#pragma once
#include "BaseForces.h"
#include "Vector3D.h"

class Gravity : public BaseForces
{
public: 
	Gravity(float mass, float gravitationalConstant = -9.81f);

	Vector3D Formula(Vector3D input) override;

	//void SetGravity(Vector3D gravity) { _gravity = gravity; }
	Vector3D GetGravity() const { return _gravity; }

private : 

	Vector3D _gravity;
	float _mass;
	float _gravitationalConstant;
};

