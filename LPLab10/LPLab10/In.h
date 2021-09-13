#pragma once

#define IN_MAX_LEN_TEXT 1024*1024	//������������ ������ ���. ���� 1.048 ��
#define IN_CODE_ENDL '\n'			//������. ������: ������� �� ����� ������
// ������� �������� ������� ����������, ������ ��� ��� ������� � Win-1251
//IN::F - ����������� ������, IN::T - ����������� ������, IN::I - ������������ (�� �������)
// ���� 0<= ����-� <=256 - �� �������� ������ ��-�.
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
/*�*/'-',IN::F, IN::F, IN::T/*�*/, IN::T/*�*/,IN::T/*E*/, IN::F, IN::F, IN::F,	IN::F, /*�*/IN::T,IN::T/*L*/, IN::T/*M*/, IN::T/*H*/, IN::F, IN::F,\
	IN::T/*�*/,  IN::T/*�*/, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
/*�*/IN::T,	IN::F, IN::F, IN::T/*�*/, /*�*/IN::T,/*�*/IN::T, IN::F, IN::F, IN::T,IN::T,/*�*/ IN::T, IN::T/*�*/, IN::T/*�*/, /*�*/IN::T,IN::F, IN::F/*239*/,\
/*�*/IN::T,/*�*/IN::T, IN::F, IN::F, IN::F,IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*255*/\
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