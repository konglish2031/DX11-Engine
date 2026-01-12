#pragma once
#include<DirectXMath.h>	

struct Vertex
{	
	DirectX::XMFLOAT2 pos;
	
	Vertex() {}
	Vectex(float x, float y)
		: pos(x, y) {}

};