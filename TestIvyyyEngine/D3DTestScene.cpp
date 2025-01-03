#include "D3DTestScene.h"
#include "IvyyyMeshRenderer.h"
#include "IvyyyMesh.h"
#include "ColorShader.h"
#include "PlayerMovement.h"
#include "IvyyyCamera.h"
#include "TextureShaderClass.h"
#include "IvyyyDirectionalLight.h"

void D3DTestScene::Init()
{
	//Parent cube
	auto parentCube = AddGameObject<GameObject>();
	auto meshRenderer = parentCube->AddComponent<MeshRenderer>();

	Mesh cube;
	cube.LoadModel("cube.txt");
	meshRenderer->SetMesh(cube);

	meshRenderer->SetShader (new TextureShaderClass);
	//meshRenderer->SetShader (new ColorShader);
	parentCube->AddComponent<PlayerMovement>();

	//Child cube
	auto childCube = AddGameObject<GameObject>(&parentCube->transform, Vector3(-10.f, 0.f, 0.f));
	meshRenderer = childCube->AddComponent<MeshRenderer>();
	meshRenderer->SetMesh(cube);
	meshRenderer->SetShader(new TextureShaderClass);

	auto childCube2 = AddGameObject<GameObject>(&childCube->transform, Vector3(0.f, -5.f, 0.f));
	meshRenderer = childCube2->AddComponent<MeshRenderer>();
	meshRenderer->SetMesh(cube);
	meshRenderer->SetShader(new TextureShaderClass);

	//Add Light
	auto light = AddGameObject<GameObject>()->AddComponent<DirectionalLight>();
	light->SetColor(Color(1.f, 0.f, 0.f, 0.5f));
}
