
#ifndef LOGDATA_HPP
#define LOGDATA_HPP

#include <map>
#include <stdexcept>
#include <vector>
#include "common/commonType.hpp"
#include "iterator/iterator.hpp"

namespace loging
{
    class LogData : public iterator::AbstractArray<loging::String>
    {
    public:
        virtual ~LogData() = 0;
        virtual auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override = 0;
        virtual auto AppendData(loging::String input) -> void = 0;

    protected:
        std::map<LogLevel, std::vector<loging::String>> data;
    };

    class UserAction : public LogData
    {
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    };

    class Info : public LogData
    {
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    };

    class Warning : public LogData
    {
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    };

    class Error : public LogData
    {
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;

    };

    class Debug : public LogData
    {
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    };

} // namespace loging

#endif // LOGDATA_HPP