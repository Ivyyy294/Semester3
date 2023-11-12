#pragma once

#include "IvyyyScene.h"
#include "IvyyyRectMesh.h"
#include "IvyyyGeometryMesh.h"
#include <IvyyyColor.h>

using namespace Ivyyy;

class TreeScene : public Ivyyy::Scene
{
protected:
	void Init () override;

private:

	struct NodeInfo
	{
		float angle;
		float rotation;
		float width;
		Vector2 pos;
		GameObject* parent;
		Color color;
	};

	struct ChildInfo
	{
		NodeInfo left;
		NodeInfo right;
	};

	void BuildTree (int depth, const int maxDepth, const NodeInfo& sideInfo);
	ChildInfo AddTreeNodeObject (const NodeInfo& sideInfo);
	Vector2 GetLineEndPos (const Vector2& startPos, const float width, const float angle);
};

