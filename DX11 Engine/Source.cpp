#include "Engine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	Engine engine;
	if(engine.Initialize(hInstance, "Window Title", "MyWindowClass", 800, 600));
	{
		while (engine.ProcessMessages() == true)
		{
			engine.Update(); // process the input from hardward (e.g. mouse, keyboard)
			engine.RenderFrame(); // redner via graphics pipeline
		}

	}	
	return 0;
}