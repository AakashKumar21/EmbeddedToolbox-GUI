import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import Felgo 3.0

Rectangle{
    color: "steelblue"
    width: 80
    height: dpi * 40
    ColumnLayout{
        id: pin_ctrl_grp
        Layout.fillHeight: true
        spacing: dpi*5
        Layout.alignment : Qt.AlignHCenter
        anchors{
            horizontalCenter: parent.horizontalCenter
        }
        //Pins
        Label {
            text: "D04"
        }
        // PinMode
        Button {
                width: dpi*10
                checkable: true
                flat: false
                text : "Output"
                checked: true
                objectName: 'p'
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
        TextInput {
            objectName: 'p' + parent.objectName
            text: "1022"
    //        contentWidth: dp(10)
            width: dpi*5
        }
        Label {
            id: label_readout
            property bool read_value
            leftPadding: 15
            text: "1"
        }
    }
}
