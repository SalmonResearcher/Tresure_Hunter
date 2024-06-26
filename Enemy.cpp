#include "Enemy.h"
#include "Stage.h"
#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
//コンストラクタ
Enemy::Enemy(GameObject* parent)
    :GameObject(parent, "Enemy"), hModel_(-1),hStage_(-1),isJumping(false)
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
    hModel_ = Model::Load("Enemy.fbx");
    assert(hModel_ >= 0);
	transEnemy_.position_.x = target_.x;
	transEnemy_.position_.y = target_.y;
	transEnemy_.position_.z = target_.z;

	SphereCollider* pSpher = new SphereCollider(XMFLOAT3(0,0.8f,0), 1.25f);
	AddCollider(pSpher);

}

//更新
void Enemy::Update()
{
	hStage_ = ((Stage*)FindObject("Stage"))->GetModelHandle();

	RayCastData data;
	data.start = { transEnemy_.position_.x,0,transEnemy_.position_.z };   //レイの発射位置
	data.dir = XMFLOAT3(0, -1, 0);       //レイの方向
	Model::RayCast(hStage_, &data); //レイを発射

	RayCastData play;
	play.start = { transEnemy_.position_.x,transEnemy_.position_.y + 0.3f,transEnemy_.position_.z };   //レイの発射位置
	play.dir = XMFLOAT3(0, -1, 0);       //レイの方向
	Model::RayCast(hStage_, &play); //レイを発射

	if (data.hit)
	{
		if (play.dist <= 0.25 && isJumping)
		{
			moveY = 0.0f;
			isJumping = false;
		}

		if (!isJumping)
		{
			transEnemy_.position_.y = -data.dist;
		}

		transEnemy_.position_.y += moveY;
	}
	transEnemy_.position_.z -= 0.05f;

	//プレイヤーのもとに駆け付けられるように
	//SetTargetPosition()



	transform_.position_ = transEnemy_.position_;
}

//描画
void Enemy::Draw()
{
    Model::SetTransform(hModel_, transEnemy_);
    Model::Draw(hModel_);

}

//開放
void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Attack")
	{
		KillMe();
	}
}