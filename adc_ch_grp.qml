import QtQuick 2.9
import QtQuick.Controls.Material 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

ColumnLayout{
//    property string name: value

    Timer {
        interval: 1; running: false; repeat: true
        onTriggered: {
        }
    }

    //Pins
    Text {
        text: "Ch " + parent.objectName
        leftPadding: 14
    }

    // PinMode
    CheckBox {
            onCheckStateChanged: {
            }
        }

    Text {
        id: label_adc_readout
        leftPadding: 15
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
