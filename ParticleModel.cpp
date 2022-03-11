#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* _transform)
{
	_position = _transform->GetPosition(); 
	_velocity = Vector3D(0.0f, 0.0f, 0.0f);
	_acceleration = Vector3D(0.0f, 1.0f, 0.0f);
}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(float t)
{
	
}

void ParticleModel::moveConstVelocity(const float deltaTime)
{
	_position = _position + (_velocity * deltaTime);
}

void ParticleModel::moveConstAcceleration(const float deltaTime)
{

	_position = _position + (_velocity * deltaTime) + (_acceleration * 0.5f) * deltaTime * deltaTime;
	_velocity = _velocity + (_acceleration * deltaTime);

}

void ParticleModel::UpdateNetForce()
{
	
}

void ParticleModel::UpdateAcceleration()
{

}