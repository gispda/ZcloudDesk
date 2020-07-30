#ifndef DATAMANAG_H
#define DATAMANAG_H
#include <vector>
#include <string>
#include "CppSQLite3.h"

using namespace std;
struct dbData
{
	dbData()
	{
		iId = nAppType = nResponseType	=	0;
	}
	int iId;
	wstring strTaskCate;
	wstring strUserId;
	wstring strUserToken;
	wstring strAppId;
	int		nAppType;
	wstring strComId;
	wstring strHzsId;
	wstring strMsgId;
	int		nResponseType;
	wstring strBtnId;
};
typedef vector<dbData>	vtrDbDatas;

class DataManage
{
public:
	static DataManage * getInstance();
	~DataManage();
	BOOL initDb();
	int querySinglelTask();		

private:
	wstring decodeLpString(LPCTSTR lpStr);
	DataManage();
	static DataManage * ptrManager;
	SQLite gDb;
};

#endif