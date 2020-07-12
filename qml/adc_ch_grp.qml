import Felgo 3.0
import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

ColumnLayout{
    height: adc_labels.height
    Layout.fillHeight: true
    Button{
        text: "A" + parent.objectName
        checkable: true
        onCheckedChanged: {
//            serial.set_pinMode(parseInt(parent.objectName),checked);
        }
    }
    AppText{
        text: "0"
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
