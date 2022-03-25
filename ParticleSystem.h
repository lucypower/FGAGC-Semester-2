#pragma once
class ParticleSystem
{
	int NumParticles;

public :

	ParticleSystem();
	~ParticleSystem();

	void Update(const float deltaTime);
	void Draw();

};

