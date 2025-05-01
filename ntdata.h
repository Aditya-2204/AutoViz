#ifndef NTDATA_H
#define NTDATA_H


#include <QTcpSocket>
#include <QTextEdit>
#include <QJsonObject>
#include <QProcess>

void startServer(QProcess *process);
void connectToNT(QTcpSocket *socket);
QJsonObject extractModuleData(QTcpSocket *socket, QByteArray buffer);

#endif // NTDATA_H
