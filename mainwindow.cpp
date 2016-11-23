#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dir_file_operations.h"
QString dir_path="/home/td/Belgeler/test/";
QDir my_direc;
QString file_path="/home/td/Belgeler/test/test.txt";
QFile my_file(file_path);
QTimer my_timer;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(!my_file.open(QFile::WriteOnly|QFile::Text))
        ui->textEdit->append("Write Error:File can not open...");
    else
    {
        QTextStream my_write_stream(&my_file);
    my_write_stream << "Write there some things";
        ui->textEdit->append("Writing success...");
    my_file.flush();
    my_file.close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    my_timer.start(10000);

}
void MainWindow::on_pushButton_3_clicked(){
 if(my_direc.rmdir(dir_path))
     ui->textEdit->append("Directory removed!");
 else
     ui->textEdit->append("Directory can not removed");
}

void MainWindow::on_Check_Dir_clicked()
{


    if(my_direc.exists(dir_path))
        ui->textEdit->append("Directory exist...");
    else
    {
        ui->textEdit->append("Directory doesn't exist...");
    }
}

void MainWindow::on_say_hello_clicked()
{
    ui->textEdit->append("Hello Human!");
}

void MainWindow::on_fuck_it_clicked()
{

    if(my_file.remove() && my_direc.rmpath(dir_path)){
    ui->textEdit->clear();
    ui->textEdit->append("Fucked!");
    }
}

void MainWindow::on_Create_Dir_clicked()
{
    if(my_direc.exists(dir_path))
        ui->textEdit->append("Directory exist...");
    else
    {
            if(my_direc.mkpath(dir_path))
                ui->textEdit->append("Directory created");
            else
                ui->textEdit->append("Directory can not created!");
    }
}

void MainWindow::on_Check_File_clicked()
{

    if(my_file.exists())
        ui->textEdit->append("File already exist.");
    else
        ui->textEdit->append("File doesn't exist.");


}

void MainWindow::on_Create_File_clicked()
{

    if(my_file.open(QFile::WriteOnly | QFile::Truncate))
        ui->textEdit->append("File created.");
}

void MainWindow::on_Display_File_clicked()
{
    if(!my_file.open(QFile::ReadOnly|QFile::Text))
        ui->textEdit->append("File can not open...");
    QTextStream my_stream(&my_file);
    QString file_stream = my_stream.readAll();
    ui->textEdit->append(file_stream);
    my_file.flush();
    my_file.close();
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString line_text=ui->lineEdit->text();
    ui->textEdit->append(line_text);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(my_file.remove())
        ui->textEdit->append("File removed!");
}

void MainWindow::on_actionExit_triggered()
{
    quick_exit(1);
}
