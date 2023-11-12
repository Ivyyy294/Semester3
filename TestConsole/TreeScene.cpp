#include <math.h>
#include <stack>
#include "IvyyyLine.h"
#include "TreeScene.h"
using namespace Ivyyy;

void TreeScene::Init ()
{
	float angle = 23.f;
	int depth = 1;

	NodeInfo rootInfo;
	rootInfo.width = 100.f;
	rootInfo.angle = 45.f;
	rootInfo.parent = nullptr;
	rootInfo.pos = Vector2 (0.f, -200.f);
	rootInfo.width = 100.f;

	BuildTree (0, 3, rootInfo);
}

void TreeScene::BuildTree (int depth, const int maxDepth, const NodeInfo& sideInfo)
{
	if (depth < maxDepth)
	{
		ChildInfo childInfo = AddTreeNodeObject (sideInfo);

		//Call BuildTree for left and right
		BuildTree (depth + 1, maxDepth, childInfo.left);
		BuildTree (depth + 1, maxDepth, childInfo.right);
	}

	return;
}

TreeScene::ChildInfo TreeScene::AddTreeNodeObject (const NodeInfo& nodeInfo)
{
	//Set GameObject
	GameObject* gameObject = AddGameObject <GameObject> ().get();
	gameObject->transform.GetLocalPosition () = nodeInfo.pos;

	if (nodeInfo.parent != nullptr)
	{
		gameObject->transform.GetLocalRotation() = nodeInfo.angle;
		gameObject->SetParent (nodeInfo.parent);
	}

	AddRectObject(nodeInfo, gameObject);
	ChildInfo childInfo = AddTriangleObject (nodeInfo, gameObject);

	return childInfo;
}

void TreeScene::AddRectObject (const NodeInfo& nodeInfo, Ivyyy::GameObject* parent)
{
	auto rectObj = AddGameObject <GameObject> ();

	rectObj->SetParent (parent);
	rectObj->transform.GetLocalPosition ().y += nodeInfo.width * 0.5f;

	auto rect = rectObj->AddComponent <RectMesh> ();
	rect->width = nodeInfo.width;
	rect->height = nodeInfo.width;
	rect->color = nodeInfo.color;
}

TreeScene::ChildInfo TreeScene::AddTriangleObject (const NodeInfo& nodeInfo, Ivyyy::GameObject* parent)
{
	auto triangleObj = AddGameObject <GameObject> ();
	
	triangleObj->transform.GetLocalPosition ().y += nodeInfo.width;
	triangleObj->SetParent (parent);

	auto triangle = triangleObj->AddComponent <GeometryMesh> ();
	triangle->color = nodeInfo.color;

	float xPos = nodeInfo.width * 0.5f;
	Vector2 p1 (-xPos, 0.f);
	Vector2 p3 (xPos, 0.f);

	float widhtLeft = nodeInfo.width * cos (nodeInfo.angle * (M_PI / 180.0));
	float widhtRight = nodeInfo.width * sin (nodeInfo.angle * (M_PI / 180.0));

	Line line;
	line.SetP1 (p1);
	line.SetLength (widhtLeft);
	line.SetAngle (std::abs (nodeInfo.angle));

	Vector2 p2 = line.P2 ();

	triangle->points.push_back (p1);
	triangle->points.push_back (p2);
	triangle->points.push_back (p3);

	ChildInfo childInfo;
	
	Vector2 posOffset = triangleObj->transform.GetLocalPosition ();

	//Left
	childInfo.left.angle = -nodeInfo.angle;
	childInfo.left.width = widhtLeft;
	childInfo.left.parent = parent;
	childInfo.left.color = nodeInfo.color;

	Line left (Vector2::Zero, Vector2(widhtLeft * 0.5f, 0.f));
	left.SetAngle (std::abs (nodeInfo.angle));

	childInfo.left.pos = p1 + posOffset + left.P2 ();

	//Right
	childInfo.right.angle = 90.f - nodeInfo.angle;
	childInfo.right.width = widhtRight;
	childInfo.right.parent = parent;
	childInfo.right.color = nodeInfo.color;

	Line right (Vector2::Zero, Vector2 (widhtRight * 0.5f, 0.f));
	right.SetAngle (-childInfo.right.angle);

	childInfo.right.pos = p3 + posOffset - right.P2 ();


	//childInfo.right.pos = right.P2 ();

	return childInfo;
}
