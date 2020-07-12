import Felgo 3.0
import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import com.Serial 1.0
//import "pin_ctrl_creator.js" as Create


Item{

    RowLayout{
        id: box_i2c_panel

        MyButton{
            text: "Scan"
        }
        MyLabel{
            text: "i2c Devices Found: "
        }

    }

    ListView{
        id: lo_i2c_ctrl_box
        y: box_i2c_panel.height + 10
//        Component.onCompleted: Create.createI2C(5)
    }
}
