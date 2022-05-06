extern bFallDamageEnable:BYTE
extern lpFallDamageNext:QWORD
extern lpOrgFallDamage:QWORD

.code 
hkFallDamage proc
	cmp bFallDamageEnable, 0
	je OrgFnc 
	jmp lpFallDamageNext
OrgFnc:
	jmp lpOrgFallDamage
hkFallDamage endp
end