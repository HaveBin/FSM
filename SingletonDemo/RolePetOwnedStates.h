#pragma once
#include "RolePet.h"

class DoHouseWork : public State<RolePet>
{
public:
	//����
	virtual void Enter(RolePet* pMinerWife);

	//ִ��
	virtual void Execute(RolePet* pMinerWife);

	//�˳�
	virtual void Exit(RolePet* pMinerWife);

	static DoHouseWork* Instance()
	{
		static DoHouseWork instance;  //����ģʽ
		return &instance;
	}
};

class VisitBathRoom : public State<RolePet>
{
public:
	//����
	virtual void Enter(RolePet* pMinerWife);

	//ִ��
	virtual void Execute(RolePet* pMinerWife);

	//�˳�
	virtual void Exit(RolePet* pMinerWife);

	static VisitBathRoom* Instance()
	{
		static VisitBathRoom instance;  //����ģʽ
		return &instance;
	}
};