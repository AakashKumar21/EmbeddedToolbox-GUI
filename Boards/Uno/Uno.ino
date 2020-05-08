#include "Controller.h"

void setup() {
  Serial.begin(115200);
}

char bytes[3] {};
int len{};
Controller Control = Controller();

void loop() {
    if(Serial.available() > 0)
    {
        bytes[len++] = Serial.read() ;
    }
    if(len == 3)
    {
        Serial.print(static_cast<int>(bytes[0]));
        Serial.print(static_cast<int>(bytes[1]));
        Serial.println(static_cast<int>(bytes[2]));
        Control.action(bytes);
        len = 0;
    }
}
