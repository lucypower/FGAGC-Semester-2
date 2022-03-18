#pragma once

#include <DirectXMath.h>
#include "Transform.h"
#include "Vector3D.h"

using namespace DirectX;



class ParticleModel
{
public :

	ParticleModel(Transform* _transform, bool useVelocity, bool useAcceleration);
	~ParticleModel();

	void Update(float t);

	void SetVelocity(Vector3D toset) { _velocity = toset; };
	Vector3D GetVelocity() const { return _velocity; }

	void SetAcceleration(Vector3D toset) { _acceleration = toset; };
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

	Transform* _transform;

	bool _useConstVelocity;
	bool _useConstAcceleration;
};

