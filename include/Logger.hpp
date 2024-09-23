#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <mutex>
#include "common.hpp"
#include "type.hpp"
#include "LogData.hpp"
#include "generalType.hpp"  

namespace loging {

    class Logger {
    public:
        static auto getLogger() -> Logger &;

        auto setLogFile(const fileSystem::Path &logFilePath) -> void;
        auto logUserAction(const String &message) -> void;
        auto logInfo(const String &message) -> void;
        auto logWarning(const String &message) -> void;
        auto logError(const String &message) -> void;
        auto logDebug(const String &message) -> void;

    private:
        Logger();
        ~Logger() = default;

        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;

        auto leaveLog(LogLevel level, const String &message) -> void;
        auto getTag(LogLevel level) const -> String;

        ContextPtr<UserAction> userActionLog;
        ContextPtr<Info> infoLog;
        ContextPtr<Warning> warningLog;
        ContextPtr<Error> errorLog;
        ContextPtr<Debug> debugLog;

        mutable std::mutex mut;
    };

} // namespace loging

#endif // LOGGER_HPP