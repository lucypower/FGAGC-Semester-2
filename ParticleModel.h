#pragma once

#include <DirectXMath.h>

using namespace DirectX;



class ParticleModel
{
public :

	ParticleModel();
	~ParticleModel();

private :

	XMFLOAT4X4 _world;
};

