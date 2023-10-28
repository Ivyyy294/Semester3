#include "Score.h"

void Score::Start ()
{
	fontMesh = gameObject->GetComponent <FontMesh> ();
}

void Score::Update ()
{
	fontMesh.lock()->text = L"Score: " + std::to_wstring (score);
}
