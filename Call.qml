import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

import sad 1.0
Window {
    id: _root
    property alias callwindow: _root
    property alias call: _call
    title: "Call"
    Rectangle {
        anchors.fill: parent
        color: "lightGrey"

       Rectangle {
            id: _callB
            width: _root.width/2
            height: _root.height
            color: "green"
            radius: 35
            Text {
                id: _callT
                anchors.centerIn: _callB
                text: qsTr("Call")
                font{
                    pointSize: _root.width / 20
                }
            }
            MouseArea{
            id: _call
            anchors.fill: parent
            }
        }

       Rectangle {
            id: _backB
            width: _root.width/2
            height: _root.height
            color: "red"
            radius: 35
            anchors.left: _callB.right
            Text {
                id: _backT
                anchors.centerIn: _backB
                text: qsTr("Back")
                font{
                    pointSize: _root.width / 20
                }
            }
            MouseArea{
            id: _back
            anchors.fill: parent
            onClicked: _root.close()
            }
        }
    }
}
