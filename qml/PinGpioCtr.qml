import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.12

ColumnLayout{
    id: pin_ctrl_grp
    property int pin_no
    height: parent.height
    Layout.fillHeight: true    
    clip: true
    Layout.alignment: Qt.AlignHCenter
    Layout.preferredWidth: dpi*16

    Component.onCompleted: {
        console.log("Pin:", pin_no)
    }

    //Pins
    Rectangle{
        height: dpi*6
        width: dpi*14
        Text {
            text: "D" + pin_no
            font.bold: true
            font.pixelSize: dpi*4
        }
        clip: true
    }

    // PinMode
    Button {
        checkable: true
        flat: false
        width: dpi*15
        text : "Output"
        checked: true
        objectName: 'p' + pin_no
        onCheckedChanged: {
            serial.set_pinMode(pin_no,checked);
            if(checked) text = "Output";
            else text = "Input";
        }
    }

    //Output
    Button {
        objectName: 'o' + pin_no
        text: "Low"
        checkable: true
        flat: false
        width: dpi*14
        onCheckedChanged: {
            serial.set_digitalWrite(pin_no,checked);
            if(checked) text = "High";
            else text = "Low";
        }
    }

    //PWM
    TextField {
        objectName: 'p' + pin_no
        text: "0"
        font.pixelSize: dpi*4
        width: dpi*14
    }

    // Digital Read
    Label {
        id: label_readout
        leftPadding: 15
        text: app.readouts_arr[pin_no]
        onTextChanged: {
            console.log(text);
        }
        font.pixelSize: dpi*4
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
