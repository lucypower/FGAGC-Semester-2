#include "ParticleModel.h"
#include <algorithm>

ParticleModel::ParticleModel(Transform* ap_transform, bool useVelocity, bool useAcceleration, float objectMass, Vector3D netForce)
{
	_transform = ap_transform; 

	_objectMass = objectMass;
	_netForce = netForce;
	
	_velocity = Vector3D(0.0f, 0.0f, 0.0f);
	_acceleration = Vector3D(0.0f, 1.0f, 0.0f);

	_useConstVelocity = useVelocity;
	_useConstAcceleration = useAcceleration;

}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(float t)
{
	if (_useConstVelocity)
	{
		moveConstVelocity(t);
	}
	else if (_useConstAcceleration)
	{
		moveConstAcceleration(t);
	}

	UpdateAcceleration();

}

void ParticleModel::moveConstVelocity(const float deltaTime)
{
	_position = _transform->GetPosition();

	_position = _position + _velocity * deltaTime;

	_transform->SetPosition(_position);
}

void ParticleModel::moveConstAcceleration(const float deltaTime)
{
	_position = _transform->GetPosition();

	_position = _position + _velocity * deltaTime + _acceleration * 0.5f * deltaTime * deltaTime;
	_velocity = _velocity + _acceleration * deltaTime;

	_transform->SetPosition(_position);
}

void ParticleModel::UpdateNetForce()
{
	_netForce = Vector3D(0, 0, 0);

	forces.push_back(new Gravity(5.0f));
	
	for (int i = 0; i < forces.size(); i++)
	{
		_netForce += forces[i]->Formula();
		if (forces[i]->IsDead())
		{
			delete forces[i];
			forces[i] = nullptr; // will give an issue and is only very accurate sudo code
		}
	}

	for (int i = 0; i < forces.size(); i++)
	{
		if (forces[i] == nullptr)
			forces.erase(forces.begin() + i);
	}

	/*_netForce.x += _gravitationalForce.x;
	_netForce.y += _gravitationalForce.y;
	_netForce.z += _gravitationalForce.z;*/


//TODO: Possible solution
//base force class,  abstract class, -> thrust, gravity, friction, teurbular flow, laminar flow ect.

//TODO: If all working correctly, move into vector array and iterate through with a for each loop

//in partcicle model
//- std::vector<baseforces> forces; loop though each in update net force to calculate and combine the results into one net force.	
}

void ParticleModel::UpdateAcceleration()
{
	UpdateNetForce();

	_acceleration.x = _netForce.x / _objectMass;
	_acceleration.y = _netForce.y / _objectMass;
	_acceleration.z = _netForce.z / _objectMass;
}

//TO DO: WATCH VIDEO ON PARTICLE SYSTEMS -> https://www.youtube.com/watch?v=GK0jHlv3e3w
