#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void newActionSlot();
    void openActionSlot();
    void saveActionSlot();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
