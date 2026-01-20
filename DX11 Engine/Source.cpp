#include "Engine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		ErrorLogger::Log(hr, "Source, failed to call CoInitialize()");
		return -1;
	}

	/*COMException exception(0, "TEST MESSAGE", __FILE__, __FUNCTION__, __LINE__);
	ErrorLogger::Log(exception);*/

	Engine engine;
	if(engine.Initialize(hInstance, "Window Title", "MyWindowClass", 800, 600))
	{
		while (engine.ProcessMessages() == true)
		{
			engine.Update(); // process the input from hardward (e.g. mouse, keyboard)
			engine.RenderFrame(); // redner via graphics pipeline
		}

	}	
	return 0;
}