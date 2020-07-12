import Felgo 3.0
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import com.Serial 1.0

App {
    id:main
    // You get free licenseKeys from https://felgo.com/licenseKey
    // With a licenseKey you can:
    //  * Publish your games & apps for the app stores
    //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
    //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
    //licenseKey: "<generate one from https://felgo.com/licenseKey>"

//    dpScale: 0.6

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
        }
    StackLayout{
        width: parent.width
        anchors{
            top: bar.bottom
        }
        currentIndex: bar.currentIndex

        // Tab GPIO
        Item {
            id: tabGpio
            TabGpio{}
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
    }
}
