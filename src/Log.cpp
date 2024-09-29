#include "common/commonType.hpp"
#include "logging/LogData.hpp"
#include "logging/Logger.hpp"

namespace loging
{
    /*
    *  @brief loggerのインスタンスを作成する
    * @return loggerのインスタンス
    */

LogData::~LogData() {};
   /*
   * @todo イテレーターの実装
   */
   auto UserAction::CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> {
      return nullptr;
   }
   auto UserAction::AppendData( loging::String input) -> void
   {
      this->data[LogLevel::USER_ACTION].push_back(input);
   };

   auto Info::CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> {
      return nullptr;
   }
   auto Info::AppendData( loging::String input) -> void
   {
      this->data[LogLevel::INFO].push_back(input);
   };

   auto Warning::CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> {
      return nullptr;
   }
   auto Warning::AppendData( loging::String input) -> void
   {
      this->data[LogLevel::WARNING].push_back(input);
   };

   auto Error::CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> {
      return nullptr;
   }
   auto Error::AppendData( loging::String input) -> void
   {
      this->data[LogLevel::ERROR].push_back(input);
   };

   auto Debug::CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> {
      return nullptr;
   }
   auto Debug::AppendData( loging::String input) -> void
   {
      this->data[LogLevel::DEBUG].push_back(input);
   };





   /*
    *  @brief loggerのインスタンスを作成する
    * @return loggerのインスタンス
    */
   auto Logger::getLogger() -> Logger& {
      static Logger instance;
      return instance;
   }
    auto Logger::setLogFile(const fileSystem::Path &logFilePath) -> void {
        // 分からん
    }

    auto Logger::logUserAction(const String &message) -> void {
        getLogger().leaveLog(LogLevel::USER_ACTION, message);
    }

    auto Logger::logInfo(const String &message) -> void {
        getLogger().leaveLog(LogLevel::INFO, message);
    }

    auto Logger::logWarning(const String &message) -> void {
        getLogger().leaveLog(LogLevel::WARNING, message);
    }

    auto Logger::logError(const String &message) -> void {
        getLogger().leaveLog(LogLevel::ERROR, message);
    }

    auto Logger::logDebug(const String &message) -> void {
        getLogger().leaveLog(LogLevel::DEBUG, message);
    }

    auto Logger::leaveLog(LogLevel level, const String &message) -> void {
        std::lock_guard<std::mutex> lock(mut);
        String taggedMessage = getTag(level) + message;
        switch (level) {
            case LogLevel::USER_ACTION:
                userActionLog->AppendData(taggedMessage);
                break;
            case LogLevel::INFO:
                infoLog->AppendData(taggedMessage);
                break;
            case LogLevel::WARNING:
                warningLog->AppendData(taggedMessage);
                break;
            case LogLevel::ERROR:
                errorLog->AppendData(taggedMessage);
                break;
            case LogLevel::DEBUG:
                debugLog->AppendData(taggedMessage);
                break;
        }
    }

    auto Logger::getTag(LogLevel level) const -> String {
      // 分からん
      return nullptr;
    }
}
