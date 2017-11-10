#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QString WindowTitle("CSV Reader");
     this->setWindowTitle(WindowTitle);
}

MainWindow::~MainWindow()
{
    delete ui;
    //checking commits
}
