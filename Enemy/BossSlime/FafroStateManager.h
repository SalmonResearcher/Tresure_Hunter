#include "../State/BossState.h"
#include "Boss_Fafrotskies.h"

//状態遷移を管理する
class FafroStateManager : public BossState
{
public:
	BossState* pBossState_;
	BossState* prevState_;

	BossSpawn* pSpawn_;
	BossMove* pMove_;
	BossWait* pWait_;
	BossDamaged* pDameged_;
	BossAttack* pAttack_;
	BossDeath* pDeath_;

	//状態遷移の許可が降りてるか判断
	bool isRestricted_;

	FafroStateManager();
	~FafroStateManager();

	//更新
	virtual void Update(Fafro* _pFafro)override;
	virtual void Process(Fafro* _pFafro)override;
	void ChangeStateRestricted() {isRestricted_ = true; };

	//状態遷移（遷移後に... true->実行 false->実行しない）
	void ChangeState(BossState* change, Fafro* fafro, bool flg);
	//状態遷移（遷移後に実行）
	void ChangeState(BossState* change, Fafro* fafro);
};