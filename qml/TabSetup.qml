import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import com.Serial 1.0

Item{
    id:lo_setup

    GroupBox {
        id: lo_connection
        x: 10
        y: 10
        width: app.width - 20
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
                id: dropdownBoards
                property int board_id
                property variant board_names: ["Arduino", "STM32_BP"]
                model: board_names
                onCurrentIndexChanged: {
                    board_id = currentIndex;
                }
            }
            //Port

            Label{
                text: qsTr("Baud Rate:")
            }
            ComboBox {
            }

            // Connect Button            
            Button{
                text: "Connect"
                onClicked: {
                    serial.connected = checked;
                }
                checkable: true;
            }
            Button{
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
