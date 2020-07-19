import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import com.Serial 1.0

Item{
    GroupBox{
        id: box_gpio_control
        x: dpi * 4
        y: dpi*4

        height: dpi * 50
        width: app.width - dpi * 20
        clip: true
        title: "GPIO Config"

        ColumnLayout{
            id: labels_gpio
            height: parent.height
            Layout.fillHeight: true
            Label{
                id: label_pins
                text: qsTr("Pin: ")
            }
            Label{
                id: label_pinmode
                text: qsTr("PinMode")
            }
            Label{
                id: label_output
                text: qsTr("Output")
            }
            Label{
                id: label_pwm
                text: qsTr("PWM:")
            }

            Label{
                text: qsTr("Readout")
            }
        }
        ScrollView{
            height: parent.height
            spacing: dpi * 4
            x: labels_gpio.width + dpi * 10
            y: dpi * 1

            RowLayout{
                Repeater{
                    model: 14
                    PinGpioCtr{pin_no: index}
                }
            }

//            ScrollView{
//            }
        }
    }

}





