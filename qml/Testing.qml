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
        Button{
            text: "Testing"
            onClicked: {
                var component = Qt.createComponent("test_element.qml");
                var object = component.createObject(lo_testing);
                object.x = (object.width + main.dp(10)) * i;
                i++;
//                list_model.append({btn_txt:"i"+i});
            }
        }

        ScrollView {
//            id: lo_testing
            y: 100
            width: 200
            height: 200
            clip: true

//            Row{
//                Repeater{
//                    model: 5
//                    Button{}
//                }
//            }
            RowLayout{
                Repeater{
                    model: 5
                    TestElement{}
                }
            }
        }

//        ScrollView{
//            height: dp(200)
//            width: dp(100)
//            y: 100
//            clip: true

//            Label {
//                text: "ABC"
//                font.pixelSize: 224
//            }
////            Rectangle{
////                id: lo_testing
////                color: "red"
////                height: dp(200)
////                width: dp(600)
////            }
//        }
    }
}
