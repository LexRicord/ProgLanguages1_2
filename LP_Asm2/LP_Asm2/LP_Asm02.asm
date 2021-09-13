.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib user32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
MB_OK	 EQU 0							;EQU ���������� ���������
dw1      dword 2d						;dword - 4 byte , d - decimal , h -hexadecical 
dw2      dword 4d						;���������� ���������� dw2 ��� ������� ����� (4 �����) + ������� d
STR1	 DB	   "�������� ���� �����", 0 ;������ + ������� ����, DB - define byte
STR2	 DB	   "��������� ��������: ", 0
HW	     DD		?						;������� �����, ��������������������

.CODE

main PROC										;����� �����, ������ ��������� main
START :											;����� 
MOV eax, dw1
MOV ebx, dw2									;Mov - ���������� � ���� ������� �������� �������, ��������� ��� ��-� ������ ������. ������ dw2 � ebx
ADD eax, ebx
ADD al, '0'
MOV ebx, lengthof STR2 - 1						;���������� ���������� �������� ������ � ����������
MOV	[STR2 + ebx], al
PUSH MB_OK										;"����� ������ � ����" - �������: �������, �����a ������ ��� ��������������o �������. ������ �������� ������ ���� 2 ��� 4 �����. 
PUSH OFFSET STR1
PUSH OFFSET STR2								
PUSH HW
CALL MessageBoxA								;����� �������

push - 1										;��� �������� ��������	Windows (���-� Exitprocess)
CALL ExitProcess								;���������� �������� Windows

main ENDP										;����� ���������
end main										;����� ������, ����� ������ main