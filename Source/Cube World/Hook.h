#ifndef HOOK_H
#define HOOK_H

#include <Windows.h>

struct DETOUR_ALIGN
{
    BYTE    obTarget : 3;
    BYTE    obTrampoline : 5;
};

struct DETOUR_INFO
{
    // An X64 instuction can be 15 bytes long.
    // In practice 11 seems to be the limit.
    BYTE            rbCode[30];     // target code + jmp to pbRemain.
    BYTE            cbCode;         // size of moved target code.
    BYTE            cbCodeBreak;    // padding to make debugging easier.
    BYTE            rbRestore[30];  // original target code.
    BYTE            cbRestore;      // size of original target code.
    BYTE            cbRestoreBreak; // padding to make debugging easier.
    DETOUR_ALIGN    rAlign[8];      // instruction alignment array.
    PBYTE           pbRemain;       // first instruction after moved code. [free list]
    PBYTE           pbDetour;       // first instruction of detour function.
    BYTE            rbCodeIn[8];    // jmp [pbDetour]
};

using lpLoopFnc = void(__fastcall*)(INT64 a1, DOUBLE a2);

class Hook
{
private:
	static lpLoopFnc lpOrgLoopFnc;

	static void __fastcall hkLoopFnc(INT64 a1, DOUBLE a2);

public:
	static void InitHook();
};

#endif