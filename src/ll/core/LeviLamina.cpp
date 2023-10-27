#include "ll/core/LeviLamina.h"

#include <csignal>
#include <iostream>
#include <string>

#include "ll/api/Logger.h"
#include "ll/api/ServerInfo.h"
#include "ll/api/memory/Hook.h"
#include "ll/api/service/GlobalService.h"
#include "ll/api/utils/FileHelper.h"
#include "ll/api/utils/SehTranslator.h"
#include "ll/api/utils/StringUtils.h"

#include "ll/core/Config.h"
#include "ll/core/CrashLogger.h"
#include "ll/core/Loader.h"
#include "ll/core/Version.h"
// #include "ll/core/AddonsHelper.h"
// #include "ll/core/SimpleServerLogger.h"

#include "mc/world/Minecraft.h"

#include "Psapi.h"
#include "TlHelp32.h"
#include "minwindef.h"
#include "processenv.h"
#include "windows.h"


ll::Logger                            ll::logger("LeviLamina");
std::chrono::steady_clock::time_point ll::SeverStartBeginTime;
std::chrono::steady_clock::time_point ll::SeverStartEndTime;

using namespace ll;

// Add plugins folder to path
void fixPluginsLibDir() {
    constexpr const DWORD MAX_PATH_LEN = 32767;

    auto* buffer = new (std::nothrow) wchar_t[MAX_PATH_LEN];
    if (!buffer) return;

    GetEnvironmentVariableW(L"PATH", buffer, MAX_PATH_LEN);
    std::wstring path(buffer);

    GetCurrentDirectoryW(MAX_PATH_LEN, buffer);
    std::wstring currentDir(buffer);

    delete[] buffer;
    // append plugins path to environment path
    SetEnvironmentVariableW(L"PATH", (currentDir + L"\\plugins;" + path).c_str());
}

void fixUpCWD() {
    constexpr const DWORD MAX_PATH_LEN = 32767;

    auto* buffer = new (std::nothrow) wchar_t[MAX_PATH_LEN];
    if (!buffer) return;

    GetModuleFileNameW(nullptr, buffer, MAX_PATH_LEN);
    std::wstring path(buffer);

    delete[] buffer;

    SetCurrentDirectoryW(path.substr(0, path.find_last_of(L'\\')).c_str());
}

void unzipNodeModules() {
    if (std::filesystem::exists(std::filesystem::path(TEXT(".\\plugins\\lib\\node_modules.tar")))) {
        std::error_code ec;
        // if(std::filesystem::exists(".\\plugins\\lib\\node_modules\\"))
        //     filesystem::remove_all(".\\plugins\\lib\\node_modules\\", ec);
        auto res = NewProcessSync(
            fmt::format(
                R"({} x "{}" -o".\plugins\lib\" -aoa)",
                ll::globalConfig.modules.compressor.path,
                R"(.\plugins\lib\node_modules.tar)"
            ),
            30000
        );
        if (res.first != 0) {
            logger.error("ll.unzipNodeModules.fail"_tr);
        } else {
            std::filesystem::remove(R"(.\plugins\lib\node_modules.tar)", ec);
        }
    }
}

void decompressResourcePacks() {
    if (std::filesystem::exists(std::filesystem::path(TEXT(".\\plugins\\LeviLamina\\ResourcePacks\\LeviLamina-CUI.tar"))
        )) {
        std::error_code ec;
        // if(std::filesystem::exists(".\\plugins\\lib\\node_modules\\"))
        //     filesystem::remove_all(".\\plugins\\lib\\node_modules\\", ec);
        auto res = NewProcessSync(
            fmt::format(
                R"({} x "{}" -o".\plugins\LeviLamina\ResourcePacks\" -aoa)",
                ll::globalConfig.modules.compressor.path,
                R"(.\plugins\LeviLamina\ResourcePacks\LeviLamina-CUI.tar)"
            ),
            30000
        );
        if (res.first != 0) {
            logger.error("ll.decompressResourcePacks.fail"_tr);
        } else {
            std::filesystem::remove(R"(.\plugins\LeviLamina\ResourcePacks\LeviLamina-CUI.tar)", ec);
        }
    }
}

