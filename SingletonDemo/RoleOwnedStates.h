#pragma once

/************************************************************************/
/*  ����:������
/*	ʱ��:2018/04/20 14:36
/* 	˵��:
/*	    ����ӵ�е�״̬ ��Ϸ��                                                                 
/************************************************************************/

#include "State.h"
#include "Role.h"

class SeriaRoom : public State<Role>

{
public:
	SeriaRoom();
	virtual void Enter(Role* pRole);  //��װ��

	virtual void Execute(Role* pRole);  //ִ����Ϸ��

	virtual void Exit(Role* pRole);  //�ο�

	//danli 
	static SeriaRoom* Instance()
	{
		static SeriaRoom instance;    //����һ���� ����ͻ����

		return &instance;
	}

private:
};

class InstanceHouse: public State<Role>
{
public:
	//InstanceHouse();
	virtual void Enter(Role* pRole) ; //��װ��

	virtual void Execute(Role* pRole) ;  //ִ����Ϸ��

	virtual void Exit(Role* pRole) ;  //�ο�


									  //danli 
	static InstanceHouse* Instance()
	{
		static InstanceHouse instance;    //����һ���� ����ͻ����

		return &instance;
	}

};


class InstanceShop : public State<Role>
{
public:
	//InstanceHouse();
	virtual void Enter(Role* pRole); //��װ��

	virtual void Execute(Role* pRole);  //ִ����Ϸ��

	virtual void Exit(Role* pRole);  //�ο�


									 //danli 
	static InstanceShop* Instance()
	{
		static InstanceShop instance;    //����һ���� ����ͻ����

		return &instance;
	}

};

class AuctionHouse : public State<Role>
{
public:
	//InstanceHouse();
	virtual void Enter(Role* pRole); //��װ��

	virtual void Execute(Role* pRole);  //ִ����Ϸ��

	virtual void Exit(Role* pRole);  //�ο�


									 //danli 
	static AuctionHouse* Instance()
	{
		static AuctionHouse instance;    //����һ���� ����ͻ����

		return &instance;
	}

};



