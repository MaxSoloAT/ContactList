import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
Window {
    id: _root
    visible: true
    width: 720
    height: 720
    title: qsTr("Contact List")
    color: "gray"

    ContactList {
        anchors.leftMargin: 2
        anchors.rightMargin: 2
        anchors.fill: parent
    }
}
