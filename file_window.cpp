#include "file_window.h"
#include <QByteArray>
#include <QLineEdit>
#include <QStringList>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <algorithm>

File_Window::File_Window(QWidget *parent, QString input_file) : QMainWindow(parent),
    the_file(input_file)

{
    QWidget* main_widget = new QWidget;


    QFile file(the_file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QGridLayout* error_layout = new QGridLayout;
        QString message = the_file + " could not be found" ;
        QLabel* warning = new QLabel(message);
        error_layout->addWidget(warning);
        main_widget->setLayout(error_layout);
    }
    else
    {
       QGridLayout* main_layout = new QGridLayout;
       QString data = file.readAll();
       QStringList vals = data.split('\n');

     // QLabel* the_data = new QLabel[rows][colums];
       QStringList::iterator begin = vals.begin();
       QStringList::iterator end = vals.end();
       int rows1 = 0, columns1=0;
       while(begin!=end)
       {
           QLabel* cell = new QLabel;
           cell->setText(*begin);
           ++begin;
           main_layout->addWidget(cell,rows1,columns1);
           ++rows1;

       }
       //std::for_each(vals.begin(),vals.end(),[&rows,cell,&main_layout,&colums]( QString x)->QGridLayout*{cell->setText(x);main_layout->addWidget(cell,rows,colums);++rows;return main_layout;});
       main_widget->setLayout(main_layout);
    }
    //main_widget->setFixedHeight(30);
    //main_widget->setFixedWidth(40);

    setCentralWidget(main_widget);


}


