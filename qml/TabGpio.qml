import Felgo 3.0
import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import com.Serial 1.0

Item{
    GroupBox{
        id: box_gpio_control
        x: 10
        y: 10
        height: dp(180)
        width: main.width - 20
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
        Item{
            id: lo_gpio_control
            x: labels_gpio.width + 50
            Component.onCompleted:{
                        var component = Qt.createComponent("pin_ctrl_grp.qml");
                        for (var i=0; i<14; i++) {
                                    var object = component.createObject(lo_gpio_control);
                                    object.x = (object.width + main.dp(20)) * i;
                                    object.objectName = i
                                }
                    }
        }
    }

}





