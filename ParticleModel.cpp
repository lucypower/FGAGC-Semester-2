#include "ParticleModel.h"

ParticleModel::ParticleModel()
{
	_position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	_velocity = XMFLOAT3(0.0f, 0.0f, 0.0f);
	_acceleration = XMFLOAT3(0.0f, 0.0f, 0.0f);

	_netForce, _mass = 0;
}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(float t)
{
	moveConstVelocity(t);
	moveConstAcceleration(t);
}

void ParticleModel::moveConstVelocity(const float deltaTime)
{
	XMPosition = XMPosition + (XMVelocity * deltaTime);
}

void ParticleModel::moveConstAcceleration(const float deltaTime)
{	
	XMPosition = XMPosition + (XMVelocity * deltaTime) + (0.5 * XMAcceleration * deltaTime * deltaTime);

	XMVelocity = XMVelocity + (XMAcceleration * deltaTime);
}

void ParticleModel::UpdateNetForce()
{
	
}

void ParticleModel::UpdateAcceleration()
{
	_accleration.x = _netForce.x / _mass;
}