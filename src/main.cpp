#include "logger.hpp"
#include <cstdlib>

int main(int argc, char** argv)
{
    Logger::init_logging();
    LOG_WARN("warn");
    LOG_INFO("info");
    LOG_DEBUG("debug");
    LOG_TRACE("trace");
    sleep(10);
    return 0;
}
