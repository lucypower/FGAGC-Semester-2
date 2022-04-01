#pragma once
#include <vector>
#include "Vector3D.h"
#include "Transform.h"
#include "Appearance.h"
#include "ParticleModel.h"

class ParticleSystem
{
public :

	ParticleSystem(Transform* transform, ParticleModel* particleModel, Appearance* appearance, float mass);
	~ParticleSystem();

	void Update(const float deltaTime);
	void Draw();

private :

	int _numParticles;
	float _mass;

	Vector3D _position;
	Vector3D _colour;
	Vector3D _velocity;

	std::vector<ParticleSystem> particles;
};

