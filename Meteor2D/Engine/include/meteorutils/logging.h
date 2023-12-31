#pragma once
#include <spdlog/spdlog.h>

namespace meteor {
	// prints a message
#define mLog(...) spdlog::info(__VA_ARGS__)
// prints a warning message
#define mWarn(...) spdlog::warn(__VA_ARGS__)
// prints an error message
#define mError(...) spdlog::error(__VA_ARGS__)
}