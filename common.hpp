#ifndef COMMON_H
#define COMMON_H

#include <chrono>
#include <string>

using system_clock = std::chrono::system_clock;

system_clock::time_point strptime(const std::string &str, const std::string &format);
std::string strftime(const std::string &format, const system_clock::time_point &tp);

#endif /* COMMON_H */
