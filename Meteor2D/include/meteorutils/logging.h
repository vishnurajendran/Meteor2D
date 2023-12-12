#pragma once
#include <spdlog/spdlog.h>

#define logNoFormat(msg) spdlog::info(msg);
#define warnNoFormat(msg) spdlog::warn(msg);
#define errorNoFormat(msg) spdlog::error(msg);

#define logFormat(msg, args) spdlog::info(msg,args);
#define warnFormat(msg,args) spdlog::warn(msg,args);
#define errorFormat(msg,args) spdlog::error(msg,args);