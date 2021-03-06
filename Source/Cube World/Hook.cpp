#include "Hook.h"
#include "Detours/include/detours.h"
#include "Global.h"

lpLoopFnc Hook::lpOrgLoopFnc = nullptr;

void Hook::InitHook()
{
	lpLocalPlayer = nullptr;
	Movement::lpJmpRemainMovement = nullptr;

	PDETOUR_TRAMPOLINE DetourData = {};

	const auto lpMovementAddress = (LPVOID)((DWORD_PTR)GetModuleHandleA("cubeworld.exe") + 0x2BE3F2);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttachEx((PVOID*)&lpMovementAddress, &Movement::hkMovement, &DetourData, nullptr, nullptr);
	const auto lpDetourInfo = (DETOUR_INFO*)DetourData;
	Movement::lpJmpRemainMovement = lpDetourInfo->pbRemain;
	DetourTransactionCommit();

	Movement::lpJmpOrgMovement = lpMovementAddress;

	const auto lpFallDamageAddress = (LPVOID)((DWORD_PTR)GetModuleHandleA("cubeworld.exe") + 0x2BEBB9);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttachEx((PVOID*)&lpFallDamageAddress, &FallDamage::hkFallDamage, &DetourData, nullptr, nullptr);
	DetourTransactionCommit();

	FallDamage::lpOrgFallDamage = lpFallDamageAddress;
	FallDamage::lpFallDamageNext = (LPVOID)((DWORD_PTR)GetModuleHandleA("cubeworld.exe") + 0x2BEDCA);

	const auto lpSuperJumpAddress = (LPVOID)((DWORD_PTR)GetModuleHandleA("cubeworld.exe") + 0x9D443);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttachEx((PVOID*)&lpSuperJumpAddress, &SuperJump::hkSuperJump, &DetourData, nullptr, nullptr);
	DetourTransactionCommit();

	SuperJump::lpSuperJumpNext = (LPVOID)((DWORD_PTR)GetModuleHandleA("cubeworld.exe") + 0x9D45E);


	const auto lpFnc = (LPVOID)((DWORD_PTR)GetModuleHandleA("cubeworld.exe") + 0x9C050);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach((PVOID*)&lpFnc, &hkLoopFnc);
	DetourTransactionCommit();

	lpOrgLoopFnc = (lpLoopFnc)lpFnc;
}

void Hook::hkLoopFnc(INT64 a1, DOUBLE a2)
{
	const uintptr_t st1 = *(uintptr_t*)(a1 + 0x8);
	const uintptr_t st2 = *(uintptr_t*)(st1 + 0x448);
	lpLocalPlayer = (LPVOID)st2;

	return lpOrgLoopFnc(a1, a2);
}
