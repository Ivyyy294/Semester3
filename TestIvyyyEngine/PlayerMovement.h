#pragma once
#include "IvyyyComponent.h"

class PlayerMovement
	: public Ivyyy::Component
{
public:
	void Update () override;

private:
	float speed{ 256.f };
};

