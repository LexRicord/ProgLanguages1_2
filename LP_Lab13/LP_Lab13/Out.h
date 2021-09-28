#pragma once

#include "stdafx.h"
#include "In.h"
#include "Parm.h"	
#include "Error.h"	

namespace Out   //работа с файлом протокола 
{
	struct OUT	//польз. тип - Протокол.
	{
		wchar_t outFile[PARM_MAX_SIZE]; //Имя файла
		std::ofstream* stream;			//выходной поток протокола
	};

	static const OUT INITLOG = { L"", NULL };		//структура для начальн. иниц. типа OUT
	OUT getOut(wchar_t outFile[]);					//сформировать стр. OUT
	void outClose(OUT out);							//закрыть файл объектного кода
};
