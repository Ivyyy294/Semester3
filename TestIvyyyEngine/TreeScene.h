#pragma once

#include "IvyyyScene.h"
#include <IvyyyColor.h>
#include <IvyyyVector2.h>

using namespace Ivyyy;

class TreeScene : public Ivyyy::Scene
{
protected:
	void Init () override;

private:

	struct NodeInfo
	{
		float angle { 0.f };
		float rotation { 0.f };
		float width { 0.f };
		Vector2 pos;
		GameObject* parent { nullptr };
		Color color;
	};

	struct ChildInfo
	{
		NodeInfo left;
		NodeInfo right;
	};

	void BuildTree (const int depth, const int maxDepth, const NodeInfo& sideInfo);
	ChildInfo AddTreeNodeObject (const NodeInfo& sideInfo);
	Vector2 GetLineEndPos (const Vector2& startPos, const float width, const float angle) const;
};

