import QtQuick 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item{
    id: i2c_device_delegate
    property variant address
    width: 400
    height: dpi * 40
    RowLayout{
        Layout.fillHeight: true
        spacing: dpi*5
        Layout.alignment : Qt.AlignHCenter
        anchors{
            horizontalCenter: parent.horizontalCenter
        }
        clip: true

        Label {text: "Address: "+address}
        TextField{
            placeholderText: "Send Bytes"
        }
        Button {}
        Label {}
    }
}
