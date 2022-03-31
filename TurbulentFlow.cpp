#include "TurbulentFlow.h"

TurbulentFlow::TurbulentFlow(Vector3D velocity, float fluidDensity, float dragCoef, float areaRef)
{
	_velocity = velocity;

	_dragFactor = 0.5f * fluidDensity * dragCoef * areaRef;

}

Vector3D TurbulentFlow::Formula()
{

	_turbulent.x = -_dragFactor * _velocity.square();

	return _turbulent;
}

// TODO: Finish formula here
