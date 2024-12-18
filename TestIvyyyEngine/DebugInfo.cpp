#include "DebugInfo.h"
#include <IvyyyTime.h>

void DebugInfo::Start ()
{
	fontmesh = gameObject->GetComponent<FontMesh> ().get ();
}

void DebugInfo::Update ()
{
	UpdateFps();

	if (fontmesh != nullptr)
		fontmesh->text = L"FPS: " + std::to_wstring (fps) + L"\nDeltaTIme: " + std::to_wstring (deltatime);
}

void DebugInfo::UpdateFps()
{
	deltatime = Time::DeltaTime ();

	if (timer <= 1.f)
	{
		timer += deltatime;
		tmpFps++;
	}
	else
	{
		timer = 0.f;
		fps = tmpFps;
		tmpFps = 0;
	}
}
