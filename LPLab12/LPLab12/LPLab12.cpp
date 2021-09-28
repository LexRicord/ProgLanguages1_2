#include "stdafx.h"
#include <string.h>
//#define _MY_FST(x) FST::FST myFST(x, 6,\
//FST::NODE(1, FST::RELATION('a', 1)), \
//FST::NODE(6, FST::RELATION('b', 1), FST::RELATION('c', 2), FST::RELATION('e', 2), FST::RELATION('b', 2), FST::RELATION('d', 2), FST::RELATION('b', 2)), \
//FST::NODE(2, FST::RELATION('e', 3), FST::RELATION('b', 2)),\
//FST::NODE(6, FST::RELATION('c', 2), FST::RELATION('e', 2), FST::RELATION('b', 2), FST::RELATION('d', 2), FST::RELATION('b', 3), FST::RELATION('f', 4)),\
//FST::NODE(1, FST::RELATION('e', 5)),\
//FST::NODE())
void main()
{
	setlocale(LC_ALL, "Russian");
	const char* strA[SIZE_STR] = {"abbbbbg","abcfbg","abbdfbg","abbbbcfbg","abbbbbbefbg","abcfbbbbg","abbbcfbbbg","abcfdfefbg","abcfdfefbg"};
	char* str = new char[SIZE_STR];
	memset(str, 0, 9);
	char* strcpy(char* destination, const char* source);
	strcpy(str, strA[0]);
	for (int iter = 0; iter < SIZE_STR; iter++)
	{
		strcpy(str, strA[iter]);
		FST::FST myFST(str, 7,
			FST::NODE(1, FST::RELATION('a', 1)),
			FST::NODE(3, FST::RELATION('b', 1), FST::RELATION('b', 2), FST::RELATION('g', 6)),
			FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('e', 3), FST::RELATION(0x00,4)),
			FST::NODE(1, FST::RELATION('f', 4)),
			FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('e', 3), FST::RELATION('b', 5)),
			FST::NODE(2, FST::RELATION('b', 5), FST::RELATION('g', 6)),
			FST::NODE()
		);
		if (FST::execute(myFST))
		{
			std::cout << "Цепочка " << myFST.string << " распознана." << std::endl;
		}
		else
		{
			std::cout << "Цепочка " << myFST.string << " не распознана." << std::endl;
		}
	
	}
	system("pause");
}