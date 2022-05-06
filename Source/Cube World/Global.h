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

namespace FallDamage
{
	extern "C" void hkFallDamage();
	extern "C" LPVOID lpFallDamageNext;
	extern "C" LPVOID lpOrgFallDamage;
	extern "C" bool bFallDamageEnable;
}

namespace SuperJump
{
	extern "C" void hkSuperJump();
	extern "C" LPVOID lpSuperJumpNext;
	extern "C" DWORD dwJumpHeight;
}

#endif