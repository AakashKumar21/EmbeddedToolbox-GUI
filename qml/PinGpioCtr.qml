import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import Felgo 3.0

ColumnLayout{
    id: pin_ctrl_grp
    property int pin_no: 0
    height: parent.height
    spacing: dp(10)
    Layout.fillHeight: true
    clip: true

    //Pins
    MyLabel {
        text: "D" + pin_no
    }

    // PinMode
    Button {
        width: dp(30)
        checkable: true
        flat: false
        text : "Output"
        checked: true
        objectName: 'p' + pin_no
        onCheckedChanged: {
            serial.set_pinMode(parseInt(parent.objectName),checked);
            if(checked) text = "Output";
            else text = "Input";
        }
    }

    //Output
    Button {
        objectName: 'o' + pin_no
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
        width: dp(20)
        placeholderText: "PWM"
    }
    // Digital Read
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
