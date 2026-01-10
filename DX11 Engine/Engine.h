// engine.h
#pragma once
#include "WindowContainer.h"

class Engine:WindowContainer
{
public:
	bool Initialize(HINSTANCE hInstance, std::string windowTitle, std::string window_class, int width, int height);
	bool ProcessMessages();
	// execute (every frame?)
	void Update(); 
	void RenderFrame();
};