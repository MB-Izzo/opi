#pragma once
#include <memory>
#include <spdlog/spdlog.h>

namespace Opi
{
class Logger
{
public:
  static void Init();

  inline static std::shared_ptr<spdlog::logger> &GetCoreLogger()
  {
    return s_coreLogger;
  }

private:
  static std::shared_ptr<spdlog::logger> s_coreLogger;
};
} // namespace Opi

#define OPI_CORE_TRACE(...) ::Opi::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define OPI_CORE_INFO(...) ::Opi::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define OPI_CORE_WARN(...) ::Opi::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define OPI_CORE_ERROR(...) ::Opi::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define OPI_CORE_ASSERT(x, ...)                                                \
  if (!(x))                                                                    \
  {                                                                            \
    OPI_CORE_ERROR("Assertion Failed: {} | " __VA_ARGS__, #x);                 \
    std::abort();                                                              \
  }
