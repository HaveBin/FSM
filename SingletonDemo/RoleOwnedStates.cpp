#include <iostream>
#include "RoleOwnedStates.h"

SeriaRoom::SeriaRoom()
{

}

void SeriaRoom::Enter(Role* pRole)
{

}

void SeriaRoom::Execute(Role* pRole)
{
	std::cout<<"�����ǣ������������õ�һ��" << std::endl;
	pRole->ChangeState(InstanceHouse::Instance());
}

void SeriaRoom::Exit(Role* pRole)
{
	std::cout << "��ѡ���ɫ\n";
}

//----------------------------------------------���븱��

void InstanceHouse::Enter(Role* pRole)
{

}

void InstanceHouse::Execute(Role* pRole)
{
	std::cout << "���븱��ս��" << std::endl;
	pRole->DecreaseFatigue();
	pRole->AddToGoldCarried();
	pRole->AddToWeightNegative();
	pRole->DecreaseBloodVolume();
	
	if (pRole->ReduceBlood())
	{
		pRole->ChangeState(InstanceShop::Instance());
	}

	if (pRole->OverWeight())
	{
		pRole->ChangeState(AuctionHouse::Instance());
	}

	if (pRole->NoFatigue())
	{
		std::cout << "��ɫƣ��ʹ�����" << 
			"�������ɫ"<<std::endl;
		pRole->ChangeState(SeriaRoom::Instance());
	}
	
}

void InstanceHouse::Exit(Role* pRole)
{
	std::cout << "���˳����뿪����\n";
}


//--------------------�����̵�

void InstanceShop::Enter(Role* pRole)
{
	std::cout << "�����̵�" << std::endl;
}

void InstanceShop::Execute(Role* pRole)
{
	std::cout << "���ڹ���ҩˮ" << std::endl;
	pRole->AddToBloodVolume();

	if (pRole->OverWeight())
	{
		pRole->ChangeState(AuctionHouse::Instance());
	}

	if (pRole->NoFatigue())
	{
		pRole->ChangeState(SeriaRoom::Instance());
	}
	pRole->ChangeState(InstanceHouse::Instance());
}

void InstanceShop::Exit(Role* pRole)
{
	std::cout << "�������\n";
}


//-------------------����������

void AuctionHouse::Enter(Role* pRole)
{
	std::cout << "����������" << std::endl;
}

void AuctionHouse::Execute(Role* pRole)
{
	pRole->InTheAuction();
	std::cout << "װ�������ϼ����" << std::endl;

	if (pRole->ReduceBlood())
	{
		pRole->ChangeState(InstanceShop::Instance());
	}

	if (pRole->NoFatigue())
	{
		pRole->ChangeState(SeriaRoom::Instance());
	}

	pRole->ChangeState(InstanceHouse::Instance());
}

void AuctionHouse::Exit(Role* pRole)
{
	std::cout << "�������\n";
}