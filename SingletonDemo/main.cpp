#include <iostream>
#include "Role.h"

#include <windows.h>
#include <thread>

int main(int argc, char argv[])
{
	Role role;

	while (true)
	{
		role.Update();
		Sleep(500);
		//std::this_thread::sleep_for(std::chrono::seconds(1);  //��ƽ̨д��
		if (role.NoFatigue())
		{
			role.Update();
			Sleep(500);
			getchar();
			return false;
		}
	}



	return 0;
}