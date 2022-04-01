#pragma once
#include "BaseForces.h"
#include "Vector3D.h"

class LaminarFlow : public BaseForces // used for slow relative object motion
{
public :

	LaminarFlow(float dragCoef);

	Vector3D Formula(Vector3D velocity) override;

	Vector3D GetLaminar() const { return _laminar; }

private:

	Vector3D _velocity;

	float _dragCoef;
	Vector3D _laminar;

};

