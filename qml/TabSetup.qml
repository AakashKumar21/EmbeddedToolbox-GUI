import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import com.Serial 1.0
import Felgo 3.0

Item{
    id:lo_setup

    GroupBox {
        id: lo_connection
        x: 10
        y: 10
        width: main.width - 20
        height: 100

        RowLayout{
            //Port
            Layout.alignment: Qt.AlignCenter
            spacing: 20
            Text{
                text: qsTr("Port:")
            }
            ComboBox {
                id: dropdownPorts
                model: serial.portList
                onCurrentIndexChanged:
                {
                    serial.port = currentIndex
                }
            }

            // Board
            Label{
                text: qsTr("Board:")
            }
            ComboBox {
            }
            //Port

            Label{
                text: qsTr("Baud Rate:")
            }
            ComboBox {
            }

            // Connect Button
            MyButton{
                text: "Connect"
                onClicked: {
                    serial.connected = 1
                }
            }
            MyButton{
                text: "Disconnect"
                onClicked: {
                    serial.connected = 0
                }
            }
            MyButton{
                text: "Refresh"
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
