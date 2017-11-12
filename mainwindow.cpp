#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QComboBox>
#include <QLayout>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString WindowTitle("CSV Reader");
    this->setWindowTitle(WindowTitle);
    QWidget* center_tile = new QWidget;
    QComboBox* months = new QComboBox;
    months ->addItem("January");
    months ->addItem("February");
    months ->addItem("March");
    months ->addItem("April");
    months ->addItem("May");
    months ->addItem("June");
    months ->addItem("July");
    months ->addItem("August");
    months ->addItem("September");
    months ->addItem("October");
    months ->addItem("November");
    months ->addItem("December");
    QLineEdit* file_to_read = new QLineEdit;
    QGridLayout* center = new QGridLayout;

    center->addWidget(months,0,0);
    center->addWidget(file_to_read,0,1);

    center_tile->setLayout(center);
    setCentralWidget(center_tile);
}
/*void MainWindow::set_month(QString month)
{

}*/
MainWindow::~MainWindow()
{
    delete ui;
}
