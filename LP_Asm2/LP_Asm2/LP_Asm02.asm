.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib user32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
MB_OK	 EQU 0							;EQU определяет константу
dw1      dword 2d						;dword - 4 byte , d - decimal , h -hexadecical 
dw2      dword 4d						;определяет переменную dw2 как двойное слово (4 байта) + суффикс d
STR1	 DB	   "Сложение двух чисел", 0 ;строка + нулевой байт, DB - define byte
STR2	 DB	   "Результат сложения: ", 0
HW	     DD		?						;двойное слово, неинициализированное

.CODE

main PROC										;точка входа, начало процедуры main
START :											;метка 
MOV eax, dw1
MOV ebx, dw2									;Mov - записывает в один регистр значение другого, константу или зн-е ячейки памяти. Запись dw2 в ebx
ADD eax, ebx
ADD al, '0'
MOV ebx, lengthof STR2 - 1						;возвращает количество объектов данных в переменной
MOV	[STR2 + ebx], al
PUSH MB_OK										;"Ложит данные в стек" - Операнд: регистр, ячейкa памяти или непосредственнo операнд. Размер операнда должен быть 2 или 4 байта. 
PUSH OFFSET STR1
PUSH OFFSET STR2								
PUSH HW
CALL MessageBoxA								;вызов функции

push - 1										;код возврата процесса	Windows (пар-р Exitprocess)
CALL ExitProcess								;завершение процесса Windows

main ENDP										;конец процедуры
end main										;конец модуля, точка выхода main