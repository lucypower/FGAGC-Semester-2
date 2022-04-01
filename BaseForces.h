#pragma once
#include "Vector3D.h"

class BaseForces
{
public :

	virtual Vector3D Formula(Vector3D velocity) = 0;

//formula function  pure virtual =0;
	// declare formula etc

	// vector3d

	// lifetime thing so they dissappear after a certain amount of time or something like that

	bool IsDead();

private:

	bool _IsDead = false;
};

