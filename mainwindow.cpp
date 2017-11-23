#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QComboBox>
#include <QLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QLabel>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    chosen_file(""),
    show_file(new QLineEdit("..."))
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
    QHBoxLayout* right_lay = new QHBoxLayout;
    QWidget* choose_file = new QWidget;
    QGridLayout* center = new QGridLayout;
    QPushButton* browser = new QPushButton("Browse");
    QLabel* title = new QLabel("Please choose a CSV file...");

    connect(browser,SIGNAL(clicked(bool)),this,SLOT(file_chooser()))

    right_lay->addWidget(title);
    right_lay->addWidget(browser);
    choose_file->setLayout(right_lay);

    center->addWidget(months,0,0);
    center->addWidget(choose_file,0,1);
    center->addWidget(show_file,1,1);
    center_tile->setLayout(center);
    setCentralWidget(center_tile);
}
void MainWindow::file_chooser()
{
   chosen_file = QFileDialog::getOpenFileName(this,("Select your file"),"/Macintosh HD",("All Files(*.*);;SV files (*.csv)"));
   show_file->setText(chosen_file);
}

MainWindow::~MainWindow()
{
    delete ui;
}
