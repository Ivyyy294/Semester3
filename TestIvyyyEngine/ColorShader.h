#pragma once

#include "IvyyyShader.h"

using namespace Ivyyy;

class ColorShader : public Shader
{
public:
	ColorShader();

protected:
	bool InitializeShader(const D3DShaderRenderData& shaderData, ID3D10Blob* vertexShaderBuffer, ID3D10Blob* pixelShaderBuffer) override;
	bool InitializeVertexBuffer(ID3D11Device* device, Mesh* mesh) override;
	unsigned int GetVertexBufferStride() override;
	bool SetShaderParameters (const D3DShaderRenderData& shaderData) override;

private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};

	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};
};

