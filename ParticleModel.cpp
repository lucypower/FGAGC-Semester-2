#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* ap_transform, bool useVelocity, bool useAcceleration)
{
	_transform = ap_transform; 
	
	_velocity = Vector3D(0.0f, 0.0f, 0.0f);
	_acceleration = Vector3D(0.0f, 1.0f, 0.0f);

	_useConstVelocity = useVelocity;
	_useConstAcceleration = useAcceleration;
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


}

void ParticleModel::moveConstVelocity(const float deltaTime)
{
	_position = _transform->GetPosition();

	_position = _position + _velocity * deltaTime;

	_transform->SetPosition(_position);
}

void ParticleModel::moveConstAcceleration(const float deltaTime)
{
	_position = _transform->GetPosition();

	_position = _position + _velocity * deltaTime + _acceleration * 0.5f * deltaTime * deltaTime;
	_velocity = _velocity + _acceleration * deltaTime;

	_transform->SetPosition(_position);
}

void ParticleModel::UpdateNetForce()
{
	
}

void ParticleModel::UpdateAcceleration()
{

}