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
	inline void SetText (const std::wstring& text) { fontMesh->text = text; };
	inline void SetEvent (const std::string& event) { script->SetEvent (event); };
	inline float GetWidth () const { return fontMesh->GetWidth (); };
private:
	AnswerButton* script;
	FontMesh* fontMesh;
};