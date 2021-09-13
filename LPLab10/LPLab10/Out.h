#pragma once

#include "stdafx.h"
#include "In.h"
#include "Parm.h"	
#include "Error.h"	

namespace Out   //������ � ������ ��������� 
{
	struct OUT	//�����. ��� - ��������.
	{
		wchar_t outFile[PARM_MAX_SIZE]; //��� �����
		std::ofstream* stream;			//�������� ����� ���������
	};

	static const OUT INITLOG = { L"", NULL };		//��������� ��� �������. ����. ���� OUT
	OUT getOut(wchar_t outFile[]);					//������������ ���. OUT
	void outClose(OUT out);							//������� ���� ���������� ����
};
