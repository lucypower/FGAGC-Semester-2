#include "ParticleModel.h"

ParticleModel::ParticleModel()
{

}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update()
{
	moveConstVelocity();
}

void ParticleModel::moveConstVelocity(const float deltaTime)
{
	_position = _position + (_velocity * deltaTime);
}

void ParticleModel::moveConstAcceleration(const float deltaTime)
{
	_position = _position + _velocity * deltaTime + 0.5 * _acceleration * time * time;
}