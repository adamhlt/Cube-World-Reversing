extern lpSuperJumpNext:QWORD
extern dwJumpHeight:DWORD

.code 
hkSuperJump proc
	mov eax, dwJumpHeight
	mov dword ptr [rcx+3Ch], eax
	jmp lpSuperJumpNext
hkSuperJump endp
end