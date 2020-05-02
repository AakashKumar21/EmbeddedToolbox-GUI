#ifndef SERIALCOMMANDS_H
#define SERIALCOMMANDS_H

namespace Inst {  // Inst for instruction
    enum OP{
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
    enum TARGET{
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
    const int TARGET[8] = {1};
}



#endif // SERIALCOMMANDS_H
