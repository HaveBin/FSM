#ifndef _ENTITY_H
#define _ENTITY_H

class BassGameEntity
{
public:
	BassGameEntity(int id)
	{
		SetID(id);
	}

	int GetiID() const
	{
		return m_ID;
	}

	void SetID(int val)
	{
		m_ID = val;

		m_iNextValidID = m_ID + 1;
	}

protected:
private:
	int m_ID;

	static int m_iNextValidID; // ��һ����Ч������
};











#endif  //_ENTITY_H
