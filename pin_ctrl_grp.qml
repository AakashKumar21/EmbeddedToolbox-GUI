import QtQuick 2.9
import QtQuick.Controls.Material 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

ColumnLayout{
//    property string name: value

    Timer {
        interval: 50; running: false; repeat: true
        onTriggered: {
            label_readout.text = serial.getReadouts(parseInt(parent.objectName))
            label_readout.read_value = parseInt(serial.getReadouts(parseInt(parent.objectName)))
            label_readout.color = label_readout.read_value ? Material.color(Material.Red) : Material.color(Material.Blue)
//            label_readout.text = label_readout.read_value ? "High" : "Low"
        }
    }

    //Pins
    Text {
        text: "D" + parent.objectName
        leftPadding: 14
    }

    // PinMode
    CheckBox {
            objectName: 'p' + parent.objectName
            onCheckStateChanged: {
                serial.set_pinMode(parseInt(parent.objectName),checked);
            }
        }

    //Output
    CheckBox {
            objectName: 'o' + parent.objectName
            onCheckStateChanged: {
                serial.set_digitalWrite(parseInt(parent.objectName),checked);
            }
        }
    Text {
        id: label_readout
        property bool read_value
        leftPadding: 15
//        property bool values: serial.test_val
//        onTextChanged:{
//            serial.test_val = parseInt(parent.objectName)
//            text = serial.test_val
//        }
        text: serial.readouts_arr[parseInt(parent.objectName)]

//        text: serial.getReadouts(parseInt(parent.objectName))
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
