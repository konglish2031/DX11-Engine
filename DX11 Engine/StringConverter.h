// StringConverter.h
#pragma once
#include <string>
#include <Windows.h>

class StringConverter
{
public:
	static std::wstring StringToWide(std::string str);
};