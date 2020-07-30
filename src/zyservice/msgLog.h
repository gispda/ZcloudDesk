#pragma once
#include <mutex>
#include <string>
#define LOGFILE L"c:\\Msg.log"
using namespace std;
static mutex writeMutex;

class msgLog
{
public:
	msgLog();
	~msgLog();

	static wstring getCurPath();

	static wstring getKeyWord();

	static void WriteMsgToLog(wstring strMsg);
};

