#include "Logger.h"

#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>

using namespace std;

namespace lpta
{

    Logger::Logger(const string& className)
    {
        this->className = className;
        log4cplus::initialize();
        log4cplus::BasicConfigurator config;
        config.configure();
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
        log4cplus::Logger::getRoot().log(log4cplus::INFO_LOG_LEVEL, GetMsg(message));
    }

    void Logger::Debug(const string& message)
    {
        log4cplus::Logger::getRoot().log(log4cplus::DEBUG_LOG_LEVEL, GetMsg(message));
    }

    void Logger::Warning(const string& message)
    {
        log4cplus::Logger::getRoot().log(log4cplus::WARN_LOG_LEVEL, GetMsg(message));
    }

    void Logger::Error(const string& message)
    {
        log4cplus::Logger::getRoot().log(log4cplus::ERROR_LOG_LEVEL, GetMsg(message));
    }

    void Logger::Fatal(const string& message)
    {
        log4cplus::Logger::getRoot().log(log4cplus::FATAL_LOG_LEVEL, GetMsg(message));
    }

    wstring Logger::GetMsg(const string& message)
    {
        char dateStr[9];
        char timeStr[9];
        _strdate(dateStr);
        _strtime(timeStr);

        wstringstream ws;
        ws << message.c_str() << '\n' << dateStr << ' ' << timeStr << ' ' << className.c_str();
        return ws.str();
    }

}