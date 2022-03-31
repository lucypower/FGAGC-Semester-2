#pragma once
#include "BaseForces.h"
#include "Vector3D.h"

class LaminarFlow : public BaseForces // used for slow relative object motion
{
public :

	LaminarFlow(Vector3D velocity, float fluidDensity, float dragCoef, float areaRef);

	Vector3D Formula() override;

	Vector3D GetLaminar() const { return _laminar; }

private:

	Vector3D _velocity;

	float _dragFactor;
	Vector3D _laminar;

};

