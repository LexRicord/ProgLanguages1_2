#include "stdafx.h"
#include "Log.h"
#include "Parm.h"
#include "In.h"
#include "Error.h"
#define FST_2(x) FST::FST myFST(x, 7, \
FST::NODE(1, FST::RELATION('a', 1)), \
FST::NODE(3, FST::RELATION('b', 1), FST::RELATION('b', 2), FST::RELATION('g', 6)), \
FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('e', 3), FST::RELATION(0x00, 4)), \
FST::NODE(1, FST::RELATION('f', 4)), \
FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('e', 3), FST::RELATION('b', 5)),\
FST::NODE(2, FST::RELATION('b', 5), FST::RELATION('g', 6)), \
FST::NODE())

int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "ru");

	std::cout << "---- Тест функций из таблицы  ---" << std::endl << std::endl;
	Log::LOG	log = Log::INITLOG;
	char checkString[PARM_MAX_SIZE];
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Тест: ", "без ошибок ", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		FST::CHECK_FST check_session_one = { 1,0 };
		for (int i = 0, j = 0; i < strlen((char*)in.text); j++)
		{
			checkString[i++] = in.text[j];
			check_session_one.position = i;
			if (checkString[i - 1] == SEPARATOR_1)
			{
				checkString[i - 1] = STRING_END_ZERO;
				i = 0;
				if (checkString[0] != STRING_END_ZERO)
				{
					FST_2(checkString);
					if (FST::execute(myFST))
					{
						std::cout << "\nЦепочка " << myFST.string << " распознана.\n";
						*log.stream << "\nЦепочка " << myFST.string << " распознана.\n";
					}
					else
					{
						std::cout << "\nЦепочка " << myFST.string << " не распознана.\n";
						*log.stream << "\nЦепочка " << myFST.string << " не распознана.\n";
						std::cout << "Номер цепочки:  " << check_session_one.str_line << ". Позиция ошибки в цепочке: " << myFST.position + 1 << std::endl;
						*log.stream << "Номер цепочки:  " << check_session_one.str_line << ". Позиция ошибки в цепочке : " << myFST.position + 1 << " \n";
					}
					check_session_one.str_line++;
				}
			}
		}
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	system("pause");
	return 0;

}