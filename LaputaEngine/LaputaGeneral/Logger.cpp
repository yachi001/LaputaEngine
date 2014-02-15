
#include "Logger.h"
#include <iostream>

using namespace std;

namespace logger
{
    Logger::Logger(const string& className)
    {
        this->className = className;
    }

    Logger::~Logger()
    {
    }

    Logger& Logger::GetLogger(const string& className)
    {
        static Logger instance(className);
        return instance;
    }

    void Logger::Info(const string& message)
    {
        clog << "INFO: " << message << endl;
    }

    void Logger::Debug(const string& message)
    {
        clog << "DEBUG: " << message << endl;
    }

    void Logger::Warning(const string& message)
    {
        clog << "WARNING: " << message << endl;
    }

    void Logger::Error(const string& message)
    {
        clog << "ERROR: " << message << endl;
    }

    void Logger::Fatal(const string& message)
    {
        clog << "FATAL: " << message << endl;
    }

}