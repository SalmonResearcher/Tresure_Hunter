#include "Global.h"
namespace Global
{
	int killcount;
	int jewel;
	int jewelKill;
	int score;

	void SetKillCount(int count) { killcount = count; }
	void AddKillCount(int count) {killcount += count;}
	int GetKillCount() { return killcount; }

	void SetJewel(int count) { jewel = count; }
	int GetJewel() { return jewel; }

	void AddJewelKill(int count) { jewelKill += count; }
	int GetJewelKill() { return jewelKill; }

	void SetScore(int count) { score = count; }
	int GetScire() { return score; }
}