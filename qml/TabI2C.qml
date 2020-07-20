import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import com.Serial 1.0

Item{
    GroupBox{
        id: i2c_box_basic_ctrl
        x: dpi * 4
        y: dpi * 4
        height: dpi * 12
        width: app.width - dpi * 8

        RowLayout{
            id: box_i2c_panel

            Button{
                text: "Scan"
                onClicked: {
                    var tmp_list = device_list;
                    tmp_list.pop();
                    device_list = tmp_list;
                }
            }
            Label{
                text: "Found: "
            }

        }
    }

    // I2C DEVICES List
    //SINGLE DEVICE
    property int address
    Component{
        id: i2c_device_delegate
        RowLayout {
            spacing: dpi*5
            Text{
                text: "Address:" + address
            }
            TextField{
                placeholderText: "Send Bytes"
            }
            TextField{
                placeholderText: "Single Byte in Hex"
            }
            ScrollView{

            }
        }
    }

    // DEVICE LIST
    GroupBox{
        x: dpi * 4
        anchors.top: i2c_box_basic_ctrl.bottom
        anchors.topMargin: dpi * 4
        height: dpi * 30
        width: app.width - dpi * 8
        title: "I2C Devices"

        ScrollView{
            height: parent.height
            width: parent.width
            clip: true
            ColumnLayout{
                spacing: dpi*10
                Repeater{
                    model: i2c_ad_list
                    delegate: I2cDevice{address: i2c_ad_list[index]}
                }
            }
        }
    }
}
