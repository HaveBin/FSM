#pragma once

template<typename T>
class Statemachine
{
public:
	void ChangeState(State<T>* new_state)
	{
		m_CurrentState->Exit(this);

		m_CurrentState = new_state;

		m_CurrentState->Enter(this);
	}

	void Update()
	{
		if (m_CurrentState)
		{
			m_CurrentState->Execute(this);
		}
	}
protected:
private:
	State<T>* m_CurrentState;
};