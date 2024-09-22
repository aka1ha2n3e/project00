
#ifndef LOGDATA_HPP
#define LOGDATA_HPP

#include <map>
namespace loging {
/*
* @todo サブクラスをカテゴリ別に作る
* */
    class LogData : public iterator::AbstractArry<loging::String> {
    public:
        virtual auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> = 0;
        virtual auto AppendData(loging::String input) -> void = 0;
    protected:
        virtual ~LogData() = 0;
        std::map<LogLevel, std::vector<loging::String>> data;
    };



    class UserAction : public LogData{
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    private:
    };
   
    class Info : public LogData{
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    private:
    };
   
    class Warning : public LogData{
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    private:
    };
   
    class Error : public LogData{
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    private:
    };
   
    class Debug : public LogData{
    public:
        auto AppendData(loging::String input) -> void override;
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>> override;
    private:
    };
    
} // loging
#endif // LOGDATA_HPP

