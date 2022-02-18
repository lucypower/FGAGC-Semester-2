#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance, Transform* transform, ParticleModel* particleModel) : _appearance(appearance), _transform(transform), _type(type), _particleModel(particleModel)
{
	_parent = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	_transform->Update(t);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
