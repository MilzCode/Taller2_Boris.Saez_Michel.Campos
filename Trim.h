#pragma once
#include <iostream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

using namespace std;
class Trim
{

public:
	string trim(string palabra);

private:
	std::string ltrim(std::string s);
	std::string rtrim(std::string s);
};

