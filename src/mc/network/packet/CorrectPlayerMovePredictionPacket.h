#pragma once

#include "mc/_HeaderOutputPredefine.h"
#include "mc/math/Vec3.h"

// auto generated inclusion list
#include "mc/deps/core/common/bedrock/Result.h"
#include "mc/enums/MinecraftPacketIds.h"
#include "mc/network/packet/Packet.h"

class CorrectPlayerMovePredictionPacket : public ::Packet {
public:
    Vec3   mPos;      // this+0x30
    Vec3   mPosDelta; // this+0x3C
    uint64 mTick;     // this+0x48
    bool   mOnGround; // this+0x50

    // prevent constructor by default
    CorrectPlayerMovePredictionPacket& operator=(CorrectPlayerMovePredictionPacket const&);
    CorrectPlayerMovePredictionPacket(CorrectPlayerMovePredictionPacket const&);
    CorrectPlayerMovePredictionPacket();

public:
    // NOLINTBEGIN
    // vIndex: 0, symbol: __unk_vfn_0
    virtual void __unk_vfn_0();

    // vIndex: 1, symbol: ?getId@CorrectPlayerMovePredictionPacket@@UEBA?AW4MinecraftPacketIds@@XZ
    virtual ::MinecraftPacketIds getId() const;

    // vIndex: 2, symbol:
    // ?getName@CorrectPlayerMovePredictionPacket@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
    virtual std::string getName() const;

    // vIndex: 3, symbol: ?write@CorrectPlayerMovePredictionPacket@@UEBAXAEAVBinaryStream@@@Z
    virtual void write(class BinaryStream&) const;

    // vIndex: 7, symbol:
    // ?_read@CorrectPlayerMovePredictionPacket@@EEAA?AV?$Result@XVerror_code@std@@@Bedrock@@AEAVReadOnlyBinaryStream@@@Z
    virtual class Bedrock::Result<void> _read(class ReadOnlyBinaryStream&);

    // symbol: ??1CorrectPlayerMovePredictionPacket@@UEAA@XZ
    MCVAPI ~CorrectPlayerMovePredictionPacket();

    // NOLINTEND
};
