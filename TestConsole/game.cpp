// include the basic windows header files and the Direct3D header file
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <memory>

#include "IvyyyEngine.h"
#include "IvyyySceneHandler.h"
#include "LoadingScene.h"
#include "GameScene.h"
#include "JonasScene.h"
#include "TreeScene.h"

// the entry point for any Windows program
int WINAPI WinMain (HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Ivyyy::SceneHandler::AddScene <TreeScene> ();
	Ivyyy::SceneHandler::AddScene <JonasScene> ();
	Ivyyy::SceneHandler::AddScene <LoadingScene> ();
	Ivyyy::SceneHandler::AddScene <GameScene> ();
	return Ivyyy::IvyyyEngine::Start (hInstance, nCmdShow);
}



