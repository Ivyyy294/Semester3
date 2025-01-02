#include "D3DTestScene.h"
#include "IvyyyMeshRenderer.h"
#include "IvyyyMesh.h"
#include "ColorShader.h"
#include "PlayerMovement.h"
#include "IvyyyCamera.h"
#include "TextureShaderClass.h"

void D3DTestScene::Init()
{
	auto obj = AddGameObject<GameObject>();
	auto meshRenderer = obj->AddComponent<MeshRenderer>();
	//meshRenderer->SetMesh(Mesh::Cube());
	meshRenderer->SetShader (new TextureShaderClass);
	//meshRenderer->SetShader (new ColorShader);

	obj->AddComponent<PlayerMovement>();
}
