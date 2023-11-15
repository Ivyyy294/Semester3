#pragma once

#include "IvyyyComponent.h"
#include "ButtonController.h"
#include "PrefabDrawing.h"
#include "PageGraph.h"

using namespace Ivyyy;

class PageController : public Component
{
public:
	PageController ();
	void Start () override;

	PrefabDrawing* prefabDrawing {nullptr};
	ButtonController* buttonController{ nullptr };

private:
	PageGraph pageGraph;
	PageNode* currentPage {nullptr};
	void InitPageGraph ();
	void LoadPage (PageNode* page);

	void OnAnswer1 ();
	void OnAnswer2 ();
	void OnAnswer3 ();
	void OnAnswer4 ();
};
