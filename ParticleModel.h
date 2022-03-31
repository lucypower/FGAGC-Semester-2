#pragma once

#include <DirectXMath.h>
#include "Transform.h"
#include "Vector3D.h"
#include <vector>
#include "BaseForces.h"
#include "Gravity.h"
#include "LaminarFlow.h"
#include "TurbulentFlow.h"

using namespace DirectX;



class ParticleModel
{
public :

	ParticleModel(Transform* _transform, bool useVelocity, bool useAcceleration, float objectMass, Vector3D netForce);
	~ParticleModel();

	void Update(float t);

	void SetVelocity(Vector3D velocity) { _velocity = velocity; }
	Vector3D GetVelocity() const { return _velocity; }

	void SetAcceleration(Vector3D acceleration) { _acceleration = acceleration; }
	Vector3D GetAcceleration() const { return _acceleration; }

	void moveConstVelocity(const float deltaTime); 
	void moveConstAcceleration(const float deltaTime);

	void UpdateNetForce();
	void UpdateAcceleration();

	void SetObjectMass(float objectMass) { _objectMass = objectMass; }
	float GetObjectMass() const { return _objectMass; }

	void SetNetForce(Vector3D netForce) { _netForce = netForce; }
	Vector3D GetNetForce() const { return _netForce; } 

private :

	XMFLOAT4X4 _world;

	std::vector<BaseForces*> forces;
	
	Vector3D _velocity;
	Vector3D _position;
	Vector3D _acceleration;

	Transform* _transform;

	bool _useConstVelocity;
	bool _useConstAcceleration;

	Vector3D _netForce;
	float _objectMass;

	Gravity* _gravity;
	Vector3D _gravitationalForce = _gravity->GetGravity();


};

