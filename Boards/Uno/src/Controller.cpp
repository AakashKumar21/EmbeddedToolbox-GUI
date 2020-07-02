#include "Controller.h"
#include <Arduino.h>
// #include <avr/io.h>

// #define DEBUG(x) Serial.println(x)
// #define Serial.write(x) 
#define DEBUG(x) 


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
    case static_cast<char>(Cmd::Sync):
        send_data();
    }
    return 0;
}

void Controller::send_data()
{
    send_digitalRead();   
}

void Controller::send_digitalRead()
{
    // Serial.write(static_cast<int>(Cmd::DigitalReadouts));
    DEBUG(static_cast<int>(Cmd::DigitalReadouts));
    DEBUG(static_cast<int>(PORTB));
    DEBUG(static_cast<int>(PORTD));

    Serial.write(static_cast<int>(Cmd::DigitalReadouts));
    Serial.write(PORTB);
    Serial.write(PORTD);
}

void Controller::run()
{
    

    if(Serial.available() > 0)
    {
        bytes[len++] = Serial.read() ;
    }
    if(len == 3)
    {
        len = 0;
        action(bytes);
    }


}

Controller::Controller(size_t i){
    interval = i;
}
