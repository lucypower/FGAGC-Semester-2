#pragma once

#include <DirectXMath.h>
#include <d3d11_1.h>

using namespace DirectX;

struct Material
{
	XMFLOAT4 diffuse;
	XMFLOAT4 ambient;
	XMFLOAT4 specular;
	float specularPower;
};

struct Geometry
{
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;
	int numberOfIndices;

	UINT vertexBufferStride;
	UINT vertexBufferOffset;
};

class Appearance
{
public :

	Appearance(Geometry* geometry, Material* material);
	~Appearance();

	void Draw(ID3D11DeviceContext* pImmediateContext);

	void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

	Material* GetMaterial() const { return _material; }

	Geometry* GetGeometryData() const { return _geometry; }

private :

	Material* _material;

	Geometry* _geometry;

	ID3D11ShaderResourceView* _textureRV;
};

