// Engine.h
#pragma once
#include "WindowContainer.h"
#include "Timer.h"

class Engine:WindowContainer
{
public:
	bool Initialize(HINSTANCE hInstance, std::string windowTitle, std::string window_class, int width, int height);
	bool ProcessMessages();
	void Update(); 
	void RenderFrame();

private:
	Timer timer;
};