#pragma once
/************************************************************************/
/*  ����:������
/*	ʱ��:2018/04/20 14:48
/* 	˵��:
/*��Ϸ������һ��״̬                                                                     
/************************************************************************/


class Role;  //����

template<typename T>

class State
{
public:
	virtual ~State() {};

	virtual void Enter(T* pRole) = 0; //��װ��

	virtual void Execute(T* pRole) = 0;  //ִ����Ϸ��

	virtual void Exit(T* pRole) = 0;  //�ο�
protected:
private:
};