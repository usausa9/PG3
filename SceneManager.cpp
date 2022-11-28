#include "SceneManager.h"

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	sceneNum = sceneNo;

	// 3->0‚Ö–ß‚éˆ—
	if (sceneNum > SceneNum::_GameClear) 
	{
		sceneNum = SceneNum::_Title;
	}
}

SceneManager::SceneManager()
{
	sceneNum = SceneNum::_Title;
}