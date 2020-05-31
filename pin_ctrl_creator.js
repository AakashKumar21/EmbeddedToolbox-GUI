var component;
var object;

function createObjects(pos_x, pos_y) {
    component = Qt.createComponent("pin_ctrl_grp.qml");
    for (var i=0; i<14; i++) {
                object = component.createObject(lo_control);
                object.x = (object.width + 10) * i;
                object.objectName = i
            }

        if (object === null) {
            // Error Handling
            console.log("Error creating object");
        }
}

function createAdc(pos_x, pos_y) {
    component = Qt.createComponent("adc_ch_grp.qml");
    for (var i=0; i<7; i++) {
                object = component.createObject(lo_adc_control);
                object.x = (object.width + 10) * i;
                object.objectName = i
            }

        if (object === null) {
            // Error Handling
            console.log("Error creating object");
        }
}

function createI2C(number) {
    component = Qt.createComponent("i2c_control_box.qml");
    for (var i=0; i<number; i++) {
                object = component.createObject(lo_i2c_ctrl_box);
                object.y = (object.height + 10) * i;
                object.objectName = i
            }

        if (object === null) {
            // Error Handling
            console.log("Error creating object");
        }
}

