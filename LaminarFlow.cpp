#include "LaminarFlow.h"

LaminarFlow::LaminarFlow(float dragCoef)
{
	_dragCoef = dragCoef;
}

Vector3D LaminarFlow::Formula(Vector3D velocity)
{
	_laminar.x = -_dragCoef * velocity.x;
	_laminar.y = -_dragCoef * velocity.y;
	_laminar.z = -_dragCoef * velocity.z;

	return _laminar;
}
