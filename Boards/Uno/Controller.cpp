#include "Controller.h"
#include <Arduino.h>
#define DEBUG(x) Serial.println(x)

void Controller::set_pinMode(PinMode pinmode,Pin pin)
{
    pinMode(static_cast<char>(pin), 
            static_cast<char>(pinmode));
    DEBUG("PinMode: ");
    DEBUG(static_cast<int>(pin));
    DEBUG(static_cast<char>(pinmode)? "OUTPUT":"INPUT");
}

void Controller::set_digitalWrite(Pin pin, Output output)
{
    digitalWrite(static_cast<char>(pin), static_cast<char>(output));
    DEBUG("DigitalWrite: ");
    DEBUG(static_cast<int>(pin));
    DEBUG(static_cast<char>(output)? "High":"Low");
}

int Controller::action(char *bytes)
{
    switch (bytes[0]) 
    {
    case static_cast<char>(Cmd::PinMode): 
        set_pinMode(static_cast<PinMode>(bytes[1]), 
                    static_cast<Pin> (bytes[2]));
        break;
    case static_cast<char>(Cmd::DigitalWrite): 
        set_digitalWrite(static_cast<Pin>(bytes[1]), 
                        static_cast<Output> (bytes[2]));
        break;
    }
    return 0;
}

Controller::Controller(){}
