#pragma once
#include <IvyyyGameObject.h>
#include <IvyyyFontMesh.h>
#include "AnswerButton.h"

using namespace Ivyyy;

class PrefabButton :
    public GameObject
{
public:
	PrefabButton ();
	void SetText (const std::wstring & text) { fontMesh->text = text; };
	float GetWidth () const { return fontMesh->GetWidth (); }
private:
	AnswerButton* script;
	FontMesh* fontMesh;
};

