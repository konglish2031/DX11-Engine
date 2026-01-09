#include "StringConverter.h"

//std::wstring stringconverter::stringtowide(std::string str)
//{
//	std::wstring wide_string(str.begin(), str.end());
//	return wide_string;
//}

std::wstring StringConverter::StringToWide(std::string str)
{
    if (str.empty()) return L"";
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);

    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

