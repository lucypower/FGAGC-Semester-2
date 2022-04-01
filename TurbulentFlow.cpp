#include "TurbulentFlow.h"

TurbulentFlow::TurbulentFlow(float fluidDensity, float areaRef)
{
	_dragFactor = 0.5f * fluidDensity * areaRef;
}

Vector3D TurbulentFlow::Formula(Vector3D velocity)
{
	_turbulent.x = -_dragFactor * velocity.x * velocity.x;
	_turbulent.y = -_dragFactor * velocity.y * velocity.y;
	_turbulent.z = -_dragFactor * velocity.z * velocity.z;

	return _turbulent;
}

