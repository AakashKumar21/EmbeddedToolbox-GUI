import Felgo 3.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GroupBox{
    RowLayout {
        Text {
            text: qsTr("Address:")
        }
        Rectangle{
            width: 20
        }
        AppButton{
            text: qsTr("Connect")
        }
        AppButton{
            text: qsTr("Disconnect")
        }
        Rectangle{
            width: 20
        }
        AppTextInput{
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
