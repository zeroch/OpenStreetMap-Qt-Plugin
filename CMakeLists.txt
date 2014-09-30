project(Maps)
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
SET (TARGET Maps)
PROJECT (${TARGET})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_BINARY_DIR}
 ${QT_INCLUDE_DIR}
)

if (DEFINED ENV{QTDIR})
    set(CMAKE_PREFIX_PATH $ENV{QTDIR} ${CMAKE_PREFIX_PATH})
else ()
    message (FATAL_ERROR "ERROR: Environment variable QTDIR is not set. Please locate your Qt folder MY_QT5_DIR.")
endif ()

find_package(Qt5 REQUIRED Widgets Gui Core Quick Qml)

message(STATUS "${CMAKE_PREFIX_PATH}")
# FIND_PACKAGE (Marble REQUIRED)
set(MARBLE_DIR "" CACHE STRING "") 
MESSAGE(STATUS "Marble dir is : ${MARBLE_DIR}")
set(MARBLE_INCLUDE "${MARBLE_DIR}/include/")
MESSAGE(STATUS "Marble include is : ${MARBLE_INCLUDE}")
SET(MARBLE_LIB "${MARBLE_DIR}/lib/")
MESSAGE(STATUS "Marble lib is : ${MARBLE_LIB}")

INCLUDE_DIRECTORIES (${MARBLE_INCLUDE})

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

LINK_DIRECTORIES(${MARBLE_LIB})
SET (LIBS ${LIBS} marblewidget Qt5::Widgets Qt5::Quick Qt5::Gui Qt5::Core)
ADD_EXECUTABLE (${TARGET} main.cpp MapItem.cpp)
TARGET_LINK_LIBRARIES (${TARGET} ${LIBS})
add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       ${CMAKE_CURRENT_SOURCE_DIR}/main.qml
                       ${CMAKE_CURRENT_BINARY_DIR}
                   )

