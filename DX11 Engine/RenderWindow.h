// RenderWindow.h
#pragma once
#include "ErrorLogger.h"

class WindowContainer;

class RenderWindow
{
public:
	bool Initialize(WindowContainer* pWindowContainer, HINSTANCE hInstance, std::string windowTitle, std::string window_class, int width, int height);
	bool ProcessMessages(); // Process the input messages(e.g. mouse or keyboard) 
	HWND GetHWND() const;
	~RenderWindow();

private:
	/* RegisterWindowClass();
		1. Before a window exists, you must define its "Class."

	*/
	void RegisterWindowClass(); 

	HWND handle = NULL; // handle to this window
	HINSTANCE hInstance; // handle to application instance

	std::string window_title = "";
	std::wstring window_title_wide = L"";
	std::string window_class = "";
	std::wstring window_class_wide = L"";
	
	int width = 0;
	int height = 0;
};