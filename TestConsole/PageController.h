#pragma once

#include "IvyyyComponent.h"
#include "ButtonController.h"
#include "PrefabDrawing.h"

using namespace Ivyyy;

class PageController : public Component
{
public:
	void Start () override;

	PrefabDrawing* prefabDrawing {nullptr};
	ButtonController* buttonController{ nullptr };

private:
	void OnAnswer1 ();
	void OnAnswer2 ();
	void OnAnswer3 ();
	void OnAnswer4 ();
	void LoadPage (int pageId);
};
