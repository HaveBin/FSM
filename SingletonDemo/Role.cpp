#include "Role.h"
#include "RoleOwnedStates.h"

Role::Role(int id)
	: BassGameEntity(id)
	,m_iGoldCarried(0)
	, m_RoleHp(100)
	, m_iRoleFatigue(188)
	, m_iWeightNegative(0)
	, m_iMedicinalWater(5)
	,m_GurrentState(SeriaRoom::Instance())
{
	m_pStateMachine = new StateMachine<Role>(this);

	m_pStateMachine->SetCurrentState(InstanceHouse::Instance());
}

location_type Role::GetLocation() const
{
	return m_Location;
}

int Role::GoldCarried() const
{
	return m_iGoldCarried;
}

void Role::SetGoldCarried(const int val) 
{
	m_iGoldCarried = val;
}

int Role::RoleMedicinalWater() const  //药水
{
	return m_iMedicinalWater;
}

void Role::SetRoleMedicinalWater(const int val)
{
	m_iMedicinalWater = val;
}



void Role::DecreaseFatigue()
{
	m_iRoleFatigue -= 6;        //进入副本疲劳减少
}

void Role::AddToGoldCarried()
{
	m_iGoldCarried += 7;
	if (m_iGoldCarried < 0)
	{
		m_iGoldCarried = 0;
	}
}

void Role::AddToWeightNegative()   
{
	m_iWeightNegative += 5;
	if (m_iWeightNegative < 0)
	{
		m_iWeightNegative = 0;
	}
}

void Role::AddToBloodVolume()
{
	m_iMedicinalWater += 2;
	if (m_iMedicinalWater < 0)
	{
		m_iMedicinalWater = 0;
	}
}

void Role::InTheAuction()
{
	m_iWeightNegative -= 70;

	m_iGoldCarried += 100;
}

void Role::DecreaseBloodVolume()
{
	m_RoleHp -= 10;
	
	if (m_RoleHp < 80)
	{
		m_iMedicinalWater -= 1;
	}
	if (m_iMedicinalWater < 0)
	{
		m_iMedicinalWater = 0;
	}
}

bool Role::OverWeight()
{
	if (m_iWeightNegative >= 70)
	{
		return true;
	}

	return false;
}

bool Role::ReduceBlood()
{
	if (m_iMedicinalWater < 5)
	{
		return true;
	}

	return false;
}

bool Role::NoFatigue()
{
	if (m_iRoleFatigue < 6)
	{
		return true;
	}

	return false;
}


void Role::ChangeState(State<Role>* new_state)
{
	m_GurrentState->Exit(this); // 把卡弹出

	m_GurrentState = new_state;   //换卡

	m_GurrentState->Enter(this);
}

void Role::Update()
{
	//状态执行

	if (m_GurrentState)
	{
		m_GurrentState->Execute(this);
	}
}

