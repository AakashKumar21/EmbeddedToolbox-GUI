import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import Felgo 3.0

Rectangle{
    color: "steelblue"
    width: 80
    height: dpi * 40
    ColumnLayout{
        id: pin_ctrl_grp
        Layout.fillHeight: true
        spacing: dpi*5
        Layout.alignment : Qt.AlignHCenter
        anchors{
            horizontalCenter: parent.horizontalCenter
        }

        Label {text: "GG"}
        Button {}
        Button {}
        TextInput{}
        Label {}
    }
}
