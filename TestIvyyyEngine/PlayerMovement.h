#pragma once
#include "IvyyyComponent.h"

class PlayerMovement
	: public Ivyyy::Component
{
public:
	void Update () override;

private:
#ifdef IVYYY_D3D
	float speed{ 1.f };
#else
	float speed{ 256.f };
#endif // IVYYY_D3D
};

