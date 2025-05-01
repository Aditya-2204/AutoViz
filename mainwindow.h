#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonArray>
#include <QProcess>
#include <QTcpSocket>
#include <QFileSystemWatcher>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTcpSocket *socket;
    QByteArray buffer;
    Ui::MainWindow *ui;
    QProcess *simProcess = new QProcess(); //Start and End Simulation Server
    QFileSystemWatcher *watcher = new QFileSystemWatcher();

private slots:
    void startProject();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
