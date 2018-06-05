#pragma once
#include "BassGameEntity.h"
#include "Loaction.h"
#include "StateMachine.h"

class RolePet : public BassGameEntity
{
public:
	RolePet(int id);

	StateMachine<RolePet>* GetFSM()
	{
		return m_pStateMachine;
	}

private:
	StateMachine<RolePet>* m_pStateMachine;
};