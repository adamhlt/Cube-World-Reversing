extern lpLocalPlayer:QWORD
extern lpJmpRemainMovement:QWORD
extern lpJmpOrgMovement:QWORD
extern dwSpeed:QWORD

.code 
hkMovement proc
	cmp r13,lpLocalPlayer
	je Check
	jmp lpJmpOrgMovement
Check:
	cmp rcx,2
	jne Cave
	jmp lpJmpOrgMovement
Cave:
	imul rax,dwSpeed
	add  [r13+rcx*8+10h],rax
	jmp lpJmpRemainMovement
hkMovement endp
end