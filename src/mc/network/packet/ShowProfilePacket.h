#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/common/bedrock/Result.h"
#include "mc/enums/MinecraftPacketIds.h"
#include "mc/network/packet/Packet.h"

class ShowProfilePacket : public ::Packet {
public:
    std::string mPlayerXiud; // this+0x30

    // prevent constructor by default
    ShowProfilePacket& operator=(ShowProfilePacket const&);
    ShowProfilePacket(ShowProfilePacket const&);

public:
    // NOLINTBEGIN
    // vIndex: 0, symbol: __unk_vfn_0
    virtual void __unk_vfn_0();

    // vIndex: 1, symbol: ?getId@ShowProfilePacket@@UEBA?AW4MinecraftPacketIds@@XZ
    virtual ::MinecraftPacketIds getId() const;

    // vIndex: 2, symbol:
    // ?getName@ShowProfilePacket@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
    virtual std::string getName() const;

    // vIndex: 3, symbol: ?write@ShowProfilePacket@@UEBAXAEAVBinaryStream@@@Z
    virtual void write(class BinaryStream&) const;

    // vIndex: 7, symbol:
    // ?_read@ShowProfilePacket@@EEAA?AV?$Result@XVerror_code@std@@@Bedrock@@AEAVReadOnlyBinaryStream@@@Z
    virtual class Bedrock::Result<void> _read(class ReadOnlyBinaryStream&);

    // symbol: ??0ShowProfilePacket@@QEAA@XZ
    MCAPI ShowProfilePacket();

    // NOLINTEND
};
