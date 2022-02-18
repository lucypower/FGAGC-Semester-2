#pragma once

#include <DirectXMath.h>

using namespace DirectX;

struct Geometry
{
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;
	int numberOfIndices;

	UINT vertexBufferStride;
	UINT vertexBufferOffset;
};

class ParticleModel
{
public :

	ParticleModel();
	~ParticleModel();

	Geometry GetGeometryData() const { return _geometry; }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

private :

	XMFLOAT4X4 _world;

	Geometry _geometry;

};

