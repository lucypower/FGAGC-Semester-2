#pragma once

#include <DirectXMath.h>

using namespace DirectX;



class ParticleModel
{
public :

	ParticleModel();
	~ParticleModel();

	void Update();

	void moveConstVelocity(const float deltaTime);
	void moveConstAcceleration(const float deltaTime);

private :

	XMFLOAT4X4 _world;
	
	XMFLOAT3 _velocity;
	XMFLOAT3 _position;
	XMFLOAT3 _acceleration;
};

