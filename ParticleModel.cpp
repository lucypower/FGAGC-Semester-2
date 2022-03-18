#include "ParticleModel.h"

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

//TODO: Possible solution
//base force class,  abstract class, -> thrust, gravity, friction, teurbular flow, laminar flow ect.

//in partcicle model
//- std::vector<baseforces> forces; loop though each in update net force to calculate and combine the results into one net force.

	
}

void ParticleModel::UpdateAcceleration()
{
	_acceleration.x = _netForce.x / _objectMass;
	_acceleration.y = _netForce.y / _objectMass;
	_acceleration.z = _netForce.z / _objectMass;
}

//TO DO: WATCH VIDEO ON PARTICLE SYSTEMS -> https://www.youtube.com/watch?v=GK0jHlv3e3w