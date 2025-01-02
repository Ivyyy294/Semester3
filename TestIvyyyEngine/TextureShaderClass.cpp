#include "TextureShaderClass.h"
#include <d3dcompiler.h>
#include <fstream>

using namespace std;
using namespace Ivyyy;

TextureShaderClass::TextureShaderClass()
	: Shader(L"TextureVS.hlsl", L"TexturePS.hlsl")
{
}

bool TextureShaderClass::InitializeShader(const D3DShaderRenderData& shaderData, ID3D10Blob* vertexShaderBuffer, ID3D10Blob* pixelShaderBuffer)
{
	HRESULT result;
	ID3D10Blob* errorMessage;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[3];
	unsigned int numElements;
	D3D11_BUFFER_DESC lightBufferDesc;

	// Initialize the pointers this function will use to null.
	errorMessage = 0;

	// Create the vertex input layout description.
	// This setup needs to match the VertexType stucture in the ModelClass and in the shader.
	polygonLayout[0].SemanticName = "POSITION";
	polygonLayout[0].SemanticIndex = 0;
	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[0].InputSlot = 0;
	polygonLayout[0].AlignedByteOffset = 0;
	polygonLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[0].InstanceDataStepRate = 0;

	polygonLayout[1].SemanticName = "TEXCOORD";
	polygonLayout[1].SemanticIndex = 0;
	polygonLayout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	polygonLayout[1].InputSlot = 0;
	polygonLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[1].InstanceDataStepRate = 0;

	polygonLayout[2].SemanticName = "NORMAL";
	polygonLayout[2].SemanticIndex = 0;
	polygonLayout[2].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[2].InputSlot = 0;
	polygonLayout[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[2].InstanceDataStepRate = 0;

	// Get a count of the elements in the layout.
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	// Create the vertex input layout.
	result = shaderData.m_device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(),
		vertexShaderBuffer->GetBufferSize(), &m_layout);
	if (FAILED(result))
	{
		return false;
	}

	D3D11_BUFFER_DESC matrixBufferDesc;

	// Setup the description of the dynamic matrix constant buffer that is in the vertex shader.
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBufferType);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	// Create the constant buffer pointer so we can access the vertex shader constant buffer from within this class.
	result = shaderData.m_device->CreateBuffer(&matrixBufferDesc, NULL, &m_matrixBuffer);
	if (FAILED(result))
	{
		return false;
	}

	char textureFilename[128];
	strcpy_s(textureFilename, "stone01.tga");
	
	// Initialize the vertex and pixel shaders.
	result = LoadTexture(shaderData.m_device, shaderData.m_deviceContext, textureFilename);

	if (FAILED(result))
	{
		return false;
	}

	D3D11_SAMPLER_DESC samplerDesc;
	// Create a texture sampler state description.
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	// Create the texture sampler state.
	result = shaderData.m_device->CreateSamplerState(&samplerDesc, &m_sampleState);
	if (FAILED(result))
	{
		return false;
	}

	// Setup the description of the light dynamic constant buffer that is in the pixel shader.
	// Note that ByteWidth always needs to be a multiple of 16 if using D3D11_BIND_CONSTANT_BUFFER or CreateBuffer will fail.
	lightBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	lightBufferDesc.ByteWidth = sizeof(LightBufferType);
	lightBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	lightBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	lightBufferDesc.MiscFlags = 0;
	lightBufferDesc.StructureByteStride = 0;

	// Create the constant buffer pointer so we can access the vertex shader constant buffer from within this class.
	result = shaderData.m_device->CreateBuffer(&lightBufferDesc, NULL, &m_lightBuffer);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

