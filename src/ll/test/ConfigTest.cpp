
#include "ll/api/memory/Hook.h"
#include "ll/core/LeviLamina.h"
#include "mc/server/ServerInstance.h"

#include "ll/api/Config.h"

#include "nlohmann/json.hpp"

// #include "ll/api/schedule/Scheduler.h"
// #include "ll/api/service/GlobalService.h"
// #include "mc/world/level/BlockPos.h"
// #include "mc/world/level/Level.h"
// #include "mc/world/level/LevelChunkTag.h"
// #include "mc/world/level/storage/LevelStorage.h"
// using namespace ll::schedule;
// GameTickScheduler s;

template <class T>

class TestClass {
public:
    int version = 2;

    bool someFlag = false;
    bool eeeeFlag = true;
    struct {
        int   hello = 233;
        float trs   = 0.2f;
    } structure;
    bool        ssbbFlag = false;
    std::string str      = R"(\1hellow)";
    int         plain    = 1111;
    class MyPair {
    public:
        std::string typo          = "hellotype";
        long long   I_am_a_number = 12415276547;
    };

    std::map<std::string, MyPair> amap = {
        {"key1", {}                 },
        {"key2", {"a new thing", 42}},
        {"key3", {}                 },
    };
    std::tuple<int, bool, float>                       tuple;
    std::pair<std::string_view, MyPair>                pair;
    std::array<int, 5>                                 array;
    std::optional<std::vector<float>>                  vector     = std::vector<float>{{}, {}, {}};
    std::optional<std::vector<float>>                  nullvector = std::nullopt;
    std::multiset<std::pair<std::string_view, double>> mulset     = {{}, {}};
    enum class H {
        Aenum,
        Benum,
    } hi;
};

LL_AUTO_TYPED_INSTANCE_HOOK(
    ConfigTest,
    HookPriority::Normal,
    ServerInstance,
    &ServerInstance::startServerThread,
    void
) {
    origin();

    auto helloReflection = TestClass<int>{};

    ll::config::saveConfig(helloReflection, "plugins/Test/testconfig.json");

    ll::logger.debug("{} for load config", ll::config::loadConfig(helloReflection, "plugins/Test/testconfig.json"));
    ll::logger.debug("\n{}", ll::reflection::serialize<nlohmann::ordered_json>(helloReflection).dump(4));
}