#pragma once
#include<DirectXMath.h>	

struct Vertex
{	
	DirectX::XMFLOAT2 pos;
	
	Vertex() : pos(0.0f, 0.0f) {}
	Vertex(float x, float y)
		: pos(x, y) {}

};