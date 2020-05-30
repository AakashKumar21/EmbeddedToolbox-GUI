import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import com.Serial 1.0
import "object_creator.js" as Create


GroupBox{

    id:lo_control_box
    height: main.height - 70
    width: main.width - 20
//    property string pin_readouts: serial.getReadoutsAll()




    ColumnLayout{
        id: lo_labels
        Rectangle{
           height: 5
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
    GroupBox{
        id: lo_control
        width: main.width - lo_control_box.width - 20
        height: lo_labels.height
        x: lo_labels.width + 50
        y: 0
        Component.onCompleted: Create.createObjects()
    }
}




