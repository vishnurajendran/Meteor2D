#pragma once
#include <spdlog/spdlog.h>

// prints a message
#define log(...) spdlog::info(__VA_ARGS__)
// prints a warning message
#define warn(...) spdlog::warn(__VA_ARGS__)
// prints an error message
#define error(...) spdlog::error(__VA_ARGS__)