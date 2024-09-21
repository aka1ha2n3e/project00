#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <memory>
#include <mutex>
#include <vector>
#include <map>
#include "common.hpp"
#include "iterator.hpp"
#include "type.hpp"
#include "LogData.hpp"

namespace loging {

    class Logger {
    public:
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
        ~Logger()= default;


        /*
        * @todo 派生クラスをクラスに問わず持たせられるようにする
        */
        LogData log;
        /* 問題なければ消してください*/
        //Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;


        auto getTag(LogLevel level) const -> String;

        mutable std::mutex mut;
    };


} // namespace loging

#endif // LOGGER_HPP
