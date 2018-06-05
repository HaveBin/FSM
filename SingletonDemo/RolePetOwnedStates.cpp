#include "RolePetOwnedStates.h"
#include <iostream>

//进入
void DoHouseWork::Enter(RolePet* pMinerWife)
{

}

//执行
void DoHouseWork::Execute(RolePet* pMinerWife)
{
	std::cout << "主人要加油哦\n";
	pMinerWife->GetFSM()->ChangeState(VisitBathRoom::Instance());
}


//退出
void DoHouseWork::Exit(RolePet* pMinerWife)
{

}

//-------------------------
void VisitBathRoom::Enter(RolePet* pMinerWife)
{

}

//执行
void VisitBathRoom::Execute(RolePet* pMinerWife)
{
	std::cout << "今天天气真好啊\n";
	pMinerWife->GetFSM()->ChangeState(DoHouseWork::Instance());
}


//退出
void VisitBathRoom::Exit(RolePet* pMinerWife)
{

}