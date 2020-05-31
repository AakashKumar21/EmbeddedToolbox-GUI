import QtQuick 2.9
import QtQuick.Controls.Material 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import com.Serial 1.0

Item{
    id:lo_setup

    GroupBox {
        id: lo_connection
        x: 10
        y: 10
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
                model: serial.portList
                onCurrentIndexChanged: {
                       serial.port = currentIndex
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
            //Port
            Rectangle{
                width: 10
            }
            Label{
                text: qsTr("Baud Rate:")
            }
            ComboBox {
            }

            // Connect Button
            Rectangle{
                width: 10
            }
            Button{
                id: btn_connect
                text: qsTr("Connect")
                checkable: true
                checked: false
                onClicked: {
                    serial.connected = checked
                }
            }
            // Connect Button
            Rectangle{
                width: 10
            }
            Button{
                text: qsTr("Refesh")
                onClicked: {
                    serial.refresh()
                }
            }
            // Test
            Text {
                id: name
                text: qsTr("text")
            }

        }
    }   
}



/*##^##
Designer {
    D{i:0;height:600;width:600}
}
##^##*/
