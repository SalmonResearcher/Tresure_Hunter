#include "Jewel.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

#include "Stage.h"
#include "Player.h"

//Debug用
#include "Engine/Debug.h"
#include "Engine/Input.h"


#include <cmath>


//コンストラクタ
Jewel::Jewel(GameObject* parent)
    :GameObject(parent, "Jewel"), hModel_(-1), time(0),jewelRotate_(false)
{

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.5f, 0), 0.8f);
    AddCollider(collision);
}

//デストラクタ
Jewel::~Jewel()
{
}

//初期化
void Jewel::Initialize()
{
    hModel_ = Model::Load("Jewel.fbx");
    assert(hModel_ >= 0);

    hStage_ = ((Stage*)FindObject("Stage"))->GetModelHandle();

    RayCastData data;
    data.start = { trJewel_.position_ };   //レイの発射位置
    data.dir = XMFLOAT3(0, -1, 0);       //レイの方向
    Model::RayCast(hStage_, &data); //レイを発射

    if (data.hit)
    {
        //if (data.dist <= 0.1f)
        //{
        //    grabity_ = 0.0f;
        //}
        //else
        //{
        //    grabity_ = 0.2f;
        //}

        //trJewel_.position_.y -= grabity_;
        trJewel_.position_.y = -data.dist;
    }
    trJewel_.position_.x = 10;
}

//更新
void Jewel::Update()
{

    //trJewel_.position_.y = (float)sin(time)/50;

    // メインのプログラム
    if (time % 90 == 0) {
        jewelRotate_ = true;
    }

    if (jewelRotate_) {
        float easingFactor = easeInOutCubic(static_cast<float>(rotY) / 360.0f);
        trJewel_.rotate_.y = rotY * easingFactor;

        rotY += 5.5f;
        if (rotY >= 360) {
            rotY = 0;
            jewelRotate_ = false;
        }
    }

    time++;
    transform_ = trJewel_;
}

//描画
void Jewel::Draw()
{
    Model::SetTransform(hModel_, trJewel_);
    Model::Draw(hModel_);
}

void Jewel::Release()
{
}
