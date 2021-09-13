#pragma once

#define IN_MAX_LEN_TEXT 1024*1024	//максимальный размер исх. кода 1.048 Мб
#define IN_CODE_ENDL '\n'			//Управл. Символ: Переход на новую строку
// таблица проверки входной информации, индекс это код символа в Win-1251
//IN::F - запрещённый символ, IN::T - разрешённый символ, IN::I - игнорировать (не вводить)
// если 0<= знач-е <=256 - то вводится данное зн-е.
#define IN_CODE_TABLE {\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::T, IN::F, IN::F,	IN::I, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::T,	IN::T, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	/*0*/IN::T,	IN::F, /*2*/IN::T, IN::F, IN::F,IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	/*A.Eng(65)*/IN::T, IN::F, IN::F, IN::T/*D*/,IN::T/*E*/, IN::F, IN::T/*G*/, IN::F,IN::F, IN::F, /*K*/IN::T, IN::T/*L*/,IN::T/*M*/, IN::T/*N*/, IN::F,\
	IN::F,	IN::F, IN::T/*R*/, IN::T/*S(83)*/, IN::F,	IN::F, IN::F, IN::F, IN::I,	'!', IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F/*95*/,\
	IN::F,/*a*/IN::T, IN::F, IN::F, /*d*/IN::T,IN::T/*e*/, IN::F, IN::T/*g*/, IN::F,IN::F, IN::F, IN::T/*k*/, IN::T/*l*/,IN::T/*m*/, /*n*/IN::T, IN::F,\
	IN::F,	IN::F, /*r*/IN::T, IN::T/*s*/, IN::F,IN::F, IN::F, IN::F, IN::F,IN::F, IN::F, IN::F, IN::F,IN::F, IN::F, IN::F/*127*/,\
																													\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
/*А*/'-',IN::F, IN::F, IN::T/*Г*/, IN::T/*Д*/,IN::T/*E*/, IN::F, IN::F, IN::F,	IN::F, /*К*/IN::T,IN::T/*L*/, IN::T/*M*/, IN::T/*H*/, IN::F, IN::F,\
	IN::T/*Р*/,  IN::T/*С*/, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
/*а*/IN::T,	IN::F, IN::F, IN::T/*г*/, /*д*/IN::T,/*е*/IN::T, IN::F, IN::F, IN::T,IN::T,/*к*/ IN::T, IN::T/*л*/, IN::T/*м*/, /*н*/IN::T,IN::F, IN::F/*239*/,\
/*р*/IN::T,/*с*/IN::T, IN::F, IN::F, IN::F,IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*255*/\
					}

namespace In
{
	struct IN    //исходные данные
	{
		enum { T = 1024, F = 2048, I = 4096 };  //Т -допустимый символ, F - недопустимый, I - игнорировать или заменить(если игн. невозможно)
		int size;
		int lines;							//число строк
		int ignor;							//Колич-во I - символос
		unsigned char* text;				//(исходный код в Win-1251)
		int code[256] = IN_CODE_TABLE;		//в таблице проверки: T/F/I - новое зн-е
	};
	IN getin(wchar_t infile[]);
}