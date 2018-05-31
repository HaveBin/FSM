#pragma once
/************************************************************************/
/*  作者:杨依斌
/*	时间:2018/04/20 14:48
/* 	说明:
/*游戏机卡的一种状态                                                                     
/************************************************************************/


class Role;  //声明

template<typename T>

class State
{
public:
	virtual ~State() {};

	virtual void Enter(T* pRole) = 0; //安装卡

	virtual void Execute(T* pRole) = 0;  //执行游戏卡

	virtual void Exit(T* pRole) = 0;  //拔卡
protected:
private:
};