void checkRunningBDS() {

    if (!ll::globalConfig.modules.checkRunningBDS) return;

    constexpr const DWORD MAX_PATH_LEN = 32767;
    auto*                 buffer       = new wchar_t[MAX_PATH_LEN];


    // get all processes id with name "bedrock_server.exe" or "bedrock_server_mod.exe"
    // and pid is not current process
    std::vector<DWORD> pids;
    PROCESSENTRY32     pe32;
    pe32.dwSize         = sizeof(PROCESSENTRY32);
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) { return; }
    if (Process32First(hProcessSnap, &pe32)) {
        do {
            if (pe32.th32ProcessID != GetCurrentProcessId()
                && (wcscmp(pe32.szExeFile, L"bedrock_server.exe") == 0
                    || wcscmp(pe32.szExeFile, L"bedrock_server_mod.exe") == 0)) {
                pids.push_back(pe32.th32ProcessID);
            }
        } while (Process32Next(hProcessSnap, &pe32));
    }
    CloseHandle(hProcessSnap);

    // Get current process path
    std::wstring currentPath;
    GetModuleFileNameW(nullptr, buffer, MAX_PATH_LEN);
    currentPath = buffer;

    // Get the BDS process paths
    for (auto& pid : pids) {
        // Open process handle
        auto handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_TERMINATE, false, pid);
        if (handle) {
            // Get the full path of the process
            std::wstring path;
            GetModuleFileNameExW(handle, nullptr, buffer, MAX_PATH_LEN);
            path = buffer;

            // Compare the path
            if (path == currentPath) {
                logger.error("ll.main.checkRunningBDS.detected"_tr);
                logger.error("ll.main.checkRunningBDS.tip"_tr);
                while (true) {
                    logger.error("ll.main.checkRunningBDS.ask"_tr, pid);
                    char input;
                    rewind(stdin);
                    input = static_cast<char>(getchar());
                    rewind(stdin);
                    if (input == 'n' || input == 'N') { break; }
                    if (input == 'y' || input == 'Y') {
                        TerminateProcess(handle, 1);
                        break;
                    }
                    if (input == 'e' || input == 'E') { std::terminate(); }
                }
            }
            CloseHandle(handle);
        }
    }
    delete[] buffer;
}

void printLogo() {

    logger.info(R"(                                                                      )");
    logger.info(R"(         _               _ _                    _                     )");
    logger.info(R"(        | |    _____   _(_) |    __ _ _ __ ___ (_)_ __   __ _         )");
    logger.info(R"(        | |   / _ \ \ / / | |   / _` | '_ ` _ \| | '_ \ / _` |        )");
    logger.info(R"(        | |__|  __/\ V /| | |__| (_| | | | | | | | | | | (_| |        )");
    logger.info(R"(        |_____\___| \_/ |_|_____\__,_|_| |_| |_|_|_| |_|\__,_|        )");
    logger.info(R"(                                                                      )");
    logger.info(R"(        --------   Light-Weight BDS Plugin Loader   ----------        )");
    logger.info(R"(                                                                      )");
    logger.info(R"(                                                                      )");

    logger.info("ll.notice.license"_tr, "LGPLv3");
    logger.info("ll.notice.newForum"_tr, "https://forum.litebds.com");
    logger.info("ll.notice.translateText"_tr, "https://crowdin.com/project/liteloaderbds");
    logger.info("ll.notice.sponsor.thanks"_tr);
    logger.info("");
}

void checkBetaVersion() {
    if (ll::getLoaderVersion().mPreRelease != ll::Version::PreRelease::None) {
        logger.warn("ll.main.warning.betaVersion"_tr);
        logger.warn("ll.main.warning.productionEnv"_tr);
    }
}

void checkProtocolVersion() {
    auto currentProtocol = ll::getServerProtocolVersion();
    if (TARGET_BDS_PROTOCOL_VERSION != currentProtocol) {
        logger.warn("ll.main.warning.protocolVersionNotMatch.1"_tr, TARGET_BDS_PROTOCOL_VERSION, currentProtocol);
        logger.warn("ll.main.warning.protocolVersionNotMatch.2"_tr);
    }
}

