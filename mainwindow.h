#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Check_Dir_clicked();

    void on_say_hello_clicked();

    void on_fuck_it_clicked();

    void on_Create_Dir_clicked();

    void on_Check_File_clicked();

    void on_Create_File_clicked();

    void on_Display_File_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_4_clicked();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
