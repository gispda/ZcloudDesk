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
    bool isRunning();               // 是否已经有实例在运行  
    QWidget *mainWindow;            // MainWindow指针 
	bool bZyServerRuning;			// 是否 是服务启动的程序
	void appDisConnect();			//断开链接
private slots:  
    // 有新连接时触发  
    void newLocalConnection();  
  
	void showZCloudDesk();

private:
    // 初始化本地连接  
    void initLocalConnection();  
    // 创建服务端  
    void newLocalServer();  
	
	bool bRunning;                  // 是否已经有实例在运行  
	
    QLocalServer *localServer;      // 本地socket Server  
    QString serverName;             // 服务名称 
};  
  
#endif // SINGLEAPPLICATION_H  