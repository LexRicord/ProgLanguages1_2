#pragma once

#define IN_MAX_LEN_TEXT 1024*1024	//������������ ������ ���. ���� 1.048 ��
#define IN_CODE_ENDL '\n'			
#define STRING_END_ZERO '\0'
#define SEPARATOR_1 '|'
#define IN_CODE_TABLE {\
IN::T,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	'|'/*\n*/,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*15*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*31*/\
IN::I,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*47*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*63*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::I,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*79*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::I,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*95*/\
IN::F,	/*a*/IN::T,	/*b*/IN::T,	/*c*/IN::T,	IN::T/*d*/,	/*e*/IN::T,	IN::T/*f*/,	IN::T/*g*/,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	/*m*/IN::T,	IN::F,	IN::F,/*111*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	/*|*/IN::T,	IN::F,	IN::F,	IN::F,/*127*/\
\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*143*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*159*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*175*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*191*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	/*H*/IN::I,	IN::F,	IN::F,/*207*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*223*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,/*239*/\
IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F,	IN::F/*255*/\
}

namespace In
{
	struct IN    //�������� ������
	{
		enum { T = 1024, F = 2048, I = 4096 };  //� -���������� ������, F - ������������, I - ������������ ��� ��������(���� ���. ����������)
		int size;
		int lines;							//����� �����
		int ignor;							//�����-�� I - ��������
		unsigned char* text;				//(�������� ��� � Win-1251)
		int code[256] = IN_CODE_TABLE;		//� ������� ��������: T/F/I - ����� ��-�
	};
	IN getin(wchar_t infile[]);
}