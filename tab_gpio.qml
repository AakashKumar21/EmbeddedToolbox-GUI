import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import com.Serial 1.0
import "pin_ctrl_creator.js" as Create


Item{

    GroupBox{
        id: box_gpio_control
        height: 210
        width: main.width - 40

        ColumnLayout{
            id: labels_gpio
            Label{
                id: label_pins
                text: qsTr("Pin: ")
            }
            Rectangle{
               height: 10
            }
            Label{
                id: label_pinmode
                text: qsTr("PinMode")
            }
            Rectangle{
               height: 20
            }
            Label{
                id: label_output
                text: qsTr("Output")
            }
            Rectangle{
               height: 20
            }
            Label{
                text: qsTr("Readout")
            }
        }
        Item{
            id: lo_control
            x: labels_gpio.width + 50
            Component.onCompleted: Create.createObjects()
        }
    }

}




