#ifndef _ENTITY_H
#define _ENTITY_H

class BassGameEntity
{
public:

	int GetiID() const
	{
		return m_ID;
	}

	void SetID(int val)
	{
		m_ID = val;
	}

	virtual void Update() = 0;
protected:
private:
	int m_ID;

	static int m_iNextValidID; // 下一个有效的数字
};











#endif  //_ENTITY_H
