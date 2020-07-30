#ifndef SINGLEAPPLICATION_H  
#define SINGLEAPPLICATION_H  
  
#include <QObject>  
#include <QWidget>
#include <QLocalServer>
#include <QApplication>  
  
class SingleApplication : public QApplication  
{  
    Q_OBJECT  
public:  
    SingleApplication(int &argc, char **argv);  
	static SingleApplication *instance();
    bool isRunning();               // �Ƿ��Ѿ���ʵ��������  
    QWidget *mainWindow;            // MainWindowָ�� 
	bool bZyServerRuning;			// �Ƿ� �Ƿ��������ĳ���
	void appDisConnect();			//�Ͽ�����
private slots:  
    // ��������ʱ����  
    void newLocalConnection();  
  
	void showZCloudDesk();

private:
    // ��ʼ����������  
    void initLocalConnection();  
    // ���������  
    void newLocalServer();  
	
	bool bRunning;                  // �Ƿ��Ѿ���ʵ��������  
	
    QLocalServer *localServer;      // ����socket Server  
    QString serverName;             // �������� 
};  
  
#endif // SINGLEAPPLICATION_H  