#include "RolePetOwnedStates.h"
#include <iostream>

//����
void DoHouseWork::Enter(RolePet* pMinerWife)
{

}

//ִ��
void DoHouseWork::Execute(RolePet* pMinerWife)
{
	std::cout << "����Ҫ����Ŷ\n";
	pMinerWife->GetFSM()->ChangeState(VisitBathRoom::Instance());
}


//�˳�
void DoHouseWork::Exit(RolePet* pMinerWife)
{

}

//-------------------------
void VisitBathRoom::Enter(RolePet* pMinerWife)
{

}

//ִ��
void VisitBathRoom::Execute(RolePet* pMinerWife)
{
	std::cout << "����������ð�\n";
	pMinerWife->GetFSM()->ChangeState(DoHouseWork::Instance());
}


//�˳�
void VisitBathRoom::Exit(RolePet* pMinerWife)
{

}