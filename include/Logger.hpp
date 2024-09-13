#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <map>
#include <memory>
#include <mutex>
#include <vector>
#include "common.hpp"
#include "iterator.hpp"
#include "type.hpp"

namespace loging {

    class Logger {
    public:
        enum class LogLevel {
            INFO,
            WARNING,
            ERROR,
            DEBUG,
            USER_ACTION,
        };

        static auto LeaveLog(LogLevel level, const String &message) -> void;
        static auto getLogger() -> Logger &;

        auto setLogFile(const fileSystem::Path &logFilePath) -> void;
        auto logUserAction(const String &message) -> void;
        auto logInfo(const String &message) -> void;
        auto logWarning(const String &message) -> void;
        auto logError(const String &message) -> void;
        auto logDebug(const String &message) -> void;


    private:
        Logger() = default;
        ~Logger() {
            if (logFile_.is_open()) {
                logFile_.close();
            }
        };


        LogData log;
        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;


        auto getTag(LogLevel level) const -> String;

        mutable std::mutex mut;
    };
/*
* @todo サブクラスをカテゴリ別に作る
* */
    class LogData : public iterator::AbstractArry<loging::String> {
    public:
        ~LogData() = 0;
        auto AppendData(Logger::LogLevel type, loging::String input) -> void {
            data[type].push_buck(std::move(input));
        };

    private:
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>>;
        std::map<Logger::LogLevel, std::vector<loging::String>> data;
    };

    class

} // namespace loging

#endif // LOGGER_HPP
