#pragma once
#include <IvyyyComponent.h>
#include <IvyyyFontMesh.h>

using namespace Ivyyy;

class DebugInfo :
    public Component
{
public:
	virtual void Start () override;
	virtual void Update () override;

private:
	int tmpFps{ 0 };
	int fps{ 0 };
	float deltatime;
	float timer{ 0.f };

	int m_colliderCount{ 0 };
	int m_meshCount{ 0 };

	FontMesh* fontmesh;

	void UpdateFps();
	void UpdateColliderCount();
};

