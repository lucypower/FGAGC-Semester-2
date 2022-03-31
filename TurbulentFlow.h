#pragma once
#include "BaseForces.h"
#include "Vector3D.h"

class TurbulentFlow : public BaseForces
{
public :

	TurbulentFlow(Vector3D velocity, float fluidDensity, float dragCoef, float areaRef);

	Vector3D Formula();

private :

	Vector3D _velocity;
	Vector3D _turbulent;
	float _dragFactor;
	Vector3D _velocityMagnitude;

};

