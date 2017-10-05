#include "logger.hpp"
#include "meta.hpp"

const std::string Logger::getLogDir()
{
    return getSrcDir() + "../log/";
}

std::shared_ptr<spdlog::logger> Logger::instance = NULL;

void Logger::init_logging()
{
    if (instance != NULL)
    {
        LOG_ERR("Repeated call of init_logging()!");
        return;
    }

    auto stdout_sink = std::make_shared<spdlog::sinks::stdout_sink_st>();
    stdout_sink->set_level(spdlog::level::info);
    auto file_sink = std::make_shared<spdlog::sinks::simple_file_sink_st>(getLogDir() + "log.txt", true);
    file_sink->set_level(spdlog::level::trace);

    instance = std::make_shared<spdlog::logger>("template_logger", spdlog::sinks_init_list{stdout_sink, file_sink});
    //instance->set_level(spdlog::level::trace);
    instance->set_pattern("[%x %X][%L]%v");
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
