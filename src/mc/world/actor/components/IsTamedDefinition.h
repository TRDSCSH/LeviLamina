#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/json/JsonSchemaObjectNode.h"

// auto generated forward declare list
// clang-format off
namespace JsonUtil { class EmptyClass; }
// clang-format on

struct IsTamedDefinition {
public:
    // prevent constructor by default
    IsTamedDefinition& operator=(IsTamedDefinition const&) = delete;
    IsTamedDefinition(IsTamedDefinition const&)            = delete;
    IsTamedDefinition()                                    = delete;

public:
    // NOLINTBEGIN
    // symbol: ?initialize@IsTamedDefinition@@QEBAXAEAVEntityContext@@@Z
    MCAPI void initialize(class EntityContext&) const;

    // symbol: ?uninitialize@IsTamedDefinition@@QEBAXAEAVEntityContext@@@Z
    MCAPI void uninitialize(class EntityContext&) const;

    // symbol:
    // ?buildSchema@IsTamedDefinition@@SAXAEAV?$shared_ptr@V?$JsonSchemaObjectNode@VEmptyClass@JsonUtil@@UIsTamedDefinition@@@JsonUtil@@@std@@@Z
    MCAPI static void
    buildSchema(std::shared_ptr<
                class JsonUtil::JsonSchemaObjectNode<class JsonUtil::EmptyClass, struct IsTamedDefinition>>&);

    // NOLINTEND
};
