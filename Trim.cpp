#include "Trim.h"

string Trim::trim(string palabra)
{
	return ltrim(rtrim(palabra));
}

std::string Trim::ltrim(std::string s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

std::string Trim::rtrim(std::string s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}
