import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import com.Serial 1.0


Item{
    id:lo_adc_tab

    GroupBox
    {
        x: 10
        y: 10
        height: dpi * 180
        width: app.width - 20

        ColumnLayout{
            id: adc_labels
            height: parent.height
            Layout.fillWidth: true
            Label{
                text: "ADC Channels"
            }
            Label{
                text: "Readings"
            }
        }
        Item {
            x: adc_labels.width + 50
            id: lo_adc_control
            Component.onCompleted:{
                var component = Qt.createComponent("adc_ch_grp.qml");
                for (var i=0; i<7; i++) {
                    var object = component.createObject(lo_adc_control);
                    object.x = (object.width + dpi*5) * i;
                    object.objectName = i
                    }
                }
        }
    }
}
