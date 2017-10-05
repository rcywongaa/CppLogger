#pragma once

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_TRACE(msg) Logger::log(Logger::TRACE, __FILENAME__, __LINE__, msg)
#define LOG_DEBUG(msg) Logger::log(Logger::DEBUG, __FILENAME__, __LINE__, msg)
#define LOG_INFO(msg) Logger::log(Logger::INFO, __FILENAME__, __LINE__, msg)
#define LOG_WARN(msg) Logger::log(Logger::WARN, __FILENAME__, __LINE__, msg)
#define LOG_ERR(msg) Logger::log(Logger::ERR, __FILENAME__, __LINE__, msg)

#include <string>
#include <memory>
#include "spdlog/spdlog.h"

class Logger
{
    public:
        enum Severity
        {
            TRACE,
            DEBUG,
            INFO,
            WARN,
            ERR
        };

        static void init_logging();
        static void log(Severity severity, std::string source_filename, int line_number, std::string message);

    private:
        static std::shared_ptr<spdlog::logger> instance;
        const static std::string getLogDir();
        Logger() {};
};
