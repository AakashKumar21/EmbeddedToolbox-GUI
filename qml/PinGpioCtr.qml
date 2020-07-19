import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.12

ColumnLayout{
    id: pin_ctrl_grp
    property int pin_no: 0
    height: parent.height
    Layout.fillHeight: true    
    clip: true
    Layout.alignment: Qt.AlignHCenter
    Layout.preferredWidth: dpi*16

    //Pins
    Rectangle{
        height: dpi*8
        width: dpi*16
        Text {
            text: "D" + pin_no
            leftPadding: dpi*4
            font.bold: true
            font.pixelSize: dpi*4
        }
        clip: true
    }

    // PinMode
    Button {
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
//        width: dpi*14
        onCheckedChanged: {
            serial.set_digitalWrite(parseInt(parent.objectName),checked);
            if(checked) text = "High";
            else text = "Low";
        }
    }
//    Rectangle{ height: dpi * 0.2}

    //PWM
    TextField {
        objectName: 'p' + parent.objectName
        text: "1022"
        font.pixelSize: dpi*4
//        width: dpi*14
    }
    // Digital Read
    Label {
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
