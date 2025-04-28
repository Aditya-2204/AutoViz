#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRect>
#include <QScreen>
#include <QProcess>
#include <QResizeEvent>
#include <QDebug>
#include <QDir>
#include <QTcpSocket>
#include "ntdata.h"
#include "managejson.h"

#include <QJsonDocument>
#include <QtCore/qjsonobject.h>
#include <chrono>
#include <thread>
#include <QCloseEvent>
#include <signal.h>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    socket=new QTcpSocket(this);

    // Set window title and scale background
    setWindowTitle("Auto Vizualizer - FRC 9289");

    // Connect button click to getNTData function
    connect(ui->openProjects, &QPushButton::clicked, this, &MainWindow::startProject); /*startServer is in NTData.h and starts NT server */

    QDir dir;
    QString cwd = dir.currentPath();
    cwd.remove("/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/AutoViz.app/Contents/MacOS");
    QString configPath = "/NTData/config.json";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    QSize size = event->size();

    int padding = 20;

    // Set width and height dynamically
    int x = ui->viewProjects->x();
    int y = ui->viewProjects->y();
    int widthBuffer = 133;
    ui->viewProjects->setGeometry(x, y, size.width() - widthBuffer - padding, size.height() -  padding);

    // Update background geometry (optional)
    ui->background->setGeometry(0, 0, size.width(), size.height());
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (socket && socket->isOpen()) {
        qInfo() << "Disconnecting socket...";
        socket->disconnectFromHost();

        // Wait for the socket to disconnect, but only if it was open
        if (socket->state() == QAbstractSocket::ConnectedState) {
            if (!socket->waitForDisconnected(1000)) {
                qWarning() << "Socket didn't disconnect cleanly:" << socket->errorString();
            }
        } else {
            qInfo() << "Socket was already disconnected.";
        }

        qDebug() << "PID:" << simProcess->processId();

    }



    if (simProcess && simProcess->state() != QProcess::NotRunning) {
        simProcess->terminate();
        if (!simProcess->waitForFinished(3000)) {  // 3 seconds to wait for a clean exit
            simProcess->kill();  // Force kill if not terminated
        }
    }

    qInfo() << "AutoViz is closing.";
    event->accept();
}



void MainWindow::startProject() {


    //TODO - ADD A DIRECTORY NAVIGATING FEATURE
    QString directory = QFileDialog::getExistingDirectory(this, "Select Folder", "", QFileDialog::ShowDirsOnly);  //TEST

    if (!directory.isEmpty()) {
        qDebug() << "Folder selected:" << directory;
        // Use the selected directory path...
    }

    QDir dir;
    QString cwd = dir.currentPath();
    cwd.remove("/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/AutoViz.app/Contents/MacOS");
    QString configPath = "/NTData/config.json";




    writeJson(configPath, "file-directory", directory);



    startServer(simProcess); // from ntdata.h - START SIMULATION SERVER ON LOCALHOST

    connectToNT(socket); // fron ntdata.h
    connect(socket, &QTcpSocket::readyRead, this, [=]{
        extractModuleData(socket,ui->displayModule); //Continuously extract module data fromthe sim when the Tcp is ready
    });


}

