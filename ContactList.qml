import QtQuick 2.0
import QtQuick.Window 2.12
import sad 1.0

ListView {
    id: _rootL

    model: ContactListModel{
        id: _cl
    }

    clip: true
    spacing: 2

    delegate: ContactItem {
        id: _cI
        property int indexOfThisDelegate: index
        internalText.text: name.toString()
        fullName.source: "file:"+ path.toString()
        width: _rootL.width
        height: 80
        color: "gray"

        MouseArea {
            anchors.fill: ccItem
            onPressAndHold: {
                _rootL.model.getIndex(indexOfThisDelegate)
                _cB.show()
            }
        }
    }

    Call {
        id: _cB
        width: 200
        height: 80
        call.onClicked: {
            _rootL.model.makeCall()
            callwindow.close()
        }
    }
}

