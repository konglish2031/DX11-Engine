
#include "ErrorLogger.h"
#include <comdef.h> // for _com_error

void ErrorLogger::Log(std::string message)
{
	std::string error_message = "Error: " + message;
	
	// MessageBoxA: The "ANSI" version of the Windows message box function.
	MessageBoxA(NULL,			// no parent
		error_message.c_str(),	// Converts the C++ string to a C-style string pointer that Windows understands.
		"Error",				// The title of the pop-up window.
		MB_ICONERROR);			// A flag that tells Windows to play an error sound and show a red "X" icon.
}

void ErrorLogger::Log(HRESULT hr, std::string message)
{
	_com_error error(hr);
	std::wstring error_message = L"Error: " + StringConverter::StringToWide(message) + L"\n";
	MessageBoxW(NULL, error_message.c_str(), L"Error", MB_ICONERROR);
}

void ErrorLogger::Log(HRESULT hr, std::wstring message)
{
	_com_error error(hr);
	std::wstring error_message = L"Error: " + message + L"\n";
	MessageBoxW(NULL, error_message.c_str(), L"Error", MB_ICONERROR);

}
