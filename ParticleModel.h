#pragma once

#include <DirectXMath.h>

using namespace DirectX;



class ParticleModel
{
public :

	ParticleModel();
	~ParticleModel();

	void Update(float t);

	void SetVelocity();
	XMFLOAT3 GetVelocity() const { return _velocity; }

	void SetAcceleration();
	XMFLOAT3 GetAcceleration() const { return _acceleration; }

	void moveConstVelocity(const float deltaTime); // need possible get set stuff idk
	void moveConstAcceleration(const float deltaTime); // don't think these are actually affecting the object at the moment

	void UpdateNetForce();
	void UpdateAcceleration();

private :

	XMFLOAT4X4 _world;
	
	XMFLOAT3 _velocity;
	XMFLOAT3 _position;
	XMFLOAT3 _acceleration;

	XMVECTOR XMVelocity = XMLoadFloat3(&_velocity);
	XMVECTOR XMPosition = XMLoadFloat3(&_position);
	XMVECTOR XMAcceleration = XMLoadFloat3(&_acceleration);

	float _netForce;
	float _mass;
};

