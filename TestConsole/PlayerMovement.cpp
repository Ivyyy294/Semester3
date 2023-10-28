#include "PlayerMovement.h"
#include "IvyyyInput.h"
#include "IvyyyTime.h"

using namespace Ivyyy;

void PlayerMovement::Update ()
{
	Vector3 moveVec;

	//Horizontal movement
	if (Input::KeyPressed (Input::KEY_D))
		moveVec += Vector3::Right ();
	if (Input::KeyPressed (Input::KEY_A))
		moveVec -= Vector3::Right ();
	
	//Vertical movement
	if (Input::KeyPressed (Input::KEY_W))
		moveVec += Vector3::Up ();
	if (Input::KeyPressed (Input::KEY_S))
		moveVec -= Vector3::Up ();

	//Scale
	if (Input::KeyPressed (Input::KEY_F))
		transform->GetLocalScale () *= 0.9f;
	if (Input::KeyPressed (Input::KEY_G))
		transform->GetLocalScale () *= 1.1f;

	//Rotation
	if (Input::KeyPressed (Input::KEY_H))
		transform->GetLocalRotation () += 45.f * Time::DeltaTime ();

	transform->GetLocalPosition () += moveVec.Normalized () * speed * Time::DeltaTime ();
}