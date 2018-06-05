#include "RolePet.h"
#include "RolePetOwnedStates.h"

RolePet::RolePet(int id)
	: BassGameEntity(id)
{
	m_pStateMachine = new StateMachine<RolePet>(this);

	m_pStateMachine->SetCurrentState(DoHouseWork::Instance());
}