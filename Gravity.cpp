#include "Gravity.h"

Gravity::Gravity(float mass, float gravitationalConstant)
{
	_mass = mass;
	_gravitationalConstant = gravitationalConstant;
}

Vector3D Gravity::Formula(Vector3D input)
{
	_gravity.x = 0;
	_gravity.y = _mass * _gravitationalConstant;
	_gravity.z = 0; 

	return _gravity;
}