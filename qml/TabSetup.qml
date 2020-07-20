import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import com.Serial 1.0

Item{
    id:lo_setup

    // CONNNECTION CONFIG
    GroupBox {
        id: lo_connection
        x: 10
        y: 10
        width: app.width - 20
        height: 100
        title: "Connection Config"

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

    // APPEARANCE

    GroupBox{
        id: lo_appear
        x: 10
        width: app.width - 20
        height: 100
        anchors.top : lo_connection.bottom
        anchors.topMargin: dpi*4
        title: "Appearance Config"

        RowLayout{
            // Style
            Text {
                text: "Style"
            }
            ComboBox{
                model: ["Default", "Material"]
                onCurrentIndexChanged: {
                }
            }

            // Accent
            Text {
                text: "Accent"
            }
            ComboBox{
                model: ["Red","Orange","Green","Blue","Purple"]
                property variant accents: [Material.Red, Material.Orange,Material.Green,Material.Purple]
                onCurrentIndexChanged: {
                    app.Material.accent = accents[currentIndex]
                }
            }

            // Theme
            Text {
                text: "Theme"
            }
            ComboBox{
                model: ["Light", "Dark"]
                onCurrentIndexChanged:{
                    app.Material.Theme = Material.Light
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
