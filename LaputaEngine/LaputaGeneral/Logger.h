
#include <string>
#include <iostream>

namespace logger
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

        Logger(Logger const&);
        void operator=(Logger const&);
    };
}