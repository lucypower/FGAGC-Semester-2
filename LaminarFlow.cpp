#include "LaminarFlow.h"

LaminarFlow::LaminarFlow(Vector3D velocity, float fluidDensity, float dragCoef, float areaRef)
{
	_velocity = velocity;

	_dragFactor = 0.5f * fluidDensity * dragCoef * areaRef;
}

Vector3D LaminarFlow::Formula()
{
	_laminar.x = -_dragFactor * _velocity.x;
	_laminar.y = -_dragFactor * _velocity.y;
	_laminar.z = -_dragFactor * _velocity.z;

	return _laminar;
}
