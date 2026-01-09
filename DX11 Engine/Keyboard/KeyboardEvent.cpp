#include "KeyboardEvent.h"
/*
you wrap Windnow messages into objects like this. 
so your game logic can easily understand what happened on the keyboard.
*/

// constructor 0
KeyboardEvent::KeyboardEvent() 
	:
	type(EventType::Invalid),
	key(0u)
{
}

//constructor 1
KeyboardEvent::KeyboardEvent(const EventType type, const unsigned char key)
	:
	type(type),
	key(key)
{
}

bool KeyboardEvent::IsPress() const
{
	return this->type == EventType::Press;
}

bool KeyboardEvent::IsRelease() const
{
	return this->type == EventType::Release;
}

bool KeyboardEvent::IsValid() const
{
	return this->type != EventType::Invalid;
}

unsigned char KeyboardEvent::GetKeyCode() const
{
	return this->key;
}