#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>

#include "Transform.h"
#include "ParticleModel.h"
#include "Appearance.h"

using namespace DirectX;
using namespace std;


class GameObject
{
public:
	GameObject(string type, Appearance* appearance, Transform* transform, ParticleModel* particleModel);
	~GameObject();

	string GetType() const { return _type; }

	Transform* GetTransform() const { return _transform; }

	ParticleModel* GetParticleModel() const { return _particleModel; }

	Appearance* GetAppearance() const { return _appearance; }
	

	void SetParent(GameObject * parent) { _parent = parent; }

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);

private:

	string _type;

	GameObject * _parent;

	Transform* _transform;
	ParticleModel* _particleModel;
	Appearance* _appearance;
};

