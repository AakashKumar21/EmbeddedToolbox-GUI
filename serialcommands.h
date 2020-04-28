#ifndef SERIALCOMMANDS_H
#define SERIALCOMMANDS_H

namespace Inst {  // Inst for instruction
    enum OP{
        PinMode_In,
        PinMode_Out,
        PullUp_True,
        PullUp_False,
        PullDown_True,
        PullDown_False,
        PinLow,
        PinHigh
    };
    enum TARGET{
        D8 = static_cast<char>(32),
        D9,
        D10,
        D11,
        D12,
        D13,
        D0 = static_cast<char>(128),
        D1,
        D2,
        D3,
        D4,
        D5,
        D6,
        D7
    };
}

#endif // SERIALCOMMANDS_H
