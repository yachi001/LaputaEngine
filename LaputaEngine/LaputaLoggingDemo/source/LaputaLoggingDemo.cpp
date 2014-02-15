#include <Logger.h>

int main(int argc, char *argv[])
{
    using lpta::Logger;
    Logger::GetLogger("test").Debug("hi");
    Logger::GetLogger("test").Error("oh noes!");
    return 0;
}