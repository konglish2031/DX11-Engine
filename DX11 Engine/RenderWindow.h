// RenderWindow.h
#pragma once
#include "ErrorLogger.h"

class WindowContainer; // forward definition

class RenderWindow
{
public:
	bool Initialize(WindowContainer* pWindowContainer, HINSTANCE hInstance, std::string windowTitle, std::string window_class, int width, int height);
	bool ProcessMessages(); // Process the input messages(e.g. mouse or keyboard) 
	HWND GetHWND() const;
	~RenderWindow();

private:
	void RegisterWindowClass(); 

	// handle to the window
	HWND handle = NULL;

	HINSTANCE hInstance; 

	std::string window_title = "";
	std::wstring window_title_wide = L"";
	std::string window_class = "";
	std::wstring window_class_wide = L"";
	
	int width = 0;
	int height = 0;
};