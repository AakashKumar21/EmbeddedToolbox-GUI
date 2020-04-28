#ifndef SERIALCOMMANDS_H
#define SERIALCOMMANDS_H

namespace Inst {  // Inst for instruction
    enum OP{
        PinMode_Low,
        PinMode_High,
        PullUp_True,
        PullUp_False,
        PullDown_True,
        PullDown_False
    };
    enum TARGET{
        D8 = static_cast<short int>(64),
        D9,
        D10,
        D11,
        D12,
        D13,
        D0 = static_cast<short int>(32),
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
