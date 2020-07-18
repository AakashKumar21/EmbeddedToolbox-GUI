import Felgo 3.0
import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import com.Serial 1.0

Item{
    GroupBox{
        id: box_gpio_control
        x: dp(4)
        y: dp(4)
        height: dp(180)
        width: main.width - 20
        clip: true
        title: "GPIO Config"

        ColumnLayout{
            id: labels_gpio
            height: parent.height
            Layout.fillHeight: true
            MyLabel{
                id: label_pins
                text: qsTr("Pin: ")
            }
            MyLabel{
                id: label_pinmode
                text: qsTr("PinMode")
            }
            MyLabel{
                id: label_output
                text: qsTr("Output")
            }
            MyLabel{
                id: label_pwm
                text: qsTr("PWM:")
            }

            MyLabel{
                text: qsTr("Readout")
            }
        }
        RowLayout{
            height: parent.height
            spacing: dp(4)
            x: labels_gpio.width + dp(10)
            y: dp(1)
            Repeater{
                model: 14
                PinGpioCtr{pin_no: index}
            }
        }
    }

}





