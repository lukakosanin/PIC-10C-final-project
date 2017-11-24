#include "file_window.h"

File_Window::File_Window(QWidget *parent,int file_month,QString input_file) : QMainWindow(parent),
    month(file_month),
    the_file(input_file)
    //ui(new Ui::File_Window),
{

    //ui->setupUi(this);
}
/*File_Window::~File_Window()
{
    delete ui;
}*/
