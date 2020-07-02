#include "serialcommands.h"
#include <Arduino.h>

// Trying Singleton class implementation
class Controller
{
    public:
    
    Controller(size_t);
    void send_data();
    void run();

    private:
    
    void set_pinMode(PinMode pinmode,Pin pin);
    void set_digitalWrite(Pin pin, Output output) ;
    void set_analogWrite(Pin pin, int duty);
    void set_PwmFrequency(int f);
 
    void set_digitalRead(Pin pin);
    void set_AnalogRead(MUX pin);

    bool i2c_connect(byte address);
    void i2c_disconnect();
    void i2c_send(byte address, byte data);

    void send_digitalRead();
    void send_analogRead();
    void send_i2cDevices();

    int action(char *);

    char bytes[3] {};
    int len{};
    size_t interval;

};