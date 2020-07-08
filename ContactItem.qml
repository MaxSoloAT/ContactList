import QtQuick 2.0

Rectangle{
    id:_rootR
    property alias internalText: valueText
    property alias fullName: _img
    property alias ccItem: _citem

    Image {
        id: _img
        height: 80
        width: 80
        fillMode: Image.PreserveAspectFit
        source: ""
    }

    Rectangle {
        id: _citem
        anchors.left: _img.right
        width: _rootR.width-80
        height: 80

        color: "green"
        border.color: "black"
        border.width: 2
        radius: 5

        Text{
            id: valueText
            anchors.centerIn: _citem
            font{
                pointSize: _citem.width / 30
            }
            text: ""
        }
    }
}
