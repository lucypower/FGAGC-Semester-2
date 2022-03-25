#pragma once

#include <DirectXMath.h>
#include "Transform.h"
#include "Vector3D.h"
#include <vector>
#include "BaseForces.h"

using namespace DirectX;



class ParticleModel
{
public :

	ParticleModel(Transform* _transform, bool useVelocity, bool useAcceleration, float objectMass, Vector3D netForce);
	~ParticleModel();

	void Update(float t);

	void SetVelocity(Vector3D toset) { _velocity = toset; }
	Vector3D GetVelocity() const { return _velocity; }

	void SetAcceleration(Vector3D toset) { _acceleration = toset; }
	Vector3D GetAcceleration() const { return _acceleration; }

	void moveConstVelocity(const float deltaTime); 
	void moveConstAcceleration(const float deltaTime);

	void UpdateNetForce();
	void UpdateAcceleration();

	void SetObjectMass(float toset) { _objectMass = toset; }
	float GetObjectMass() const { return _objectMass; }

	void SetNetForce(Vector3D toset) { _netForce = toset; }
	Vector3D GetNetForce() const { return _netForce; } 

private :

	XMFLOAT4X4 _world;
	
	Vector3D _velocity;
	Vector3D _position;
	Vector3D _acceleration;

	Transform* _transform;

	bool _useConstVelocity;
	bool _useConstAcceleration;

	Vector3D _netForce;
	float _objectMass;

	float _gravity = 9.81f;
	float _weight = _objectMass * _gravity;

	std::vector<BaseForces> forces;
};

