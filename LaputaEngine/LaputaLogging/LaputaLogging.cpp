// LaputaLogging.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "LaputaLogging.h"


#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/ndc.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/loggingmacros.h>

#include <log4cplus/configurator.h>
#include <iomanip>
#include <iostream>

// This is an example of an exported variable
LAPUTALOGGING_API int nLaputaLogging=0;

// This is an example of an exported function.
LAPUTALOGGING_API void testLogToConsole(void)
{
    using namespace log4cplus;
    //BasicConfigurator config;
    //config.configure();

    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("logging"));
    LOG4CPLUS_FATAL(logger, LOG4CPLUS_TEXT("fatal error"));

}

LAPUTALOGGING_API void testLogToFile(void) {
    using namespace log4cplus;

    log4cplus::initialize();
    helpers::LogLog::getLogLog()->setInternalDebugging(false);
    SharedAppenderPtr append_1(
        new RollingFileAppender(LOG4CPLUS_TEXT("log/Test.log"), 5 * 1024, 5));
    append_1->setName(LOG4CPLUS_TEXT("LOGGER"));
    append_1->setLayout(std::auto_ptr<Layout>(new TTCCLayout()));
    Logger::getRoot().addAppender(append_1);

    Logger test = Logger::getInstance(LOG4CPLUS_TEXT("logfile"));

    LOG4CPLUS_DEBUG(test, LOG4CPLUS_TEXT("Info"));
}

// This is the constructor of a class that has been exported.
// see LaputaLogging.h for the class definition
CLaputaLogging::CLaputaLogging()
{
	return;
}