bool TextureShaderClass::InitializeVertexBuffer(ID3D11Device* device, Mesh* mesh)
{
	VertexType* shaderData;
	D3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData;
	HRESULT result;

	const Vector3* vertices = mesh->GetVertices();
	int vertexCount = mesh->GetVertexCount();

	// Create the vertex array.
	shaderData = new VertexType[vertexCount];
	if (!shaderData)
	{
		return false;
	}

	const Vector2* uv = mesh->GetUV();

	for (int i = 0; i < vertexCount; ++i)
	{
		shaderData[i].position = XMFLOAT3(vertices[i].x, vertices[i].y, vertices[i].z);
		shaderData[i].uv = XMFLOAT2(uv[i].x, uv[i].y);
	}

	// Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = shaderData;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

unsigned int TextureShaderClass::GetVertexBufferStride()
{
	return sizeof(VertexType);
}

bool TextureShaderClass::SetShaderParameters(const D3DShaderRenderData& shaderData)
{
	HRESULT result;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	MatrixBufferType* dataPtr;
	unsigned int bufferNumber;

	// Transpose the matrices to prepare them for the shader.
	XMMATRIX worldMatrix = XMMatrixTranspose(shaderData.m_worldMatrix);
	XMMATRIX viewMatrix = XMMatrixTranspose(shaderData.m_viewMatrix);
	XMMATRIX projectionMatrix = XMMatrixTranspose(shaderData.m_projectionMatrix);

	// Lock the constant buffer so it can be written to.
	result = shaderData.m_deviceContext->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
	{
		return false;
	}

	// Get a pointer to the data in the constant buffer.
	dataPtr = (MatrixBufferType*)mappedResource.pData;

	// Copy the matrices into the constant buffer.
	dataPtr->world = worldMatrix;
	dataPtr->view = viewMatrix;
	dataPtr->projection = projectionMatrix;

	// Unlock the constant buffer.
	shaderData.m_deviceContext->Unmap(m_matrixBuffer, 0);

	// Set the position of the constant buffer in the vertex shader.
	bufferNumber = 0;

	// Finanly set the constant buffer in the vertex shader with the updated values.
	ID3D11Buffer* matrix = m_matrixBuffer;
	shaderData.m_deviceContext->VSSetConstantBuffers(bufferNumber, 1, &matrix);

	// Set shader texture resource in the pixel shader.
	shaderData.m_deviceContext->PSSetShaderResources(0, 1, &m_srv);

	// Set the sampler state in the pixel shader.
	shaderData.m_deviceContext->PSSetSamplers(0, 1, &m_sampleState);

	return true;
}

void Ivyyy::TextureShaderClass::ShutdownShader()
{
	Shader::ShutdownShader();

	// Release the sampler state.
	if (m_sampleState)
	{
		m_sampleState->Release();
		m_sampleState = 0;
	}

	// Release the texture object.
	if (m_texture)
	{
		m_texture->Shutdown();
		delete m_texture;
		m_texture = 0;
	}

}

//TextureShaderClass::TextureShaderClass ()
//	: Shader (L"TextureVS.hlsl", L"TexturePS.hlsl")
//{
//	m_vertexShader = 0;
//	m_pixelShader = 0;
//	m_layout = 0;
//	m_matrixBuffer = 0;
//	m_sampleState = 0;
//}
//
//TextureShaderClass::TextureShaderClass (const TextureShaderClass& other)
//	: Shader (L"TextureVS.hlsl", L"TexturePS.hlsl")
//{
//}
//
//TextureShaderClass::~TextureShaderClass ()
//{
//}
//
//bool TextureShaderClass::Initialize (const D3DShaderRenderData& shaderData)
//{
//	bool result;
//
//	char textureFilename[128];
//	strcpy_s(textureFilename, "stone01.tga");
//
//	// Initialize the vertex and pixel shaders.
//	result = LoadTexture(shaderData.m_device, shaderData.m_deviceContext, textureFilename)
//		&& InitializeVertexBuffer(shaderData.m_device, shaderData.m_mesh)
//		&& InitializeShader(shaderData.m_device, shaderData.m_hwnd, m_vsFilename, m_psFilename);
//
//	if (!result)
//	{
//		return false;
//	}
//
//	return true;
//}
//
//bool TextureShaderClass::Render (const D3DShaderRenderData& shaderData)
//{
//	bool result;
//
//	// Set the shader parameters that it will use for rendering.
//	result = SetShaderParameters(shaderData);
//	if (!result)
//	{
//		return false;
//	}
//
//	// Now render the prepared buffers with the shader.
//	RenderShader(shaderData.m_deviceContext, shaderData.m_mesh->GetIndexCount());
//
//	return true;
//}
//
//bool TextureShaderClass::InitializeShader(ID3D11Device* device, HWND hwnd, WCHAR* vsFilename, WCHAR* psFilename)
//{
//	HRESULT result;
//	ID3D10Blob* errorMessage;
//	ID3D10Blob* vertexShaderBuffer;
//	ID3D10Blob* pixelShaderBuffer;
//	D3D11_INPUT_ELEMENT_DESC polygonLayout[2];
//	unsigned int numElements;
//	D3D11_BUFFER_DESC matrixBufferDesc;
//
//	D3D11_SAMPLER_DESC samplerDesc;
//
//	// Initialize the pointers this function will use to null.
//	errorMessage = 0;
//	vertexShaderBuffer = 0;
//	pixelShaderBuffer = 0;
//
//	// Compile the vertex shader code.
//	result = D3DCompileFromFile(vsFilename, NULL, NULL, "TextureVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0,
//		&vertexShaderBuffer, &errorMessage);
//	if (FAILED(result))
//	{
//		// If the shader failed to compile it should have writen something to the error message.
//		if (errorMessage)
//		{
//			OutputShaderErrorMessage(errorMessage, hwnd, vsFilename);
//		}
//		// If there was nothing in the error message then it simply could not find the shader file itself.
//		else
//		{
//			MessageBox(hwnd, vsFilename, L"Missing Shader File", MB_OK);
//		}
//
//		return false;
//	}
//
//	// Compile the pixel shader code.
//	result = D3DCompileFromFile(psFilename, NULL, NULL, "TexturePixelShader", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0,
//		&pixelShaderBuffer, &errorMessage);
//	if (FAILED(result))
//	{
//		// If the shader failed to compile it should have writen something to the error message.
//		if (errorMessage)
//		{
//			OutputShaderErrorMessage(errorMessage, hwnd, psFilename);
//		}
//		// If there was nothing in the error message then it simply could not find the file itself.
//		else
//		{
//			MessageBox(hwnd, psFilename, L"Missing Shader File", MB_OK);
//		}
//
//		return false;
//	}
//
//	// Create the vertex shader from the buffer.
//	result = device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), NULL, &m_vertexShader);
//	if (FAILED(result))
//	{
//		return false;
//	}
//
//	// Create the pixel shader from the buffer.
//	result = device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), NULL, &m_pixelShader);
//	if (FAILED(result))
//	{
//		return false;
//	}
//
//	// Create the vertex input layout description.
//	// This setup needs to match the VertexType stucture in the ModelClass and in the shader.
//	polygonLayout[0].SemanticName = "POSITION";
//	polygonLayout[0].SemanticIndex = 0;
//	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
//	polygonLayout[0].InputSlot = 0;
//	polygonLayout[0].AlignedByteOffset = 0;
//	polygonLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
//	polygonLayout[0].InstanceDataStepRate = 0;
//
//	polygonLayout[1].SemanticName = "TEXCOORD";
//	polygonLayout[1].SemanticIndex = 0;
//	polygonLayout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
//	polygonLayout[1].InputSlot = 0;
//	polygonLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
//	polygonLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
//	polygonLayout[1].InstanceDataStepRate = 0;
//
//	// Get a count of the elements in the layout.
//	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);
//
//	// Create the vertex input layout.
//	result = device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(),
//		vertexShaderBuffer->GetBufferSize(), &m_layout);
//	if (FAILED(result))
//	{
//		return false;
//	}
//
//	// Release the vertex shader buffer and pixel shader buffer since they are no longer needed.
//	vertexShaderBuffer->Release();
//	vertexShaderBuffer = 0;
//
//	pixelShaderBuffer->Release();
//	pixelShaderBuffer = 0;
//
//	// Setup the description of the dynamic matrix constant buffer that is in the vertex shader.
//	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
//	matrixBufferDesc.ByteWidth = sizeof(MatrixBufferType);
//	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
//	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
//	matrixBufferDesc.MiscFlags = 0;
//	matrixBufferDesc.StructureByteStride = 0;
//
//	// Create the constant buffer pointer so we can access the vertex shader constant buffer from within this class.
//	result = device->CreateBuffer(&matrixBufferDesc, NULL, &m_matrixBuffer);
//	if (FAILED(result))
//	{
//		return false;
//	}
//
//	// Create a texture sampler state description.
//	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
//	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
//	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
//	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
//	samplerDesc.MipLODBias = 0.0f;
//	samplerDesc.MaxAnisotropy = 1;
//	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
//	samplerDesc.BorderColor[0] = 0;
//	samplerDesc.BorderColor[1] = 0;
//	samplerDesc.BorderColor[2] = 0;
//	samplerDesc.BorderColor[3] = 0;
//	samplerDesc.MinLOD = 0;
//	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
//
//	// Create the texture sampler state.
//	result = device->CreateSamplerState(&samplerDesc, &m_sampleState);
//	if (FAILED(result))
//	{
//		return false;
//	}
//
//	return true;
//}
//
//void TextureShaderClass::ShutdownShader()
//{
//	ReleaseTexture();
//
//	// Release the sampler state.
//	if (m_sampleState)
//	{
//		m_sampleState->Release();
//		m_sampleState = 0;
//	}
//
//	// Release the matrix constant buffer.
//	if (m_matrixBuffer)
//	{
//		m_matrixBuffer->Release();
//		m_matrixBuffer = 0;
//	}
//
//	// Release the layout.
//	if (m_layout)
//	{
//		m_layout->Release();
//		m_layout = 0;
//	}
//
//	// Release the pixel shader.
//	if (m_pixelShader)
//	{
//		m_pixelShader->Release();
//		m_pixelShader = 0;
//	}
//
//	// Release the vertex shader.
//	if (m_vertexShader)
//	{
//		m_vertexShader->Release();
//		m_vertexShader = 0;
//	}
//
//	return;
//}
//
//bool Ivyyy::TextureShaderClass::SetShaderParameters(const D3DShaderRenderData& shaderData)
//{
//	HRESULT result;
//	D3D11_MAPPED_SUBRESOURCE mappedResource;
//	MatrixBufferType* dataPtr;
//	unsigned int bufferNumber;
//
//	// Transpose the matrices to prepare them for the shader.
//	XMMATRIX worldMatrix = XMMatrixTranspose(shaderData.m_worldMatrix);
//	XMMATRIX viewMatrix = XMMatrixTranspose(shaderData.m_viewMatrix);
//	XMMATRIX projectionMatrix = XMMatrixTranspose(shaderData.m_projectionMatrix);
//
//	// Lock the constant buffer so it can be written to.
//	result = shaderData.m_deviceContext->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
//	if (FAILED(result))
//	{
//		return false;
//	}
//
//	// Get a pointer to the data in the constant buffer.
//	dataPtr = (MatrixBufferType*)mappedResource.pData;
//
//	// Copy the matrices into the constant buffer.
//	dataPtr->world = worldMatrix;
//	dataPtr->view = viewMatrix;
//	dataPtr->projection = projectionMatrix;
//
//	// Unlock the constant buffer.
//	shaderData.m_deviceContext->Unmap(m_matrixBuffer, 0);
//
//	// Set the position of the constant buffer in the vertex shader.
//	bufferNumber = 0;
//
//	// Finanly set the constant buffer in the vertex shader with the updated values.
//	shaderData.m_deviceContext->VSSetConstantBuffers(bufferNumber, 1, &m_matrixBuffer);
//
//	// Set shader texture resource in the pixel shader.
//	ID3D11ShaderResourceView* srv = m_texture->GetTexture();
//	shaderData.m_deviceContext->PSSetShaderResources(0, 1, &srv);
//
//	return true;
//}
//
//void TextureShaderClass::RenderShader(ID3D11DeviceContext* deviceContext, int indexCount)
//{
//	// Set the vertex input layout.
//	deviceContext->IASetInputLayout(m_layout);
//
//	// Set the vertex and pixel shaders that will be used to render this triangle.
//	deviceContext->VSSetShader(m_vertexShader, NULL, 0);
//	deviceContext->PSSetShader(m_pixelShader, NULL, 0);
//
//	// Set the sampler state in the pixel shader.
//	deviceContext->PSSetSamplers(0, 1, &m_sampleState);
//
//	// Render the triangle.
//	deviceContext->DrawIndexed(indexCount, 0, 0);
//
//	return;
//}

bool Ivyyy::TextureShaderClass::LoadTexture(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* filename)
{
	bool result;

	// Create and initialize the texture object.
	m_texture = new Texture;

	result = m_texture->Initialize(device, deviceContext, filename);
	if (!result)
	{
		return false;
	}

	m_srv = m_texture->GetTexture();

	return true;
}

void Ivyyy::TextureShaderClass::ReleaseTexture()
{
	// Release the texture object.
	if (m_texture)
	{
		m_texture->Shutdown();
		delete m_texture;
		m_texture = 0;
	}

	return;
}

//bool Ivyyy::TextureShaderClass::InitializeVertexBuffer(ID3D11Device* device, Mesh* mesh)
//{
//	VertexType* shaderData;
//	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
//	D3D11_SUBRESOURCE_DATA vertexData, indexData;
//	HRESULT result;
//
//	const Vector3* vertices = mesh->GetVertices();
//	int vertexCount = mesh->GetVertexCount();
//	const Vector2* uvs = mesh->GetUV();
//
//	// Create the vertex array.
//	shaderData = new VertexType[vertexCount];
//	if (!shaderData)
//	{
//		return false;
//	}
//
//	for (int i = 0; i < vertexCount; ++i)
//	{
//		shaderData[i].position = XMFLOAT3(vertices[i].x, vertices[i].y, vertices[i].z);
//		shaderData[i].texture = XMFLOAT2 (uvs[i].x, uvs[i].y);
//	}
//
//	// Set up the description of the static vertex buffer.
//	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
//	vertexBufferDesc.ByteWidth = sizeof(VertexType) * vertexCount;
//	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//	vertexBufferDesc.CPUAccessFlags = 0;
//	vertexBufferDesc.MiscFlags = 0;
//	vertexBufferDesc.StructureByteStride = 0;
//
//	// Give the subresource structure a pointer to the vertex data.
//	vertexData.pSysMem = shaderData;
//	vertexData.SysMemPitch = 0;
//	vertexData.SysMemSlicePitch = 0;
//
//	// Now create the vertex buffer.
//	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
//	if (FAILED(result))
//	{
//		return false;
//	}
//
//	unsigned long* indices = mesh->GetIndices();
//	size_t indexCount = mesh->GetIndexCount();
//
//	// Set up the description of the static index buffer.
//	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
//	indexBufferDesc.ByteWidth = sizeof(unsigned long) * indexCount;
//	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
//	indexBufferDesc.CPUAccessFlags = 0;
//	indexBufferDesc.MiscFlags = 0;
//	indexBufferDesc.StructureByteStride = 0;
//
//	// Give the subresource structure a pointer to the index data.
//	indexData.pSysMem = indices;
//	indexData.SysMemPitch = 0;
//	indexData.SysMemSlicePitch = 0;
//
//	// Create the index buffer.
//	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
//	if (FAILED(result))
//	{
//		return false;
//	}
//
//	return true;
//}
//
//bool Ivyyy::TextureShaderClass::InitializeShader(ID3D11Device* device, HWND hwnd, ID3D10Blob* vertexShaderBuffer, ID3D10Blob* pixelShaderBuffer)
//{
//	return false;
//}
//
//unsigned int Ivyyy::TextureShaderClass::GetVertexBufferStride()
//{
//	return 0;
//}