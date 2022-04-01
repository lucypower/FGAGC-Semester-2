#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Transform* transform, ParticleModel* particleModel, Appearance* appearance, float mass) : _mass(mass)
{
	_position = transform->GetPosition();
	_velocity = particleModel->GetVelocity();
	//_colour = appearance->GetMaterial();
}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::Update(const float deltaTime)
{

}

void ParticleSystem::Draw()
{

}