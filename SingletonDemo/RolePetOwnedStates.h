#pragma once
#include "RolePet.h"

class DoHouseWork : public State<RolePet>
{
public:
	//进入
	virtual void Enter(RolePet* pMinerWife);

	//执行
	virtual void Execute(RolePet* pMinerWife);

	//退出
	virtual void Exit(RolePet* pMinerWife);

	static DoHouseWork* Instance()
	{
		static DoHouseWork instance;  //饿汉模式
		return &instance;
	}
};

class VisitBathRoom : public State<RolePet>
{
public:
	//进入
	virtual void Enter(RolePet* pMinerWife);

	//执行
	virtual void Execute(RolePet* pMinerWife);

	//退出
	virtual void Exit(RolePet* pMinerWife);

	static VisitBathRoom* Instance()
	{
		static VisitBathRoom instance;  //饿汉模式
		return &instance;
	}
};