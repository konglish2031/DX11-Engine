#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, std::string windowTitle, std::string window_class, int width, int height)
{
	if (!this->WindowContainer::render_window.Initialize(this, hInstance, windowTitle, window_class, width, height))
		return false;

	if(!graphic.Initialize(this->render_window.GetHWND(), width, height))
		return false;

	return true;
}

void Engine::RenderFrame()
{
	graphic.RenderFrame();
}

bool Engine::ProcessMessages()
{
	return this->render_window.ProcessMessages();
}

void Engine::Update() 
{
	// key board processing
	while (!keyboard.CharBufferIsEmpty()) // If keyboard input occurs
	{
		unsigned char ch = keyboard.ReadChar(); // read the first character in charBuffer
		
		// present the ch
		std::string outmsg = "Char: ";
		outmsg += ch;
		outmsg += "\n";
		OutputDebugStringA(outmsg.c_str()); 
	}

	while (!keyboard.KeyBufferIsEmpty()) // If keyboard input occurs
	{
		OutputDebugStringA("Engine::Update(), !keyboard.KeyBufferIsEmpty())\n");
		KeyboardEvent kbe = keyboard.ReadKey();
		unsigned char keycode = kbe.GetKeyCode(); // read the first keycode in keyBuffer

		// present the keycode
		std::string outmsg = "";
		if (kbe.IsPress())
		{
			outmsg += "Key pressed: ";
		}
		if (kbe.IsRelease())
		{
			outmsg += "Key released: ";
		}
		outmsg += keycode;
		outmsg += "\n";
		OutputDebugStringA(outmsg.c_str());
	}

	// mouse event processing
	while (!mouse.EventBufferIsEmpty())
	{
		MouseEvent me = mouse.ReadEvent();

		if (me.GetType() == MouseEvent::EventType::RAW_MOVE)
		{
			// printing mouse position
			std::string outmsg = "dX: ";
			outmsg += std::to_string(me.GetPosX());
			outmsg += ", dY: ";
			outmsg += std::to_string(me.GetPosY());
			outmsg += "\n";
			//OutputDebugStringA(outmsg.c_str());
		}
		
		// printing mouse wheel up/down
		if (me.GetType() == MouseEvent::EventType::WheelDown)
		{
			OutputDebugStringA("mouse wheel down\n");
		}
		if (me.GetType() == MouseEvent::EventType::WheelUp)
		{
			OutputDebugStringA("mouse wheel up\n");
		}
	}
}