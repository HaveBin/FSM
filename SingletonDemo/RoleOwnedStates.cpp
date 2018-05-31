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
	std::cout<<"赛利亚：今天又是美好的一天" << std::endl;
	pRole->ChangeState(InstanceHouse::Instance());
}

void SeriaRoom::Exit(Role* pRole)
{
	std::cout << "请选择角色\n";
}

//----------------------------------------------进入副本

void InstanceHouse::Enter(Role* pRole)
{

}

void InstanceHouse::Execute(Role* pRole)
{
	std::cout << "进入副本战斗" << std::endl;
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
		std::cout << "角色疲劳使用完毕" << 
			"请更换角色"<<std::endl;
		pRole->ChangeState(SeriaRoom::Instance());
	}
	
}

void InstanceHouse::Exit(Role* pRole)
{
	std::cout << "【退出】离开副本\n";
}


//--------------------进入商店

void InstanceShop::Enter(Role* pRole)
{
	std::cout << "进入商店" << std::endl;
}

void InstanceShop::Execute(Role* pRole)
{
	std::cout << "正在购买药水" << std::endl;
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
	std::cout << "购买完毕\n";
}


//-------------------进入拍卖行

void AuctionHouse::Enter(Role* pRole)
{
	std::cout << "进入拍卖行" << std::endl;
}

void AuctionHouse::Execute(Role* pRole)
{
	pRole->InTheAuction();
	std::cout << "装备材料上架完毕" << std::endl;

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
	std::cout << "拍卖完毕\n";
}