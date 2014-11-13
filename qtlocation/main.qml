import QtQuick 2.2
import QtQuick.Window 2.1
import QtLocation 5.3
import QtPositioning 5.3

Window {
    visible: true
    width: 360
    height: 360

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    Plugin {
        id: osm_plug
        preferred: ["osm"]
    }
    Map {
        id: map
        plugin: osm_plug
        Component.onCompleted:{
            console.log("Hello map qml")
            console.log(map.plugin.name)
        }
        anchors.fill: parent
        zoomLevel: (maximumZoomLevel - minimumZoomLevel)/2
        center {
            latitude: -27.5796
            longitude: 153.1003
        }
        gesture.enabled: true
    }
}
