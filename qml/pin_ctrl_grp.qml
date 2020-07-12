import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import Felgo 3.0

ColumnLayout{
    id: pin_ctrl_grp
    height: labels_gpio.height
    Layout.fillHeight: true
    //Pins
    MyLabel {
        text: "D" + parent.objectName
    }
    // PinMode
    Button {
            width: dp(30)
            checkable: true
            text : "Output"
            checked: true
            objectName: 'p' + parent.objectName
            onCheckedChanged: {
                serial.set_pinMode(parseInt(parent.objectName),checked);
                if(checked) text = "Output";
                else text = "Input";
            }
        }

    //Output
    Button {
            objectName: 'o' + parent.objectName
            text: "Low"
            checkable: true
            onCheckedChanged: {
                serial.set_digitalWrite(parseInt(parent.objectName),checked);
                if(checked) text = "High";
                else text = "Low";
            }
        }
    //PWM
    AppTextInput {
        objectName: 'p' + parent.objectName
        text: "1022"
//        contentWidth: dp(10)
        width: dp(20)
        placeholderText: "PWM"
    }
    MyLabel {
        id: label_readout
        property bool read_value
        leftPadding: 15
        text: serial.readouts_arr[parseInt(parent.objectName)]
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
