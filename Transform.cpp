#include "Transform.h"

Transform::Transform()
{
	_position = Vector3D(0.0f, 0.0f, 0.0f);
	_rotation = Vector3D(0.0f, 0.0f, 0.0f);
	_scale = Vector3D(0.0f, 0.0f, 0.0f);

	_parent = nullptr;
}

Transform::~Transform()
{

}

void Transform::Update(float t)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	XMMATRIX rotation = XMMatrixRotationX(_rotation.x) * XMMatrixRotationY(_rotation.y) * XMMatrixRotationZ(_rotation.z);
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
}