#ifndef SERIALCOMMANDS_H
#define SERIALCOMMANDS_H

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

enum Cmd{
    PinMode,
    DigitalWrite,
    AnalogWrite,
    DigitalRead,
    AnalogRead,
    AnalogConfig,
    Sync,
    DigitalReadouts
};

enum PinMode {
    PinMode_In = INPUT,
    PinMode_Out = OUTPUT,
    PullUp_True = INPUT_PULLUP,
//    PullUp_False,
//    PullDown_True,
//    PullDown_False,
};

enum Output{
    High = HIGH,
    Low = LOW
};

enum Pin{
    D0,
    D1,
    D2,
    D3,
    D4,
    D6,
    D7,
    D8,
    D9,
    D10,
    D11,
    D12,
    D13
};

enum MUX{
    A0,
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7
};

enum AdcPrescale{
    Prescale2,
    Prescale4,
    Prescale8,
    Prescale16,
    Prescale32,
    Prescale64,
    Prescale128,
};

enum AdcBits{
    Bits10,
    Bits8
};

enum AdcVRef{
    Aref,
    AVcc,
    Internal1_1V
};

class Pwm{

};

#endif // SERIALCOMMANDS_H
