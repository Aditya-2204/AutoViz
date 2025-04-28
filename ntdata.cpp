#include "ntdata.h"
#include "managejson.h"

#include <QProcess>
#include <QDir>
#include <QtNetwork/QTcpSocket>

#include <QStringList>

#include <QJsonDocument>

#include <chrono>
#include <thread>

#include <QTextEdit>

#include <QThread>

#include <QTextEdit>

void startServer(QProcess *process /*Import pre-existing nullptr
                                    process to start and end the
                                    same process - that is the
                                    sim server*/
                ){
    QDir dir;
    QString cwd = dir.currentPath(); //get current path
    cwd.remove("/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/AutoViz.app/Contents/MacOS"); //navigate to code directory


    process->setWorkingDirectory(cwd);


    //Manage child process
    process->setProcessChannelMode(QProcess::MergedChannels);
    process->start("python3", QStringList() << "NTData/main.py"); //Run python prgm

    //process->terminate(); //End the program gracefully
}


void connectToNT(QTcpSocket *socket /*This nullptr is to mitigate
                                    the same socket being called
                                    twice*/
                ){
    QDir dir;
    QString cwd = dir.currentPath();
    cwd.remove("/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/AutoViz.app/Contents/MacOS");
    QString configPath = "/NTData/config.json";


    std::this_thread::sleep_for(std::chrono::milliseconds(2500)); //Wait for the port variable in config.json to update, precisely 2500ms
    QJsonObject config = readJson(cwd + configPath);
    int port = config.value("free-port").toInt();

    qInfo() << "Connecting to localhost @ port: " << port;
    socket->connectToHost(QHostAddress::LocalHost, port);

    // Wait for connection with timeout
    if (!socket->waitForConnected(2000)) {
        qWarning() << "Failed to connect:" << socket->errorString();
        return;
    }
    qInfo() << "Connected!";
}

QJsonObject extractModuleData(QTcpSocket *socket, QTextEdit *textEdit) {
    QThread::msleep(1000);
    QByteArray data = socket->readAll();
    qInfo() << "Received: " << data;
    return QJsonObject();

}



