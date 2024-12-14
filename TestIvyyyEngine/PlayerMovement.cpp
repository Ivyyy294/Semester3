#include "PlayerMovement.h"
#include "IvyyyInput.h"
#include "IvyyyTime.h"

using namespace Ivyyy;

void PlayerMovement::Update ()
{
	Vector2 moveVec;

	//Horizontal movement
	if (Input::KeyPressed (Key::KEY_D))
		moveVec += Vector2::Right;
	if (Input::KeyPressed (Key::KEY_A))
		moveVec -= Vector2::Right;
	
	//Vertical movement
	if (Input::KeyPressed (Key::KEY_W))
		moveVec += Vector3::Up ();
	if (Input::KeyPressed (Key::KEY_S))
		moveVec -= Vector3::Up ();

	//Scale
	if (Input::KeyPressed(Key::KEY_F))
	{
		Vector2 newScale = transform->GetLocalScale() * 0.9f;
		transform->SetLocalScale (newScale);
	}
	if (Input::KeyPressed (Key::KEY_G))
	{
		Vector2 newScale = transform->GetLocalScale() * 1.1f;
		transform->SetLocalScale(newScale);
	}

	//Rotation
	if (Input::KeyPressed(Key::KEY_H))
	{
		Quaternion euler = Quaternion::Euler (Vector3 (0.f, 0.f, 45.f * Time::DeltaTime()));
		Quaternion newRot = transform->GetLocalRotation() * euler;
		transform->SetLocalRotation (newRot);
	}

	Vector2 newPos = transform->GetLocalPosition() + moveVec.Normalized() * speed * Time::DeltaTime();
	transform->SetLocalPosition(newPos);
}
