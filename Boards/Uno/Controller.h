#include "serialcommands.h"

// Trying Singleton class implementation
class Controller
{
    public:
    int action(char *);
    Controller();

    private:
    
    // Setters
    void set_pinMode(PinMode pinmode,Pin pin);
    void set_digitalWrite(Pin pin, Output output) ;
    void set_analogWrite(Pin pin, int duty) ;
    void set_digitalRead(Pin pin);
    void set_AnalogRead(MUX pin);
    void set_AnalogConfig(AdcPrescale divider, AdcVRef ref, AdcBits accuracy) ;
};