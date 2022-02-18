#pragma once

#include <DirectXMath.h>

using namespace DirectX;

struct Material
{
	XMFLOAT4 diffuse;
	XMFLOAT4 ambient;
	XMFLOAT4 specular;
	float specularPower;
};

class Appearance
{
public :

	Appearance();
	~Appearance();

	void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

	Material GetMaterial() const { return _material; }

private :

	Material _material;

	ID3D11ShaderResourceView* _textureRV;
};

