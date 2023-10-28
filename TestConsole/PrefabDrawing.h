#pragma once
#include <IvyyyGameObject.h>
#include <IvyyyFontMesh.h>

using namespace Ivyyy;

class PrefabDrawing :
    public GameObject
{
public:
	PrefabDrawing ();
	void SetDrawing (const std::wstring& drawing);

protected:
	FontMesh* fontMesh;
};

