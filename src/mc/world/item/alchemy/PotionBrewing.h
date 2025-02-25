#pragma once

#include "mc/_HeaderOutputPredefine.h"

class PotionBrewing {
public:
    // PotionBrewing inner types declare
    // clang-format off
    class Ingredient;
    template<typename T0> class Mix;
    // clang-format on

    // PotionBrewing inner types define
    class Ingredient {
    public:
        // prevent constructor by default
        Ingredient& operator=(Ingredient const&);
        Ingredient(Ingredient const&);
        Ingredient();

    public:
        // NOLINTBEGIN
        // symbol: ??0Ingredient@PotionBrewing@@QEAA@AEBVItemInstance@@@Z
        MCAPI explicit Ingredient(class ItemInstance const&);

        // symbol: ?equals@Ingredient@PotionBrewing@@QEBA_NAEBVItemDescriptor@@@Z
        MCAPI bool equals(class ItemDescriptor const&) const;

        // symbol: ?getData@Ingredient@PotionBrewing@@QEBAHXZ
        MCAPI int getData() const;

        // symbol: ?getItemId@Ingredient@PotionBrewing@@QEBAHXZ
        MCAPI int getItemId() const;

        // NOLINTEND
    };

    template <typename T0>
    class Mix {
    public:
        // prevent constructor by default
        Mix& operator=(Mix const&);
        Mix(Mix const&);
        Mix();
    };

public:
    // prevent constructor by default
    PotionBrewing& operator=(PotionBrewing const&);
    PotionBrewing(PotionBrewing const&);
    PotionBrewing();

public:
    // NOLINTBEGIN
    // symbol: ?addContainerRecipe@PotionBrewing@@SAXAEBVItem@@AEBVIngredient@1@0@Z
    MCAPI static void addContainerRecipe(class Item const&, class PotionBrewing::Ingredient const&, class Item const&);

    // symbol: ?addPotionMix@PotionBrewing@@SAXAEBVItemDescriptor@@AEBVIngredient@1@0@Z
    MCAPI static void
    addPotionMix(class ItemDescriptor const&, class PotionBrewing::Ingredient const&, class ItemDescriptor const&);

    // symbol: ?getFuelValue@PotionBrewing@@SAHAEBVItemDescriptor@@@Z
    MCAPI static int getFuelValue(class ItemDescriptor const&);

    // symbol: ?hasMix@PotionBrewing@@SA_NAEBVItemInstance@@AEBVItemDescriptor@@@Z
    MCAPI static bool hasMix(class ItemInstance const&, class ItemDescriptor const&);

    // symbol: ?initPotionBrewing@PotionBrewing@@SAXXZ
    MCAPI static void initPotionBrewing();

    // symbol: ?isFuel@PotionBrewing@@SA_NAEBVItemDescriptor@@@Z
    MCAPI static bool isFuel(class ItemDescriptor const&);

    // symbol: ?isIngredient@PotionBrewing@@SA_NAEBVItemDescriptor@@@Z
    MCAPI static bool isIngredient(class ItemDescriptor const&);

    // symbol: ?isPotionRecipeInput@PotionBrewing@@SA_NAEBVItemDescriptor@@@Z
    MCAPI static bool isPotionRecipeInput(class ItemDescriptor const&);

    // symbol: ?mix@PotionBrewing@@SA?AVItemInstance@@AEBVItemDescriptor@@AEBV2@@Z
    MCAPI static class ItemInstance mix(class ItemDescriptor const&, class ItemInstance const&);

    // symbol: ?shutdown@PotionBrewing@@SAXXZ
    MCAPI static void shutdown();

    // NOLINTEND

    // private:
    // NOLINTBEGIN
    // symbol: ?addChemistryMix@PotionBrewing@@CAXAEBVItemInstance@@AEBVIngredient@1@0@Z
    MCAPI static void
    addChemistryMix(class ItemInstance const&, class PotionBrewing::Ingredient const&, class ItemInstance const&);

    // symbol: ?getChemistryMix@PotionBrewing@@CA?AVItemInstance@@AEBVItemDescriptor@@0@Z
    MCAPI static class ItemInstance getChemistryMix(class ItemDescriptor const&, class ItemDescriptor const&);

    // NOLINTEND

private:
    // NOLINTBEGIN
    // symbol:
    // ?mChemistryMixes@PotionBrewing@@0V?$vector@V?$Mix@VItemInstance@@@PotionBrewing@@V?$allocator@V?$Mix@VItemInstance@@@PotionBrewing@@@std@@@std@@A
    MCAPI static std::vector<class PotionBrewing::Mix<class ItemInstance>> mChemistryMixes;

    // symbol:
    // ?mContainerMixes@PotionBrewing@@0V?$vector@V?$Mix@AEBVItem@@@PotionBrewing@@V?$allocator@V?$Mix@AEBVItem@@@PotionBrewing@@@std@@@std@@A
    MCAPI static std::vector<class PotionBrewing::Mix<class Item const&>> mContainerMixes;

    // symbol: ?mIsInitialized@PotionBrewing@@0_NA
    MCAPI static bool mIsInitialized;

    // symbol:
    // ?mPotionMixes@PotionBrewing@@0V?$vector@V?$Mix@VItemDescriptor@@@PotionBrewing@@V?$allocator@V?$Mix@VItemDescriptor@@@PotionBrewing@@@std@@@std@@A
    MCAPI static std::vector<class PotionBrewing::Mix<class ItemDescriptor>> mPotionMixes;

    // symbol:
    // ?mValidContainers@PotionBrewing@@0V?$vector@VIngredient@PotionBrewing@@V?$allocator@VIngredient@PotionBrewing@@@std@@@std@@A
    MCAPI static std::vector<class PotionBrewing::Ingredient> mValidContainers;

    // symbol:
    // ?mValidIngredients@PotionBrewing@@0V?$unordered_set@VIngredient@PotionBrewing@@U?$hash@VIngredient@PotionBrewing@@@std@@U?$equal_to@VIngredient@PotionBrewing@@@4@V?$allocator@VIngredient@PotionBrewing@@@4@@std@@A
    MCAPI static std::unordered_set<class PotionBrewing::Ingredient> mValidIngredients;

    // symbol:
    // ?mValidRecipeInputs@PotionBrewing@@0V?$unordered_set@VIngredient@PotionBrewing@@U?$hash@VIngredient@PotionBrewing@@@std@@U?$equal_to@VIngredient@PotionBrewing@@@4@V?$allocator@VIngredient@PotionBrewing@@@4@@std@@A
    MCAPI static std::unordered_set<class PotionBrewing::Ingredient> mValidRecipeInputs;

    // NOLINTEND

    // member accessor
public:
    // NOLINTBEGIN
    auto& $mChemistryMixes() { return mChemistryMixes; }

    auto& $mContainerMixes() { return mContainerMixes; }

    auto& $mIsInitialized() { return mIsInitialized; }

    auto& $mPotionMixes() { return mPotionMixes; }

    auto& $mValidContainers() { return mValidContainers; }

    auto& $mValidIngredients() { return mValidIngredients; }

    auto& $mValidRecipeInputs() { return mValidRecipeInputs; }

    // NOLINTEND
};
