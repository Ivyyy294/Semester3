#include "PrefabScore.h"
#include "Score.h"
#include "IvyyyFontMesh.h"

PrefabScore::PrefabScore ()
{
	AddComponent<FontMesh> ();
	AddComponent<Score> ();
	transform.SetSpace (Transform2D::Space::SCREEN);
	transform.SetPivot (Transform2D::Pivot::TOPLEFT);
}
