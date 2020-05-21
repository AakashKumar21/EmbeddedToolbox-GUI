import QtQuick 2.7
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: main
    height: 720
    width: 1024

    visible: true

    TabBar {
        id: bar
        width: parent.width

        TabButton {
            text: qsTr("GPIO")
        }
        TabButton {
            text: qsTr("ADC")
        }
        TabButton {
            text: qsTr("i2c")
        }
        TabButton {
            text: qsTr("Setup")
        }
    }

    StackLayout {
        width: parent.width
        anchors{
            top: bar.bottom
        }
        currentIndex: bar.currentIndex

        // Tab GPIO
        Item {
            id: tabGpio
            Loader{
                x: 10
                y: 10
                source: "qrc:/tab_gpio.qml"
            }
        }
        Item {
            id: discoverTab
            Loader{
                x: 10
                y: 10
//                source: "qrc:/tab_setup.qml"
            }
        }
        Item {
            id: name
        }
        Item {
            id: something
            Loader{
                x: 10
                y: 10
                source: "qrc:/tab_setup.qml"
            }
        }
    }
}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}
}
##^##*/
