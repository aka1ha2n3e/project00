#ifndef LOGDATA_HPP
#define LOGDATA_HPP

#include <map>
namespace loging {
/*
* @todo サブクラスをカテゴリ別に作る
* */
    class LogData : public iterator::AbstractArry<loging::String> {
    public:
        ~LogData() = 0;
        auto AppendData(LogLevel type, loging::String input) -> void;
    private:
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<loging::String>>;
        std::map<LogLevel, std::vector<loging::String>> data;
    };

    class UserAction : public LogData{
    public:
    private:
    };
   
    class Info : public LogData{
    public:
    private:
    };
   
    class Warning : public LogData{
    public:
    private:
    };
   
    class Error : public LogData{
    public:
    private:
    };
   
    class Debug : public LogData{
    public:
    private:
    };
    
} // loging
#endif // LOGDATA_HPP