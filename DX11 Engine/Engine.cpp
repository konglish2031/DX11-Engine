#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, std::string windowTitle, std::string window_class, int width, int height)
{
	timer.Start();

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
	float dt = timer.GetMilisecondsElapsed();
	timer.Restart();

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

		if (mouse.IsRightDown())
		{
			if (me.GetType() == MouseEvent::EventType::RAW_MOVE)
			{
				this->graphic.camera.AdjustRotation((float)me.GetPosY() * 0.01f, (float)me.GetPosX() * 0.01f, 0);
			}
		}
	}
	this->graphic.model.AdjustRotation(0.0f, 0.001f * dt, 0.0f);

	const float cameraSpeed = 0.0002f;

	if (keyboard.KeyIsPressed('W'))
	{
		this->graphic.camera.AdjustPosition(this->graphic.camera.GetForwardVector() * cameraSpeed * dt);
	}
	if (keyboard.KeyIsPressed('S'))
	{
		this->graphic.camera.AdjustPosition(this->graphic.camera.GetBackwardVector() * cameraSpeed * dt);
	}
	if (keyboard.KeyIsPressed('A'))
	{
		this->graphic.camera.AdjustPosition(this->graphic.camera.GetLeftVector() * cameraSpeed * dt);
	}
	if (keyboard.KeyIsPressed('D'))
	{
		this->graphic.camera.AdjustPosition(this->graphic.camera.GetRightVector() * cameraSpeed * dt);
	}
	if (keyboard.KeyIsPressed(VK_SPACE))
	{
		this->graphic.camera.AdjustPosition(0.0f, cameraSpeed * dt, 0.0f);
	}
	if (keyboard.KeyIsPressed('Z'))
	{
		this->graphic.camera.AdjustPosition(0.0f, -cameraSpeed * dt, 0.0f);
	}
}