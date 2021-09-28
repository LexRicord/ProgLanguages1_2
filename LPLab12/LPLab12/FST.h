#include "stdafx.h"

namespace FST {
	struct RELATION {			//вершина графа перехода КА (ребро:символ)
		char symbol;			//символ перех.
		short nnode;			//номер смежной верщ.
		RELATION(				//конструктор 
			char c = 0x00,			//символ перехода*(пустая цепочка)
			short ns = NULL			//новое сост.
		);
	};
	/*RELATION::RELATION(char c, short ns) {
		symbol = c;
		nnode = ns;
	};*/
	struct NODE {
		short n_relation;		//кол-во рёбер перехода
		RELATION* relations;		//ребра
		NODE();
		NODE(
			short n,
			RELATION rel, ...
		);
	};
	//NODE::NODE() {  //default(empty) state of vertex/node 
	//	n_relation = 0;
	//	RELATION relations = NULL;
	//};

	//NODE::NODE(short n, RELATION rel, ...) {    //function overloading(with parameters)
	//	n_relation = n;
	//	RELATION* p = &rel;
	//	relations = new RELATION[n];
	//	for (short i = 0; i < n; i++) relations[i] = p[i];
	//};
	struct FST {				//НКА
		char* string;			//цепочка (строка, зав-ся 0x00)
		short position;			//текущая поз.
		short nstates;			//number of states of the automaton
		NODE* nodes;			//transition graph: [0] - start state, final state [nstates - 1](last is 0x00)
		short* rstates;			//possible states 
		FST(
			char* s,
			short ns,
			NODE n, ...
		);
	};
	//FST::FST(char* s, short ns, NODE n, ...)
	//{
	//	string = s;
	//	nstates = ns;
	//	nodes = new NODE[ns];
	//	NODE* ptr = &n;
	//	for (short k = 0; k < ns; k++) nodes[k] = ptr[k];
	//	short* rstates = new short[nstates];
	//	memset(rstates, -1, sizeof(short) * nstates);
	//	rstates[0] = 0;   //S(-1)-state
	//	position = -1;
	//};
	/*struct CHECK_FST
	{
		int str_line;
		int position;
	};*/
	bool step(FST& fst, short* rstates);   //single char. recognition
	bool execute(FST& fst);   //execute the sequence recoginition 
	
};