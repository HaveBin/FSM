#pragma once
#include "State.h"

template<typename T>
class StateMachine
{
public:
	StateMachine(T* owner)
		:m_pOwner(owner)
	{

	}


	void ChangeState(State<T>* new_state)
	{
		m_pCurrentState->Exit(m_pOwner);  //这里以前是this指针

		m_pCurrentState = new_state;

		m_pCurrentState->Enter(m_pOwner);
	}

	//非常重要必须实现
	void Update()
	{
		if (m_pCurrentState)
		{
			m_pCurrentState->Execute(m_pOwner);
		}
	}

	void SetCurrentState(State<T>* new_state)
	{
		m_pCurrentState = new_state;
	}

private:
	T* m_pOwner;
	State<T>* m_pCurrentState;
};

