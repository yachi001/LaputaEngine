
#include "Logger.h"
#include <iostream>
#include <string>
#include <sstream>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>
using namespace std;

namespace lpta
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
    log4cplus::initialize(); // gah!
    log4cplus::BasicConfigurator config;
    config.configure();
    wstringstream ws;
    ws << message.c_str();
    log4cplus::Logger::getRoot().log(log4cplus::WARN_LOG_LEVEL, ws.str());
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