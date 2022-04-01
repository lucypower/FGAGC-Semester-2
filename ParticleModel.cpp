#include "ParticleModel.h"
#include <algorithm>

ParticleModel::ParticleModel(Transform* ap_transform, bool useVelocity, bool useAcceleration, float objectMass) : _transform(ap_transform), _useConstVelocity(useVelocity), _useConstAcceleration(useAcceleration), _objectMass(objectMass)
{
	_velocity = Vector3D(0.0f, 0.0f, 0.0f);
	_acceleration = Vector3D(0.0f, 1.0f, 0.0f);
	_netForce = Vector3D(0.0f, 0.0f, 0.0f);

	forces.push_back(new LaminarFlow(1.05f));
	forces.push_back(new TurbulentFlow(0.0f, 1.0f));
}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(float t)
{
	if (_useConstVelocity)
	{
		moveConstVelocity(t);
	}
	else if (_useConstAcceleration)
	{
		moveConstAcceleration(t);
	}

	UpdateAcceleration();

	_transform->SetPosition(_transform->GetPosition() + _velocity * t);
	//_transform->SetPosition(_transform->GetPosition() + _velocity * t + _acceleration * 0.5f * t * t);
	//_velocity = _velocity + _acceleration * t;

}

void ParticleModel::moveConstVelocity(const float deltaTime)
{
	_transform->SetPosition(_transform->GetPosition() + _velocity * deltaTime);
}

void ParticleModel::moveConstAcceleration(const float deltaTime)
{
	_transform->SetPosition(_transform->GetPosition() + _velocity * deltaTime + _acceleration * 0.5f * deltaTime * deltaTime);
	_velocity = _velocity + _acceleration * deltaTime;
}

void ParticleModel::UpdateNetForce()
{
	for (int i = 0; i < forces.size(); i++)
	{
		_netForce += forces[i]->Formula(_velocity);
		if (forces[i]->IsDead())
		{
			delete forces[i];
			forces[i] = nullptr; // will give an issue and is only very accurate sudo code
		}
	}

	for (int i = 0; i < forces.size(); i++)
	{
		if (forces[i] == nullptr)
		{
			forces.erase(forces.begin() + i);
			i--;
		}
	}
}

void ParticleModel::UpdateAcceleration()
{
	UpdateNetForce();

	_acceleration.x = _netForce.x / _objectMass;
	_acceleration.y = _netForce.y / _objectMass;
	_acceleration.z = _netForce.z / _objectMass;

	_netForce = Vector3D(0, 0, 0);
}

//TO DO: WATCH VIDEO ON PARTICLE SYSTEMS -> https://www.youtube.com/watch?v=GK0jHlv3e3w
