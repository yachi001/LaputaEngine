#include <Logger.h>

int main(int argc, char *argv[])
{
    using lpta::Logger;
    Logger::GetLogger("test").Warning("hi");
    Logger::GetLogger("test").Error("oh noes!");
    return 0;
}



