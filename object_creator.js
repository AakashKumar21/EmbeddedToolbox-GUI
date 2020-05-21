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
