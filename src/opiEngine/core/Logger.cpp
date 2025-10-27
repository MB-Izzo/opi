#include "opiEngine/Core/Logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Opi
{

std::shared_ptr<spdlog::logger> Logger::s_coreLogger;

void Logger::Init()
{
  spdlog::set_pattern("%^[%T] %n: %v%$"); // colored [HH:MM:SS] LOGGER: message
  s_coreLogger = spdlog::stdout_color_mt("OPI");
}

} // namespace Opi
