#ifndef NTDATA_H
#define NTDATA_H


#include <QTcpSocket>
#include <QJsonObject>
#include <QProcess>

void startServer(QProcess *process);
void connectToNT(QTcpSocket *socket);
QJsonObject extractModuleData(QTcpSocket *socket, QByteArray buffer);
QVector2D computeRobotVelocity(const QJsonObject &modules);

#endif // NTDATA_H
