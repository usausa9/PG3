#pragma once

enum SceneNum {
	_Title,
	_NewGame,
	_GamePlay,
	_GameClear
};

class SceneManager final
{
public:
	// コピーコンストラクタを無効化
	SceneManager(const SceneManager& obj) = delete;

	// 代入演算子を無効化
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	// シーン切り替え用の関数
	void ChangeScene(int sceneNo);

	int GetSceneNum() { return sceneNum; }

private:
	SceneManager();
	~SceneManager();

	int sceneNum;
};
