// include the basic windows header files and the Direct3D header file
#include "IvyyyEngine.h"
#include "IvyyySceneHandler.h"
#include "JonasScene.h"
#include "TreeScene.h"

// the entry point for any Windows program
int WINAPI WinMain (HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//Ivyyy::SceneHandler::AddScene <TreeScene> ();
	Ivyyy::SceneHandler::AddScene <JonasScene> ();
	return Ivyyy::IvyyyEngine::Start (hInstance, nCmdShow);
}