BOOL WINAPI ConsoleExitHandler(DWORD CEvent) {
    switch (CEvent) {
    case CTRL_C_EVENT:
    case CTRL_CLOSE_EVENT:
    case CTRL_SHUTDOWN_EVENT: {
        if (Global<Minecraft>) {
            Global<Minecraft>->requestServerShutdown("");
        } else {
            std::terminate();
        }
        return TRUE;
    }
    default:
        break;
    }
    return FALSE;
}

void unixSignalHandler(int signum) {
    switch (signum) {
    case SIGINT:
    case SIGTERM: {
        if (Global<Minecraft>) {
            Global<Minecraft>->requestServerShutdown("");
        } else {
            std::terminate();
        }
        break;
    }
    default:
        break;
    }
}

// extern

extern void RegisterCommands();

extern void EndScheduleSystem();

namespace bstats {
void registerBStats();
}

void leviLaminaMain() {
    // If SEH Protection is not enabled (Debug mode), restore old SE translator
    if (!ll::isDebugMode()) _set_se_translator(seh_exception::TranslateSEHtoCE);

    // Prohibit pop-up windows to facilitate automatic restart
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOALIGNMENTFAULTEXCEPT);

    // Disable Output-Sync
    std::ios::sync_with_stdio(false);

    // Init LL Logger
    Logger::setDefaultFile("logs/LeviLamina-latest.log", false);

    // Create Plugin Directory
    std::error_code ec;
    std::filesystem::create_directories("plugins", ec);

    // I18n
    auto i18n = ll::i18n::Translation::load("plugins/LeviLamina/LangPack/");

    // Load Config
    ll::LoadLLConfig();

    // Unzip packed Node Modules
    unzipNodeModules();

    // Decompress resource packs
    decompressResourcePacks();

    // Update default language
    if (i18n && ll::globalConfig.language != "system") { i18n->defaultLocaleName = ll::globalConfig.language; }

    // Check Protocol Version
    checkProtocolVersion();

    // Fix problems
    fixUpCWD();
    fixPluginsLibDir();

    // Check Running BDS(Requires Config)
    checkRunningBDS();

    // Builtin CrashLogger
    ll::CrashLogger::initCrashLogger(ll::globalConfig.modules.crashLogger.enabled);

    // Rename Window
    HWND         hwnd = GetConsoleWindow();
    std::wstring s    = ll::StringUtils::str2wstr("Bedrock Dedicated Server " + ll::getBdsVersion());
    SetWindowText(hwnd, s.c_str());

    // Register Exit Event Handler.
    SetConsoleCtrlHandler(ConsoleExitHandler, TRUE);
    signal(SIGTERM, unixSignalHandler);
    signal(SIGINT, unixSignalHandler);

    // Welcome
    printLogo();

    // DebugMode
    if (ll::globalConfig.debugMode) logger.warn("ll.main.warning.inDevMode"_tr);

    // Addon Helper
    // if (ll::globalConfig.enableAddonsHelper) {
    //     InitAddonsHelper();
    // }

    // Load plugins
    ll::LoadMain();

    // Register built-in commands
    RegisterCommands();

    // Register simple server logger
    // ll::SimpleServerLogger::registerSimpleServerLogger();

    // Register BStats
    // bstats::registerBStats();
}

using namespace ll::memory;

LL_AUTO_STATIC_HOOK(LeviLaminaMainHook, HookPriority::Normal, "main", int, int argc, char* argv[]) {

    SeverStartBeginTime = std::chrono::steady_clock::now();

    for (int i = 0; i < argc; ++i) {
        switch (do_hash(argv[i])) {
        case "--noColor"_h:
            ll::globalConfig.logger.colorLog = false;
            break;
        case "-v"_h:
        case "--version"_h:
            fmt::print("{}", ll::getBdsVersion());
            return 0;
        case "--protocolversion"_h:
            fmt::print("{}", ll::getServerProtocolVersion());
            return 0;
        default:
            break;
        }
    }
    leviLaminaMain();
    return origin(argc, argv);
}

[[maybe_unused]] BOOL WINAPI DllMain(HMODULE, DWORD, LPVOID) { return TRUE; }
