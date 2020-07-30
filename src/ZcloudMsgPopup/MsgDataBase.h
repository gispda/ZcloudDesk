#ifndef MSGDATABASE_H
#define MSGDATABASE_H

#include <QObject>
#include <QReadWriteLock>
#include <QSqlDatabase>
//!��Ϣ�ṹ��
class stMsgInfo
{
public:
	QString     _strUid;
	QString     _strToken;
	QString		_strCompId;
	int			_nMsgType = 0;					//!��Ϣ����(1����ͨ��Ϣ 2��ͼƬ��Ϣ 3�������ظ� 4������ѵ��ڡ���������ӻ����д������Ǳߵ���Ϣ)
	QString		_strMsgId;						//!��Ϣ��� 
	QString     _strFeedBackId;					//!����������
	QString     _strMsgTitle;					//!��Ϣ����
	QString		_strMsgContent;					//!��Ϣ���ݣ�������ϸ��Ϣչʾ�;��е���
	QString		_strAbstruct;					//!����ժҪ(�������½ǵ���)
	int			_nPosition = 0;					//!��Ϣλ��(0������1���½�2���е���)
	int			_nSendTime = 0;					//!��Ϣ����ʱ��
	int			_nValidStartTime = 0;			//!��Ч��ʼʱ��(Ϊ0ֱ����Ч)
	int			_nValidEndTime = 0;				//!��Ч����ʱ��(Ϊ0������Ч)
	int         _nTargetType = 0;				//!����ָ������(1��ת����2��תӦ��3������)
	QString     _strTarget;						//!����ָ��(����_nTargetType:1���ӵ�ַ2Ӧ�ñ��3�����(+�̶����ӵ�ַ))
	QByteArray  _arryBtnList = QByteArray();	//!��ť�б�
	bool		_bIsRead = false;				//!�Ƿ��Ѷ�
	bool		_bIsOld = false;				//!������¼�Ƿ�����ǰ�汾ͬ������
};

//!��Ϣ��ť�ṹ��
class stMsgBtnInfo
{
public:
	QString     _strBtnId;
	QString     _strBtnName;
	int			_nBtnType = 0;					//!��ť����((0���йر�1��ת����2��תӦ��3������4���½ǲ�水ť5�鿴����))
	QString		_strBtnTarget;					//!��ťָ��(����btn_typ:0��1���ӵ�ַ2Ӧ�ñ��3�����) 
};
class MsgDataBase : public QObject
{
	Q_OBJECT

public:
	
	~MsgDataBase();

	static MsgDataBase *GetInstance();
	static void DestoryInstance();

	//!��ѯ��Ϣ
	bool queryMsgInfo(QString strUid, QString strToken,QString strComId, QString strMsgId, stMsgInfo& msgInfo);
	
private:
	//!�ж����ݿ���Ƿ����
	bool isTableExist(QString strTableName);

	//�����ݿ�
	bool openMsgDatabase();

	//!������ݿⲻ�����򴴽�
	bool CreateDB(QString strPath);

	explicit MsgDataBase(QObject *parent = 0);

	QReadWriteLock		m_ReadWriteLock;
	QSqlDatabase		m_DataBase;
	static MsgDataBase*	m_pDbInstance;
};

#endif // MSGDATABASE_H
