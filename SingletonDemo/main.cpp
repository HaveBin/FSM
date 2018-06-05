#include <iostream>
#include "Role.h"
#include "RolePet.h"

#include <windows.h>
#include <thread>

int main(int argc, char argv[])
{
	Role* role = new Role(100);
	RolePet* rolePet = new RolePet(200);
	while (true)
	{
// 		role.Update();
// 		Sleep(500);
// 		//std::this_thread::sleep_for(std::chrono::seconds(1);  //¿çÆ½Ì¨Ð´·¨
// 		if (role.NoFatigue())
// 		{
// 			role.Update();
// 			Sleep(500);
// 			getchar();
// 			return false;
	role->GetFSM()->Update();

	rolePet->GetFSM()->Update();

	Sleep(1000);
	}
}