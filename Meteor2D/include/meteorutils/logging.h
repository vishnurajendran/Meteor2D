#pragma once
#include <spdlog/spdlog.h>

#define log(msg) spdlog::info(msg);
#define warn(msg) spdlog::warn(msg);
#define error(msg) spdlog::error(msg);

#define logFormat(msg, args) spdlog::info(msg,args);
#define warnFormat(msg,args) spdlog::warn(msg,args);
#define errorFormat(msg,args) spdlog::error(msg,args);