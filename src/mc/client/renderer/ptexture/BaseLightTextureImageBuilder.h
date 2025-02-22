#pragma once

#include "mc/_HeaderOutputPredefine.h"

class Dimension;

class BaseLightTextureImageBuilder {
public:
    // prevent constructor by default
    BaseLightTextureImageBuilder& operator=(BaseLightTextureImageBuilder const&);
    BaseLightTextureImageBuilder(BaseLightTextureImageBuilder const&);
    BaseLightTextureImageBuilder();

    void* vftable;

    const Dimension* mDimension; // this+0x8
};
