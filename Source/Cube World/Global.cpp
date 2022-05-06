#include "Global.h"

LPVOID lpLocalPlayer = nullptr;

LPVOID Movement::lpJmpRemainMovement = nullptr;
LPVOID Movement::lpJmpOrgMovement = nullptr;
DWORD64 Movement::dwSpeed = 1;

LPVOID FallDamage::lpFallDamageNext = nullptr;
LPVOID FallDamage::lpOrgFallDamage = nullptr;
bool FallDamage::bFallDamageEnable = false;

LPVOID SuperJump::lpSuperJumpNext = nullptr;
DWORD SuperJump::dwJumpHeight = 10.0f;