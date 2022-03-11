#pragma once

#include <DirectXMath.h>
#include "Transform.h"
#include "Vector3D.h"

using namespace DirectX;



class ParticleModel
{
public :

	ParticleModel(Transform* _transform);
	~ParticleModel();

	void Update(float t);

	void SetVelocity();
	Vector3D GetVelocity() const { return _velocity; }

	void SetAcceleration();
	Vector3D GetAcceleration() const { return _acceleration; }

	void moveConstVelocity(const float deltaTime); 
	void moveConstAcceleration(const float deltaTime);

	void UpdateNetForce();
	void UpdateAcceleration();

private :

	XMFLOAT4X4 _world;
	
	Vector3D _velocity;
	Vector3D _position;
	Vector3D _acceleration;

	/*XMVECTOR XMVelocity = XMLoadFloat3(&_velocity);
	XMVECTOR XMPosition = XMLoadFloat3(&_position);
	XMVECTOR XMAcceleration = XMLoadFloat3(&_acceleration);*/

	Transform* _transform;
};

