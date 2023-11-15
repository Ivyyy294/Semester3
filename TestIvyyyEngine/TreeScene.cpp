#include <math.h>
#include "IvyyyLine.h"
#include "IvyyyRectMesh.h"
#include "IvyyyGeometryMesh.h"

#include "TreeScene.h"

void TreeScene::Init ()
{
	float angle = 23.f;
	int depth = 1;

	NodeInfo rootInfo;
	rootInfo.width = 96.f;
	rootInfo.angle = 40.f;
	rootInfo.rotation = 0.f;
	rootInfo.parent = nullptr;
	rootInfo.pos = Vector2 (0.f, -200.f);
	rootInfo.width = 100.f;
	rootInfo.color = Color (152, 107, 65);

	BuildTree (0, 12, rootInfo);
}

void TreeScene::BuildTree (const int depth, const int maxDepth, const NodeInfo& sideInfo)
{
	if (depth < maxDepth)
	{
		ChildInfo childInfo = AddTreeNodeObject (sideInfo);

		//Dye last two Nodes pink
		if (depth + 3 == maxDepth)
		{
			Color pink (255, 183, 197);
			childInfo.left.color = pink;
			childInfo.right.color = pink;
		}

		//Call BuildTree for left and right
		BuildTree (depth + 1, maxDepth, childInfo.left);
		BuildTree (depth + 1, maxDepth, childInfo.right);
	}

	return;
}

TreeScene::ChildInfo TreeScene::AddTreeNodeObject (const NodeInfo& nodeInfo)
{
	//Add GameObject
	auto gameObject = AddGameObject <GameObject> ();

	//Set local position, rotation and parent  from NodeInfo
	gameObject->transform.GetLocalPosition () = nodeInfo.pos;

	if (nodeInfo.parent != nullptr)
	{
		gameObject->transform.GetLocalRotation () = nodeInfo.rotation;
		gameObject->SetParent (nodeInfo.parent);
	}

	//Add GeometryMesh component
	auto geoMesh = gameObject->AddComponent <GeometryMesh> ();

	//Set Mesh color
	geoMesh->color = nodeInfo.color;

	//Rect containts of P1, P2, P6 and P7 
	Vector2 p1 (nodeInfo.width * -0.5f, 0.f);
	Vector2 p2 (p1.x, nodeInfo.width);
	Vector2 p6 (nodeInfo.width * 0.5f, nodeInfo.width);
	Vector2 p7 (p6.x, 0.f);

	//Triangle consists of P2, P4, P6 and sub positions P3 and P5

	//Length ankathete
	float widhtLeft = nodeInfo.width * cos (nodeInfo.angle * (M_PI / 180.0));
	//Length gegenkathete
	float widhtRight = nodeInfo.width * sin (nodeInfo.angle * (M_PI / 180.0));
	
	//Calculate P3-P5
	Vector2 p3 = GetLineEndPos (p2, widhtLeft * 0.5f, nodeInfo.angle);
	Vector2 p4 = GetLineEndPos (p2, widhtLeft, nodeInfo.angle);
	Vector2 p5 = GetLineEndPos (p6, widhtRight * 0.5f,  90.f + nodeInfo.angle);
	
	//Add points to GeometryMesh
	geoMesh->points.push_back (p1);
	geoMesh->points.push_back (p2);
	geoMesh->points.push_back (p3);
	geoMesh->points.push_back (p4);
	geoMesh->points.push_back (p5);
	geoMesh->points.push_back (p6);
	geoMesh->points.push_back (p7);

	//Set Child Info struct
	ChildInfo childInfo;
	childInfo.left.angle = nodeInfo.angle;
	childInfo.left.color = nodeInfo.color;
	childInfo.left.parent = gameObject.get();
	childInfo.left.width = widhtLeft;
	childInfo.left.pos = p3;
	childInfo.left.rotation = -nodeInfo.angle;

	childInfo.right.angle = nodeInfo.angle;
	childInfo.right.color = nodeInfo.color;
	childInfo.right.parent = gameObject.get ();
	childInfo.right.width = widhtRight;
	childInfo.right.pos = p5;
	childInfo.right.rotation = 90.f - nodeInfo.angle;
	return childInfo;
}

Vector2 TreeScene::GetLineEndPos (const Vector2& startPos, const float width, const float angle) const
{
	Line line (startPos, startPos + Vector2 (width, 0.f));
	line.SetAngle (line.Angle() + angle);
	return line.P2 ();
}
