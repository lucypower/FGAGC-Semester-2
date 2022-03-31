#include "Gravity.h"

Gravity::Gravity(float mass, float gravitationalConstant)
{
	_mass = mass;
	gravitationalConstant = gravitationalConstant;
}

Vector3D Gravity::Formula()
{
	_gravity.x = 0;
	_gravity.y = _mass * gravitationalConstant;
	_gravity.z = 0; 

	return _gravity;
}