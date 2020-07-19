import Felgo 3.0
import QtQuick 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    property int i:0

    GroupBox{
        title: "Testing"
        x: 10
        y: 10
        height: dpi * 30
        width: dpi * 50

        ScrollView {
            y: 100
            width: 200
            height: 200
            clip: false

            RowLayout{
                Repeater{
                    model: 5
                    TestElement{}
                }
            }
        }
    }
}
