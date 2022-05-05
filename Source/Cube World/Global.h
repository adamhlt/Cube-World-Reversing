#ifndef GLOBAL_H
#define GLOBAL_H

#include <Windows.h>

extern "C" LPVOID lpLocalPlayer;

namespace Movement
{
	extern "C" void hkMovement();
	extern "C" LPVOID lpJmpRemainMovement;
	extern "C" LPVOID lpJmpOrgMovement;
	extern "C" DWORD64 dwSpeed;
}

#endif