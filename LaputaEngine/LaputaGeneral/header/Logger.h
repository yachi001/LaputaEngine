#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <iostream>

namespace lpta
{

class Logger
{
public:
    static Logger& GetLogger(const std::string& className);

    void Info(const std::string& message);
    void Debug(const std::string& message);
    void Warning(const std::string& message);
    void Error(const std::string& message);
    void Fatal(const std::string& message);

private:
    std::string className;

    Logger(const std::string& className);
    ~Logger();

    std::wstring ConvertStringToWString(const std::string& message);
    void AddTimestamp();


    Logger(Logger const&);
    void operator=(Logger const&);
};

}

#endif