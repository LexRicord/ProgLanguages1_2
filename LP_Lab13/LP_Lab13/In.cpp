#include "stdafx.h"
#include "Error.h"
#include "In.h"

using namespace std;

namespace In
{
	IN getin(wchar_t infile[])
	{
		IN in_ex;
		in_ex.size = 0;
		in_ex.lines = 0;
		in_ex.ignor = 0;
		int cols = 0;

		unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];

		ifstream fin(infile);
		if (fin.fail()) throw ERROR_THROW(110);

		while (in_ex.size < IN_MAX_LEN_TEXT)
		{
			char k; fin.get(k);
			unsigned char uc = k;

			if (fin.eof()) //��� ������ � �������������� ������������ ����� eof() ���������� 1, ���� ��� ��������� ����� �����; � ��������� ������ ��� ���������� 0. � ������ ������ ��� ���������� �1
			{
				text[in_ex.size] = STRING_END_ZERO;
				break;
			}
			if (in_ex.code[uc] == in_ex.T)
			{
				text[in_ex.size] = uc;
				in_ex.size++;
				cols++;
			}
			else if (in_ex.code[uc] == in_ex.I)
			{
				in_ex.ignor++;
			}
			else if (in_ex.code[uc] == in_ex.F)
			{
				throw ERROR_THROW_IN(111, in_ex.lines, cols);
			}
			else
			{
				text[in_ex.size] = in_ex.code[uc];
				in_ex.size++;
				cols++;
			}
			if (uc == IN_CODE_ENDL)
			{
				in_ex.lines++;
				cols = 0;
			}
		}
		in_ex.text = text;
		return in_ex;
	}
	bool checkText(IN in, unsigned char uc, int cols, int lines)
	{
		if (in.code[uc] == in.F)
		{
			throw ERROR_THROW_IN(111, lines, cols);
		}
	}
}