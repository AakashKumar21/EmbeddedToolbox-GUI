import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
GroupBox{
    RowLayout {
        Text {
            text: qsTr("Address:")
        }
        Rectangle{
            width: 20
        }
        Button{
            text: qsTr("Connect")
        }
        Button{
            text: qsTr("Disconnect")
        }
        Rectangle{
            width: 20
        }
        TextInput{
            text: qsTr("Enter a byte in Hex")
            onAccepted: text = ""
            onFocusChanged: {
                if(focus) text = ""
            }
            Keys.onReturnPressed: {
                console.log(text)
                text = ''
            }

            width: 20
        }
    }
}
