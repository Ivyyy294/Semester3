#pragma once

#include "IvyyyScene.h"
#include "IvyyyRectMesh.h"
#include "IvyyyGeometryMesh.h"
#include <IvyyyColor.h>

class TreeScene : public Ivyyy::Scene
{
protected:
	void Init () override;

private:

	struct NodeInfo
	{
		float angle;
		float width;
		Ivyyy::Vector2 pos;
		Ivyyy::GameObject* parent;
		Ivyyy::Color color;
	};

	struct ChildInfo
	{
		NodeInfo left;
		NodeInfo right;
	};

	void BuildTree (int depth, const int maxDepth, const NodeInfo& sideInfo);
	ChildInfo AddTreeNodeObject (const NodeInfo& sideInfo);
	void AddRectObject (const NodeInfo& nodeInfo, Ivyyy::GameObject* parent);
	ChildInfo AddTriangleObject (const NodeInfo& nodeInfo, Ivyyy::GameObject* parent);
};

