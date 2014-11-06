TEMPLATE = lib
TARGET = Map
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.mycompany.qmlcomponents

# Input
SOURCES += \
    map_plugin.cpp \
    myitem.cpp \
    qgeocodereply_osm.cpp \
    qgeocodingmanagerengine_osm.cpp \
    qgeomapreply_osm.cpp \
    qgeoroutereply_osm.cpp \
    qgeoroutingmanagerengine_osm.cpp \
    qgeoserviceproviderplugin_osm.cpp \
    qgeotiledmappingmanagerengine_osm.cpp \
    qgeotilefetcher_osm.cpp

HEADERS += \
    map_plugin.h \
    myitem.h \
    qgeocodereply_osm.h \
    qgeocodingmanagerengine_osm.h \
    qgeomapreply_osm.h \
    qgeoroutereply_osm.h \
    qgeoroutingmanagerengine_osm.h \
    qgeoserviceproviderplugin_osm.h \
    qgeotiledmappingmanagerengine_osm.h \
    qgeotilefetcher_osm.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

