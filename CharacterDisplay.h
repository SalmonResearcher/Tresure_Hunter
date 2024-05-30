#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"



class CharacterDisplay :public GameObject
{
private:
	Text* pText;

	int kill_;
	int jewel_;
	int score_ = 0;
	int up_ = 0;

public:

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	CharacterDisplay(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};