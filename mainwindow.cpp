#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file_window.h"
#include <QString>
#include <QComboBox>
#include <QLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QLabel>
#include <QStringList>
#include <iostream>

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
    QHBoxLayout* right_lay = new QHBoxLayout;
    QWidget* choose_file = new QWidget;
    QGridLayout* center = new QGridLayout;
    QPushButton* browser = new QPushButton("Browse");
    QLabel* title = new QLabel("Please choose a CSV file...");
    QPushButton* next_button = new QPushButton("Read File");


    connect(browser,SIGNAL(clicked(bool)),this,SLOT(file_chooser()));
    connect(next_button,SIGNAL(clicked(bool)),this,SLOT(new_window()));

    right_lay->addWidget(title);
    right_lay->addWidget(browser);
    choose_file->setLayout(right_lay);



    center->addWidget(choose_file,0,0);
    center->addWidget(show_file,1,0);
    center->addWidget(next_button,2,2);
    center_tile->setLayout(center);
    setCentralWidget(center_tile);

}
void MainWindow::file_chooser()
{

   chosen_file = QFileDialog::getOpenFileName(this,("Select your file"),"/Macintosh HD",("All Files(*.*);;CSV files (*.csv)"));
   show_file->setText(chosen_file);
}
void MainWindow::new_window()
{
    File_Window* the_window = new File_Window(nullptr,chosen_file);
    the_window->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
