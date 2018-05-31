#pragma once

/************************************************************************/
/*  作者:杨依斌
/*	时间:2018/04/20 14:36
/* 	说明:
/*	    人物拥有的状态 游戏卡                                                                 
/************************************************************************/

#include "State.h"
#include "Role.h"

class SeriaRoom : public State<Role>

{
public:
	SeriaRoom();
	virtual void Enter(Role* pRole);  //安装卡

	virtual void Execute(Role* pRole);  //执行游戏卡

	virtual void Exit(Role* pRole);  //拔卡

	//danli 
	static SeriaRoom* Instance()
	{
		static SeriaRoom instance;    //程序一启动 对象就会产生

		return &instance;
	}

private:
};

class InstanceHouse: public State<Role>
{
public:
	//InstanceHouse();
	virtual void Enter(Role* pRole) ; //安装卡

	virtual void Execute(Role* pRole) ;  //执行游戏卡

	virtual void Exit(Role* pRole) ;  //拔卡


									  //danli 
	static InstanceHouse* Instance()
	{
		static InstanceHouse instance;    //程序一启动 对象就会产生

		return &instance;
	}

};


class InstanceShop : public State<Role>
{
public:
	//InstanceHouse();
	virtual void Enter(Role* pRole); //安装卡

	virtual void Execute(Role* pRole);  //执行游戏卡

	virtual void Exit(Role* pRole);  //拔卡


									 //danli 
	static InstanceShop* Instance()
	{
		static InstanceShop instance;    //程序一启动 对象就会产生

		return &instance;
	}

};

class AuctionHouse : public State<Role>
{
public:
	//InstanceHouse();
	virtual void Enter(Role* pRole); //安装卡

	virtual void Execute(Role* pRole);  //执行游戏卡

	virtual void Exit(Role* pRole);  //拔卡


									 //danli 
	static AuctionHouse* Instance()
	{
		static AuctionHouse instance;    //程序一启动 对象就会产生

		return &instance;
	}

};



