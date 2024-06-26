#pragma once
#include "Engine/Global.h"

class Player;

class PlayerState
{
public:
	//更新
	virtual void Update(Player* _p) {};

	//入力
	virtual void HandleInput(Player* _p) {};

	//状態変化したとき
	virtual void Enter(Player* _p) {};

	//状態変化
	void StateChange(PlayerState* _current, PlayerState* _next);
};

