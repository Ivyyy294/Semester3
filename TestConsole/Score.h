#pragma once
#include <IvyyyComponent.h>
#include <IvyyyFontMesh.h>
#include <memory>

using namespace Ivyyy;

class Score :
    public Component
{
public:
		virtual void Start () override;
		virtual void Update () override;

		int score{ 0 };
private:
	std::weak_ptr <FontMesh> fontMesh;
};

