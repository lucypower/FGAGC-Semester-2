#pragma once
#include "BaseForces.h"
#include "Vector3D.h"

class TurbulentFlow : public BaseForces
{
public :

	TurbulentFlow(float fluidDensity, float areaRef);

	Vector3D Formula(Vector3D velocity) override;

private :

	Vector3D _velocity;
	Vector3D _turbulent;

	float _dragFactor;
};

