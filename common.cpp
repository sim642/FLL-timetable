#include "common.hpp"
#include <ctime>
#include <cstring>
#include <stdexcept>

system_clock::time_point strptime(const std::string &str, const std::string &format)
{
	std::tm tm;
	std::memset(&tm, 0, sizeof(tm));
	auto ptr = strptime(str.c_str(), format.c_str(), &tm);
	if (ptr == nullptr)
		throw std::runtime_error("strptime: failed to match entire format");
	return system_clock::from_time_t(std::mktime(&tm));
}

std::string strftime(const std::string &format, const system_clock::time_point &tp)
{
	std::time_t t = system_clock::to_time_t(tp);
	char str[512];
	std::strftime(str, sizeof(str), format.c_str(), std::localtime(&t));
	return std::string(str);
}
