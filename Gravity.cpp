#include "Gravity.h"

Gravity::Gravity(float mass, float GravitationalConstant = -9.81f)
{
	_mass = mass;
	gravitationalConstant = GravitationalConstant;
}

Vector3D Gravity::Formula()
{
	_gravity.x = 0;
	_gravity.y = _mass * -9.81;
	_gravity.z = 0; 

	return _gravity;
}