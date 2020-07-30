
#include <mutex>
#include "DataManage.h"
#include "msgLog.h"
#include "srvInterface.h"

DataManage::DataManage()
{
	
}

DataManage::~DataManage()
{
}

DataManage * DataManage::ptrManager = nullptr;

DataManage * DataManage::getInstance()
{
	std::mutex mut;
	if (ptrManager == nullptr)
	{
		mut.lock();
		ptrManager = new DataManage();
		mut.unlock();
	}
	return ptrManager;
}
int DataManage::querySinglelTask()
{
	// 查询当前用户的表
	wstring strSelectSql = L"select * from tasklist where taskCate != 'sys_config' order by timeline;";

	while (true)
	{
		if (!initDb())
		{
			::Sleep(1000*60);
			continue;
		}

		vtrDbDatas	vtrDatas;
		SQLiteDataReader Reader = gDb.ExcuteQuery(strSelectSql.c_str());
		while (Reader.Read())
		{
			dbData	data;
			data.iId				= Reader.GetIntValue(0);
			data.strTaskCate		= decodeLpString(Reader.GetStringValue(1));
			data.strUserId			= decodeLpString(Reader.GetStringValue(2));
			data.strUserToken		= decodeLpString(Reader.GetStringValue(3));
			data.strAppId			= decodeLpString(Reader.GetStringValue(4));
			data.nAppType			= Reader.GetIntValue(5);
			data.strMsgId			= decodeLpString(Reader.GetStringValue(6));
			data.strComId			= decodeLpString(Reader.GetStringValue(7));
			data.strHzsId			= decodeLpString(Reader.GetStringValue(8));
			data.nResponseType		= Reader.GetIntValue(9);
			data.strBtnId			= decodeLpString(Reader.GetStringValue(10));
			vtrDatas.push_back(data);
		}
		Reader.Close();
		::Sleep(1000);

		vector<int> vec;
		srvInterface	sInter;
		bool bFlag = false;
		vtrDbDatas::iterator itr = vtrDatas.begin();
		for (; itr != vtrDatas.end(); ++itr)
		{
			if (itr->strTaskCate	==	 L"app_oper")
			{
				bFlag = sInter.WinHttpAppOperate((*itr).strUserId, (*itr).strUserToken, (*itr).strComId, (*itr).strHzsId, (*itr).strAppId, (*itr).nAppType);
			}
			
			else if (itr->strTaskCate == L"msg_oper")
			{
				bFlag = sInter.WinHttpMessageResponse((*itr).strUserId, (*itr).strUserToken, (*itr).strComId, (*itr).strHzsId,(*itr).strMsgId, (*itr).nResponseType, (*itr).strBtnId);
			}
			
			if (bFlag)
			{
				vec.push_back((*itr).iId);
			}
			else
			{
				wstring strMsg = (*itr).iId + L"interface failed";
				msgLog::WriteMsgToLog(strMsg.c_str());
			}
		}
		::Sleep(1000);
		
		vector<int>::iterator itrId = vec.begin();
		for (; itrId != vec.end();	++itrId)
		{
			wstring strSql = L"delete from tasklist where autoid=" + to_wstring((*itrId));
			if (!gDb.ExcuteNonQuery(strSql.c_str()))
			{
				LPCTSTR lpError = gDb.GetLastErrorMsg();
				msgLog::WriteMsgToLog(decodeLpString(lpError));
			}
		}
		vec.clear();
		::Sleep(60 * 1000);
	}
	return 0;
}

wstring DataManage::decodeLpString(LPCTSTR lpStr)
{
	if (NULL == lpStr)
	{
		return L"";
	}
	return wstring(lpStr);
}

BOOL DataManage::initDb()
{
	if (!gDb.checkDB())
	{
		wstring strFilePath = msgLog::getCurPath() + L"zhicloudServices.db";
		return gDb.Open(strFilePath.c_str());	
	}
	return true;
}
