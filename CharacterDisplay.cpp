// CharacterDisplay.cpp
#include "CharacterDisplay.h"
#include "Score.h"
#include "Timer.h"
#include "JewelNumber.h"
#include "Engine/Debug.h"

CharacterDisplay::CharacterDisplay(GameObject* parent)
    : GameObject(parent, "CharacterDisplay"),
    displayScore(true), displayTimer(true), displayJewel(true)
{
}

void CharacterDisplay::Initialize()
{
}

void CharacterDisplay::Update()
{
}

void CharacterDisplay::Draw()
{
    if (displayScore) {
        for (size_t i = 0; i < scores.size(); ++i) {
            scores[i]->Draw();
        }
    }
    if (displayTimer) {
        for (size_t i = 0; i < timers.size(); ++i) {
            timers[i]->Draw();
        }
    }
    if (displayJewel) {
        for (size_t i = 0; i < jewels.size(); ++i) {
            jewels[i]->Draw(/* 適切な座標を設定 */);
        }
    }
}


void CharacterDisplay::Release()
{
    for (auto score : scores) {
        delete(score);
    }
    scores.clear();

    for (auto timer : timers) {
        delete(timer);
    }
    timers.clear();

    for (auto jewel : jewels) {
        delete(jewel);
    }
    jewels.clear();
}

void CharacterDisplay::SetScorePosition(int index, int x, int y)
{
    if (index >= 0 && index < static_cast<int>(scores.size())) {
        scores[index]->SetDisplayPosition(x,y);
    }
}

void CharacterDisplay::SetScoreValue(int index, int value)
{
    if (index >= 0 && index < static_cast<int>(scores.size())) {
        scores[index]->SetScore(value);
    }
}

void CharacterDisplay::SetTimerPosition(int index, int x, int y)
{
    if (index >= 0 && index < static_cast<int>(timers.size())) {
        timers[index]->SetTimerPosition(x, y);
    }
}

void CharacterDisplay::SetJewelPosition(int index, int x, int y)
{
    if (index >= 0 && index < static_cast<int>(jewels.size())) {
        jewels[index]->SetPosition(x, y);
    }
}

void CharacterDisplay::SetJewelValue(int index, int value)
{
    if (index >= 0 && index < static_cast<int>(jewels.size())) {
        jewels[index]->SetNumber(value);
    }
}




void CharacterDisplay::CreateScores(int count)
{
    for (int i = 0; i < count; ++i) {
        scores.push_back(Instantiate<Score>(this));
    }
}

void CharacterDisplay::CreateTimers(int count)
{
    for (int i = 0; i < count; ++i) {
        auto timer = Instantiate<Timer>(this);
        timer->SetLimit(0); // タイマー一応初期化
        timers.push_back(timer);
    }
}

void CharacterDisplay::CreateJewels(int count)
{
    for (int i = 0; i < count; ++i) {
        jewels.push_back(Instantiate<JewelNumber>(this));
    }
}