.586
.MODEL FLAT,STDCALL
includelib  kernel32.lib
includelib  user32.lib

ExitProcess PROTO	: DWORD
MessageBoxA	PROTO	: DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
myBytes		BYTE	10h, 20h, 30h, 40h
myWords		WORD	8Ah, 3Bh, 44H, 5Fh, 99h
myDoubles	DWORD	3, 2, 3, 4, 8, 6
myPointer	DWORD	myDoubles
NUMBERS_ARRAY BYTE	2,5,3,7,4,6,0
MB_OK		EQU		0
STR1		DB		"Герман Александр Евгеньевич, 2-й курс, ФИТ-4(ПОИТ)",0
STR2		DB		"Массив содержит нулевой элемент",0
STR3		DB		"Массив не содержит нулевой элемент",0
HW			DD		?

.CODE

main PROC
START:

			mov ESI, OFFSET myWords
			mov AX, [ESI + 4]
			mov BX, [ESI + 2]

			mov EBX, myPointer
			;Сумма элементов массива
			mov EAX, [EBX]
			add EAX, [EBX + 4]
			add EAX, [EBX + 8]
			add EAX, [EBX + 12]
			add EAX, [EBX + 16]
			add EAX, [EBX + 20]
			add EAX, [EBX + 24]

			;Проход по всему массиву с поиском нулевых элементов

BEGIN_CYCLE:
			mov	ECX, lengthof	NUMBERS_ARRAY
			mov EBX, 1
CYCLE:
			cmp [NUMBERS_ARRAY + ECX],	0
			jne FALSE
			je  TRUE
TRUE:
			mov ebx, 0
			jmp	END_CYCLE
FALSE:
			loop CYCLE

END_CYCLE:

CHECK:
			cmp EBX, 0
			je	ZERO

			invoke	MessageBoxA,HW,OFFSET STR3,OFFSET STR1,	MB_OK
			jmp	ENDING
ZERO:
			invoke	MessageBoxA,HW,OFFSET STR2,OFFSET STR1,	MB_OK
ENDING:



	push -1
	call ExitProcess
main ENDP

end main