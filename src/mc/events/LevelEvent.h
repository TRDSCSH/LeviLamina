#pragma once

#include "mc/_HeaderOutputPredefine.h"

enum class LevelEvent : short {
    Undefined                    = 0x0,
    SoundClick                   = 0x3E8,
    SoundClickFail               = 0x3E9,
    SoundLaunch                  = 0x3EA,
    SoundOpenDoor                = 0x3EB,
    SoundFizz                    = 0x3EC,
    SoundFuse                    = 0x3ED,
    SoundPlayRecording           = 0x3EE,
    SoundGhastWarning            = 0x3EF,
    SoundGhastFireball           = 0x3F0,
    SoundBlazeFireball           = 0x3F1,
    SoundZombieWoodenDoor        = 0x3F2,
    SoundZombieDoorCrash         = 0x3F4,
    SoundZombieInfected          = 0x3F8,
    SoundZombieConverted         = 0x3F9,
    SoundEndermanTeleport        = 0x3FA,
    SoundAnvilBroken             = 0x3FC,
    SoundAnvilUsed               = 0x3FD,
    SoundAnvilLand               = 0x3FE,
    SoundInfinityArrowPickup     = 0x406,
    SoundTeleportEnderPearl      = 0x408,
    SoundAddItem                 = 0x410,
    SoundItemFrameBreak          = 0x411,
    SoundItemFramePlace          = 0x412,
    SoundItemFrameRemoveItem     = 0x413,
    SoundItemFrameRotateItem     = 0x414,
    SoundExperienceOrbPickup     = 0x41B,
    SoundTotemUsed               = 0x41C,
    SoundArmorStandBreak         = 0x424,
    SoundArmorStandHit           = 0x425,
    SoundArmorStandLand          = 0x426,
    SoundArmorStandPlace         = 0x427,
    SoundPointedDripstoneLand    = 0x428,
    SoundDyeUsed                 = 0x429,
    SoundInkSacUsed              = 0x42A,
    QueueCustomMusic             = 0x76C,
    PlayCustomMusic              = 0x76D,
    StopCustomMusic              = 0x76E,
    SetMusicVolume               = 0x76F,
    ParticlesShoot               = 0x7D0,
    ParticlesDestroyBlock        = 0x7D1,
    ParticlesPotionSplash        = 0x7D2,
    ParticlesEyeOfEnderDeath     = 0x7D3,
    ParticlesMobBlockSpawn       = 0x7D4,
    ParticleCropGrowth           = 0x7D5,
    ParticleSoundGuardianGhost   = 0x7D6,
    ParticleDeathSmoke           = 0x7D7,
    ParticleDenyBlock            = 0x7D8,
    ParticleGenericSpawn         = 0x7D9,
    ParticlesDragonEgg           = 0x7DA,
    ParticlesCropEaten           = 0x7DB,
    ParticlesCrit                = 0x7DC,
    ParticlesTeleport            = 0x7DD,
    ParticlesCrackBlock          = 0x7DE,
    ParticlesBubble              = 0x7DF,
    ParticlesEvaporate           = 0x7E0,
    ParticlesDestroyArmorStand   = 0x7E1,
    ParticlesBreakingEgg         = 0x7E2,
    ParticleDestroyEgg           = 0x7E3,
    ParticlesEvaporateWater      = 0x7E4,
    ParticlesDestroyBlockNoSound = 0x7E5,
    ParticlesKnockbackRoar       = 0x7E6,
    ParticlesTeleportTrail       = 0x7E7,
    ParticlesPointCloud          = 0x7E8,
    ParticlesExplosion           = 0x7E9,
    ParticlesBlockExplosion      = 0x7EA,
    ParticlesVibrationSignal     = 0x7EB,
    ParticlesDripstoneDrip       = 0x7EC,
    ParticlesFizzEffect          = 0x7ED,
    WaxOn                        = 0x7EE,
    WaxOff                       = 0x7EF,
    Scrape                       = 0x7F0,
    ParticlesElectricSpark       = 0x7F1,
    ParticleTurtleEgg            = 0x7F2,
    ParticlesSculkShriek         = 0x7F3,
    SculkCatalystBloom           = 0x7F4,
    SculkCharge                  = 0x7F5,
    SculkChargePop               = 0x7F6,
    SonicExplosion               = 0x7F7,
    StartRaining                 = 0xBB9,
    StartThunderstorm            = 0xBBA,
    StopRaining                  = 0xBBB,
    StopThunderstorm             = 0xBBC,
    GlobalPause                  = 0xBBD,
    SimTimeStep                  = 0xBBE,
    SimTimeScale                 = 0xBBF,
    ActivateBlock                = 0xDAC,
    CauldronExplode              = 0xDAD,
    CauldronDyeArmor             = 0xDAE,
    CauldronCleanArmor           = 0xDAF,
    CauldronFillPotion           = 0xDB0,
    CauldronTakePotion           = 0xDB1,
    CauldronFillWater            = 0xDB2,
    CauldronTakeWater            = 0xDB3,
    CauldronAddDye               = 0xDB4,
    CauldronCleanBanner          = 0xDB5,
    CauldronFlush                = 0xDB6,
    AgentSpawnEffect             = 0xDB7,
    CauldronFillLava             = 0xDB8,
    CauldronTakeLava             = 0xDB9,
    CauldronFillPowderSnow       = 0xDBA,
    CauldronTakePowderSnow       = 0xDBB,
    StartBlockCracking           = 0xE10,
    StopBlockCracking            = 0xE11,
    UpdateBlockCracking          = 0xE12,
    AllPlayersSleeping           = 0x2648,
    SleepingPlayers              = 0x2649,
    JumpPrevented                = 0x2652,
    ParticleLegacyEvent          = 0x4000,
};
