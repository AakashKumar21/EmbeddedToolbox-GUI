import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Window 2.12
import com.Serial 1.0

ApplicationWindow {
    id:app
    property int dpi
    Component.onCompleted: {
        dpi = Screen.pixelDensity
        console.log(height)
        console.log(width)
    }

    height: dpi * 100
    width: dpi * 150

    Material.theme: Material.Light
    Material.accent: Material.Purple

    Serial{
        id: serial
        onOnNotifyDatRecv: {
            readouts_arr = serial.getReadoutsAll()
        }
        property var readouts_arr
    }

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
            TabButton {
                text: qsTr("Testing")
            }
        }
    StackLayout{
        width: parent.width
        anchors{
            top: bar.bottom
        }
        currentIndex: bar.currentIndex

        // Tab GPIO
        Item {
            Rectangle{
                width: pin_ctrl_grp.width
                height: pin_ctrl_grp.height
                color: "red"
                TabGpio{}
            }
            id: tabGpio
        }
        Item {
            id: tabAdc
            TabAdc{}

        }
        Item {
            id: tab_i2c
            TabI2C{}
        }
        Item {
            id: tab_setup
            TabSetup{}
        }
        Item{
            Testing{}
        }
    }
}
