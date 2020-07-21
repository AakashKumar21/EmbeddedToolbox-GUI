import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

GroupBox{
    id: i2c_device_delegate
    property variant address
    property variant cmd_list: []
    property variant mem_list: []

    width: app.width - dpi * 16
    x: dpi*2
    height: dpi * 30
    title: "Address: " + "0x" +address.toString(16)

    ColumnLayout{
        // SIMPLE I2C DEVICE
        RowLayout{

            Label{
                text: "Send Byte \n(Decimal):"
            }
            TextField{
                id: cmd_txt_field
                maximumLength: 1
                Keys.onReleased: {
                    console.log("Ret:",text);
                }
            }

            Button{
                text: "Add to \nCommand list"
                onClicked: {
                    cmd_list.push(cmd_txt_field.text)
                    console.log("Added")
                    cmd_list_box.model = cmd_list;
                }
            }
            Button{
                text: "Remove \nLast Cmd"
                onClicked: {
                    cmd_list.pop()
                    console.log("Removed")
                    cmd_list_box.model = cmd_list;
                }
            }

            Label{
                text: "Command\nList:"
            }
            ComboBox{
                id: cmd_list_box
                model: cmd_list
            }
            Button{
                text: "Send"
                onClicked: {
                    console.log(cmd_list_box.currentText);
                }
            }
        }

        // MEMORY DEVICES
        RowLayout{
            // Write
            Label{
                text: "Mem Address\n(Decimal):"
            }
            TextField{
                id: mem_txt_field
            }

            Label{
                text: "Data Byte\n(Decimal):"
            }
            TextField{
            }

            // Read
            Label{

            }

            Text{
                text: "f"
            }

            // BUTTONS
            Button{
                text: "Read"
                onClicked: {
                    mem_list.push(mem_txt_field.text);
                    mem_list_box.model = mem_list;
                }
            }
            Button{
                text: "Add To\n Mem Ad List"
                onClicked: {
                    mem_list.push(mem_txt_field.text);
                    mem_list_box.model = mem_list;
                }
            }
            Button{
                text: "Remove \nLast Ad"
                onClicked: {
                    mem_list.pop();
                    mem_list_box.model = mem_list;
                }
            }

            Label{
                text: "Ad List"
            }

            ComboBox{
                id: mem_list_box
            }
        }
    }
}
