#include "logger.hpp"

int main(int argc, char** argv)
{
    Logger::init_logging();
    LOG_INFO("test");
    return 0;
}
