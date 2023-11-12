#include "PlayerMovement.h"
#include "IvyyyInput.h"
#include "IvyyyTime.h"

using namespace Ivyyy;

void PlayerMovement::Update ()
{
	Vector3 moveVec;

	//Horizontal movement
	if (Input::KeyPressed (Key::KEY_D))
		moveVec += Vector3::Right ();
	if (Input::KeyPressed (Key::KEY_A))
		moveVec -= Vector3::Right ();
	
	//Vertical movement
	if (Input::KeyPressed (Key::KEY_W))
		moveVec += Vector3::Up ();
	if (Input::KeyPressed (Key::KEY_S))
		moveVec -= Vector3::Up ();

	//Scale
	if (Input::KeyPressed (Key::KEY_F))
		transform->GetLocalScale () *= 0.9f;
	if (Input::KeyPressed (Key::KEY_G))
		transform->GetLocalScale () *= 1.1f;

	//Rotation
	if (Input::KeyPressed (Key::KEY_H))
		transform->GetLocalRotation () += 45.f * Time::DeltaTime ();

	transform->GetLocalPosition () += moveVec.Normalized () * speed * Time::DeltaTime ();
}
