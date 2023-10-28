#pragma once
#include "IvyyyComponent.h"
#include "IvyyyFontMesh.h"

class AnswerButton :
	public Ivyyy::Component
{
public:
	void Start () override;

	void OnMouseDown () override;
	void OnMouseEnter () override;
	void OnMouseExit () override;

private:
	float timer{ 0.f };
	Ivyyy::FontMesh* fontMesh;
};

