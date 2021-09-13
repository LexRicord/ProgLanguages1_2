#include "stdafx.h"	
#include "Out.h"	

#pragma warning(disable : 4996)
using namespace std;

namespace Out
{
	OUT getOut(wchar_t outFile[])
	{
		OUT out;
		out.stream = new ofstream;
		out.stream->open(outFile);
		if (out.stream->fail())
			throw ERROR_THROW(112);
		wcscpy_s(out.outFile, outFile);
		return out;
	}
	void outClose(OUT out)
	{
		out.stream->close();
		delete out.stream;
	}

}