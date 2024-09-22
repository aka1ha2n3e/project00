#include "commonType.hpp"
#include "type.hpp"
#include "LogData.hpp"
#include "Logger.hpp"

namespace loging
{
   LogData::~LogData(){};

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

}
