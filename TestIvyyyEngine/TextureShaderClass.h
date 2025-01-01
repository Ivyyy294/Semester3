#pragma once

#include "IvyyyShader.h"
#include "IvyyyTexture.h"

namespace Ivyyy
{
	class TextureShaderClass : public Shader
	{
	public:
		TextureShaderClass();

	protected:
		bool InitializeShader(const D3DShaderRenderData& shaderData, ID3D10Blob* vertexShaderBuffer, ID3D10Blob* pixelShaderBuffer) override;
		bool InitializeVertexBuffer(ID3D11Device* device, Mesh* mesh) override;
		unsigned int GetVertexBufferStride() override;
		bool SetShaderParameters(const D3DShaderRenderData& shaderData) override;

	private:
		Texture* m_texture;
		ID3D11ShaderResourceView* m_srv;
		ID3D11SamplerState* m_sampleState;

		bool LoadTexture(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename);
		void ReleaseTexture();

		struct VertexType
		{
			XMFLOAT3 position;
			XMFLOAT2 uv;
		};

		struct MatrixBufferType
		{
			XMMATRIX world;
			XMMATRIX view;
			XMMATRIX projection;
		};
	};

	//class TextureShaderClass : public Shader
	//{
	//	//variables
	//private:
	//	struct MatrixBufferType
	//	{
	//		XMMATRIX world;
	//		XMMATRIX view;
	//		XMMATRIX projection;
	//	};

	//	struct VertexType
	//	{
	//		XMFLOAT3 position;
	//		XMFLOAT2 texture;
	//	};

	//	ID3D11SamplerState* m_sampleState;
	//	Texture* m_texture;

	//	//Methods
	//public:
	//	TextureShaderClass ();
	//	TextureShaderClass(const TextureShaderClass&);
	//	~TextureShaderClass();

	//	bool Initialize (const D3DShaderRenderData& shaderData) override;
	//	bool Render (const D3DShaderRenderData& shaderData) override;

	//private:
	//	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	//	void ShutdownShader();
	//	bool SetShaderParameters(const D3DShaderRenderData& shaderData) override;
	//	void RenderShader(ID3D11DeviceContext*, int);

	//	bool LoadTexture(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename);
	//	void ReleaseTexture();

	//	// Inherited via Shader
	//	bool InitializeVertexBuffer(ID3D11Device* device, Mesh* mesh) override;
	//	bool InitializeShader(ID3D11Device* device, HWND hwnd, ID3D10Blob* vertexShaderBuffer, ID3D10Blob* pixelShaderBuffer) override;
	//	unsigned int GetVertexBufferStride() override;
	//};

}
