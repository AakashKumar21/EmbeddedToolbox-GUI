import QtQuick 2.9
import QtQuick.Controls.Material 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import com.Serial 1.0

GroupBox{
    id:lo_setup
    height: main.height - 70
    width: main.width - 20

    Serial{
        id: serial
    }

    GroupBox {
        id: groupBox
        x: 8
        y: 7
        width: parent.width - 20

        height: 100
        title: qsTr("Connection")

        RowLayout{
            //Port
            Label{
                text: qsTr("Port:")
            }
            ComboBox {
                id: dropdownPorts
                flat: false
                model: serial.portList
                onCurrentIndexChanged: {

                }
            }
            // Board
            Rectangle{
                width: 10
            }
            Label{
                text: qsTr("Board:")
            }
            ComboBox {
            }
            // Connect Button
            Rectangle{
                width: 10
            }
            Button{
                text: qsTr("Connect")
                checkable: true
                checked: false
            }
            // Refresh Button
            Rectangle{
                width: 10
            }
            Button{
                text: qsTr("Refresh")
                onClicked: {
                    serial.refresh()
                }
            }
        }
    }
}



/*##^##
Designer {
    D{i:0;height:600;width:600}
}
##^##*/
