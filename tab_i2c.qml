import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import com.Serial 1.0
import "pin_ctrl_creator.js" as Create


Item{

    RowLayout{
        id: box_i2c_panel

        Button{
            text: "Scan"
        }
        Label{
            text: "i2c Devices Found: "
        }

    }

    ListView{
        id: lo_i2c_ctrl_box
        y: box_i2c_panel.height + 10
        Component.onCompleted: Create.createI2C(5)
    }
}
