#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/events/TextFilteringEvent.h"
#include "mc/world/events/TextProcessingEventOrigin.h"
#include "mc/world/level/Command.h"

class ServerCommand : public ::Command {
public:
    // prevent constructor by default
    ServerCommand& operator=(ServerCommand const&) = delete;
    ServerCommand(ServerCommand const&)            = delete;
    ServerCommand()                                = delete;

public:
    // NOLINTBEGIN
    // symbol: ??1ServerCommand@@UEAA@XZ
    MCVAPI ~ServerCommand();

    // NOLINTEND

    // protected:
    // NOLINTBEGIN
    // symbol:
    // ?tryToSIFTText@ServerCommand@@IEBA_NAEBVCommandOrigin@@AEAVCommandOutput@@AEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@AEBW4TextProcessingEventOrigin@@V?$function@$$A6AXAEBV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@AEBV?$vector@W4TextFilteringEvent@Safety@@V?$allocator@W4TextFilteringEvent@Safety@@@std@@@2@@Z@5@@Z
    MCAPI bool
    tryToSIFTText(class CommandOrigin const&, class CommandOutput&, std::vector<std::string> const&, ::TextProcessingEventOrigin const&, std::function<void(std::vector<std::string> const&, std::vector<::Safety::TextFilteringEvent> const&)>)
        const;

    // NOLINTEND

protected:
    // NOLINTBEGIN
    // symbol: ?mGame@ServerCommand@@1PEAVMinecraft@@EA
    MCAPI static class Minecraft* mGame;

    // NOLINTEND

    // member accessor
public:
    // NOLINTBEGIN
    // NOLINTEND
};
