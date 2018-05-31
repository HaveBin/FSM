#pragma once

#include "State.h"
#include "Loaction.h"
#include "BassGameEntity.h"

const int m_Hp = 100;  //��ɫѪ��
const int MedicinalWater = 5; // ����Ѫƿ����
const int MaxFatigue = 188; //���ƣ��ֵ
const int MaxWeightNegative = 100; //�����

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

	//Ѫ��
	int m_RoleHp;
	//��Ǯ
	int m_iGoldCarried;
	//ƣ��
	int m_iRoleFatigue;

	//����
	int m_iWeightNegative;
	//Ѫƿ
	int m_iMedicinalWater;

};