// ErrorLogger.h
#pragma once
#include "COMException.h"

#include <fstream>
#include <iostream>
#include <string>

class ErrorLogger
{
public:
	static void Log(std::string message); // present message boxes
	static void Log(HRESULT hr, std::string message);
	static void Log(HRESULT hr, std::wstring message);
	static void Log(COMException& exception);

};