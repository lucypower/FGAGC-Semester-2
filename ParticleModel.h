#pragma once

#include <DirectXMath.h>
#include "Transform.h"

using namespace DirectX;



class ParticleModel
{
public :

	ParticleModel(Transform* _transform);
	~ParticleModel();

	void Update(float t);

	void SetVelocity();
	XMFLOAT3 GetVelocity() const { return _velocity; }

	void SetAcceleration();
	XMFLOAT3 GetAcceleration() const { return _acceleration; }

	void moveConstVelocity(const float deltaTime); 
	void moveConstAcceleration(const float deltaTime);

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

	Transform* _transform;
};

