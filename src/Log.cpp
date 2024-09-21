#include "type.hpp"
#include "LogData.hpp"
#include "Logger.hpp"

namespace loging
{

 auto LogData::AppendData(LogLevel type, loging::String input) -> void
 {
   this->data[type].push_back(input);
 };
auto LogData::CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>>
{
};
/*
auto Logger::logUserAction (const String& message) -> void
{
  log.AppendData(LogLevel::USER_ACTION, message);
};

auto Logger::logInfo       (const String& message) -> void
{
  log.AppendData(LogLevel::INFO, message);
};

auto Logger::logWarning    (const String& message) -> void
{
  log.AppendData(LogLevel::WARNING, message);
};

auto Logger::logError      (const String& message) -> void
{
  log.AppendData(LogLevel::ERROR, message);
};

auto Logger::logDebug      (const String& message) -> void
{
  log.AppendData(LogLevel::DEBUG, message);
};
*/

}
