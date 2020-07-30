#ifndef MSGDATABASE_H
#define MSGDATABASE_H

#include <QObject>
#include <QReadWriteLock>
#include <QSqlDatabase>
//!消息结构体
class stMsgInfo
{
public:
	QString     _strUid;
	QString     _strToken;
	QString		_strCompId;
	int			_nMsgType = 0;					//!消息类型(1、普通消息 2、图片消息 3、反馈回复 4、服务费到期。其他待添加还会有大数据那边的消息)
	QString		_strMsgId;						//!消息编号 
	QString     _strFeedBackId;					//!意见反馈编号
	QString     _strMsgTitle;					//!消息标题
	QString		_strMsgContent;					//!消息内容（用于详细信息展示和居中弹框）
	QString		_strAbstruct;					//!正文摘要(用于右下角弹窗)
	int			_nPosition = 0;					//!消息位置(0不弹窗1右下角2居中弹窗)
	int			_nSendTime = 0;					//!消息发送时间
	int			_nValidStartTime = 0;			//!有效开始时间(为0直接有效)
	int			_nValidEndTime = 0;				//!有效结束时间(为0永久有效)
	int         _nTargetType = 0;				//!正文指向类型(1跳转链接2跳转应用3弹出表单)
	QString     _strTarget;						//!正文指向(关联_nTargetType:1链接地址2应用编号3表单编号(+固定链接地址))
	QByteArray  _arryBtnList = QByteArray();	//!按钮列表
	bool		_bIsRead = false;				//!是否已读
	bool		_bIsOld = false;				//!本条记录是否是以前版本同步而来
};

//!消息按钮结构体
class stMsgBtnInfo
{
public:
	QString     _strBtnId;
	QString     _strBtnName;
	int			_nBtnType = 0;					//!按钮类型((0居中关闭1跳转链接2跳转应用3弹出表单4右下角叉叉按钮5查看更多))
	QString		_strBtnTarget;					//!按钮指向(关联btn_typ:0空1链接地址2应用编号3表单编号) 
};
class MsgDataBase : public QObject
{
	Q_OBJECT

public:
	
	~MsgDataBase();

	static MsgDataBase *GetInstance();
	static void DestoryInstance();

	//!查询消息
	bool queryMsgInfo(QString strUid, QString strToken,QString strComId, QString strMsgId, stMsgInfo& msgInfo);
	
private:
	//!判断数据库表是否存在
	bool isTableExist(QString strTableName);

	//打开数据库
	bool openMsgDatabase();

	//!如果数据库不存在则创建
	bool CreateDB(QString strPath);

	explicit MsgDataBase(QObject *parent = 0);

	QReadWriteLock		m_ReadWriteLock;
	QSqlDatabase		m_DataBase;
	static MsgDataBase*	m_pDbInstance;
};

#endif // MSGDATABASE_H
