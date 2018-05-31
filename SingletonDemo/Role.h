#pragma once

#include "State.h"
#include "Loaction.h"
#include "BassGameEntity.h"

const int m_Hp = 100;  //角色血量
const int MedicinalWater = 5; // 身上血瓶数量
const int MaxFatigue = 188; //最大疲劳值
const int MaxWeightNegative = 100; //最大负重

class Role : public BassGameEntity
{
public:
	Role();

	location_type GetLocation() const;

	int GoldCarried() const;

	void SetGoldCarried(const int val) ;

	int RoleMedicinalWater() const;

	void SetRoleMedicinalWater(const int val);

	void DecreaseFatigue();

	void AddToGoldCarried();

	void AddToWeightNegative();

	void AddToBloodVolume();

	void InTheAuction();

	void DecreaseBloodVolume();

	bool OverWeight();

	bool ReduceBlood();

	bool NoFatigue();

	virtual void Update();

	void ChangeState(State<Role>* new_state);
private:
	State<Role>* m_GurrentState;

	location_type m_Location;

	//血量
	int m_RoleHp;
	//金钱
	int m_iGoldCarried;
	//疲劳
	int m_iRoleFatigue;

	//负重
	int m_iWeightNegative;
	//血瓶
	int m_iMedicinalWater;

};