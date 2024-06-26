#pragma once
#include "Engine/GameObject.h"
#include <string.h>

class StageSelectScene :
    public GameObject
{
private:
	const int MAX_STAGE = 3;

	//↓なんかMAX_STAGEが使えない↓
	int hStage_[3];
	//ステージプレビューのトランスフォーム
	Transform trStage1, trStage2, trStage3;

	int hSkysphere;
	Transform trSky;

	std::string name = "MiniStage";
	std::string num;
	std::string ext = ".fbx";

	//回転用の時間
	float timer;

	//キー長押しで高速ステージ選択用タイマー
	int keyTimer;

	//縦揺れ時間
	float yMoveTime;

	//ゆっくり上下させたい
	float sinwave;

	//ステージ選択するときのカウント
	int selectCount = 0;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	StageSelectScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};

