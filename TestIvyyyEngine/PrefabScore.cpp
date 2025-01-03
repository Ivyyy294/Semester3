#include "PrefabScore.h"
#include "Score.h"
#include "IvyyyFontMesh.h"

PrefabScore::PrefabScore ()
{
	AddComponent<FontMesh> ();
	AddComponent<Score> ();
	transform.SetSpace (Transform::Space::SCREEN);
	transform.SetPivot (Transform::Pivot::TOPLEFT);
}
