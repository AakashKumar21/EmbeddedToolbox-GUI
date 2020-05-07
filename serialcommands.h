#ifndef SERIALCOMMANDS_H
#define SERIALCOMMANDS_H

namespace Inst {  // Inst for instruction
    enum PinMode{
        PinMode_In = static_cast<char>(0),
        PinMode_Out,
        PullUp_True,
        PullUp_False,
        PullDown_True,
        PullDown_False,
        PinLow,
        PinHigh,
        DigitalRead,
        AnalogRead
    };
    enum Pin{
        D8 = static_cast<char>(0),
        D9,
        D10,
        D11,
        D12,
        D13,
        D0,
        D1,
        D2,
        D3,
        D4,
        D5,
        D6,
        D7,
        A0,
        A1,
        A2,
        A3,
        A4,
        A5,
        A6
    };
}

enum class Cmd{
    PinMode,
    DigitalWrite,
    AnalogWrite,
    DigitalRead,
    AnalogRead,
    AnalogConfig
};

enum class PinMode {
    PinMode_In,
    PinMode_Out,
    PullUp_True,
    PullUp_False,
    PullDown_True,
    PullDown_False,
};

enum class Pin{
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

enum class MUX{
    A0,
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7
};

enum class AdcPrescale{
    Prescale2,
    Prescale4,
    Prescale8,
    Prescale16,
    Prescale32,
    Prescale64,
    Prescale128,
};

enum class AdcBits{
    Bits10,
    Bits8
};

enum class AdcVRef{
    Aref,
    AVcc,
    Internal1_1V
};

enum class Output{
    High,
    Low
};

class Pwm{

};

#endif // SERIALCOMMANDS_H
