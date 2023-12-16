#pragma once
#include <spdlog/spdlog.h>

#define logNoFormat(msg) spdlog::info(msg)
#define warnNoFormat(msg) spdlog::warn(msg)
#define errorNoFormat(msg) spdlog::error(msg)

#define logFormat(...) spdlog::info(__VA_ARGS__)
#define warnFormat(...) spdlog::warn(__VA_ARGS__)
#define errorFormat(...) spdlog::error(__VA_ARGS__)