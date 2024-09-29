
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
        LogData() : AbstractArray<loging::String>() {};

        virtual auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override = 0;
        virtual auto AppendData(loging::String input) -> void = 0;

        auto GetSize() const -> size_t override { return 0; }
        auto GetItemImpl(int) const -> loging::String& override {
            static loging::String dummy;
            return dummy;
        };

    protected:
        std::map<LogLevel, std::vector<loging::String>> data;
    };

    class UserAction : public LogData
    {
    public:
        UserAction() : LogData() {};
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    };

    class Info : public LogData
    {
    public:
        Info() : LogData() {};
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    };

    class Warning : public LogData
    {
    public:
        Warning() : LogData() {};
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    };

    class Error : public LogData
    {
    public:
        Error() : LogData() {};
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;

    };

    class Debug : public LogData
    {
    public:
        Debug() : LogData() {};
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    };

} // namespace loging

#endif // LOGDATA_HPP