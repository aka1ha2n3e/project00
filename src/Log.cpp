#include "type.hpp"
#include "Logger.hpp"

namespace loging
{

 auto LogData::AppendData(loging::Logger::LogLevel type, loging::String input) -> void
 {
   this->data[type].second.push_buck(input);
 };
auto LogData::CreateIterator() const -> iterator::BrowseIterator<loging::String>*
{
};

auto Logger::logUserAction (const String& message) -> void
{
  log.AppendData(USER_ACTION, message);
};

auto Logger::logInfo       (const String& message) -> void
{
  log.AppendData(INFO, message);
};

auto Logger::logWarning    (const String& message) -> void
{
  log.AppendData(WARNING, message);
};

auto Logger::logError      (const String& message) -> void
{
  log.AppendData(ERROR, message);
};

auto Logger::logDebug      (const String& message) -> void
{
  log.AppendData(DEBUG, message);
};


}
