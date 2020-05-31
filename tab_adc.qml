import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import com.Serial 1.0
import "pin_ctrl_creator.js" as Create


Item{

    id:lo_adc_tab

    ColumnLayout{
        id: labels_adc
        Label{
            text: qsTr("ADC Channel: ")
        }
        Rectangle{
           height: 10
        }
        Label{
            text: qsTr("Toggle Channel: ")
        }
        Rectangle{
           height: 20
        }
        Label{
            text: qsTr("Readings: ")
        }
        height: labels_adc.height
    }
    GridLayout{
        id: lo_adc_control
        x: labels_adc.width + 50
        Component.onCompleted: Create.createAdc()
    }
}
