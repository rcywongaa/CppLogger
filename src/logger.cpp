#include "logger.hpp"

std::shared_ptr<spdlog::logger> Logger::instance = NULL;

void Logger::init_logging()
{
    if (instance != NULL)
    {
        LOG_ERR("Repeated call of init_logging()!");
        return;
    }
    instance = spdlog::stdout_logger_mt("template_logger");
    instance->set_level(spdlog::level::info);
    instance->set_pattern("[%c][%L]%v");
}

void Logger::log(Severity severity, std::string source_filename, int line_number, std::string message)
{
    if (instance == NULL)
    {
        init_logging();
        LOG_ERR("log() called before init_logging()!");
    }
    std::string msg = "[" + std::string(source_filename) + ":" + std::to_string(line_number) + "]   " + message;
    if (severity == TRACE) instance->trace(msg);
    if (severity == DEBUG) instance->debug(msg);
    if (severity == INFO) instance->info(msg);
    if (severity == WARN) instance->warn(msg);
    if (severity == ERR) instance->error(msg);
    return;
}
