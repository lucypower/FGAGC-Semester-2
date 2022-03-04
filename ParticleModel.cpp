#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* _transform)
{
	_position = _transform->GetPosition(); 
	_velocity = XMFLOAT3(0.0f, 0.0f, 0.0f);
	_acceleration = XMFLOAT3(0.0f, 1.0f, 0.0f);
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
	
	XMPosition = XMLoadFloat3(&_position);
	XMVelocity = XMLoadFloat3(&_velocity);

	XMPosition = XMPosition + (XMVelocity * deltaTime) + (0.5 * XMLoadFloat3(&_acceleration) * deltaTime * deltaTime);
	XMVelocity = XMVelocity + (XMLoadFloat3(&_acceleration) * deltaTime);

	XMStoreFloat3(&_position, XMPosition);
	XMStoreFloat3(&_velocity, XMVelocity);
}

void ParticleModel::UpdateNetForce()
{
	
}

void ParticleModel::UpdateAcceleration()
{

}