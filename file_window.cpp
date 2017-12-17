#include "file_window.h"
#include "basecell.h"
#include <QByteArray>
#include <QLineEdit>
#include <QStringList>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <algorithm>
#include <QScrollArea>
File_Window::File_Window(QWidget *parent, QString input_file) : QMainWindow(parent),
    the_file(input_file)

{
    QWidget* main_widget = new QWidget;


    QFile file(the_file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//open the file in read only mode and accepts '\n' as a new line
    {
        QGridLayout* error_layout = new QGridLayout;
        QString message = the_file + " could not be found" ;//display if the file could not be found
        QLabel* warning = new QLabel(message);
        error_layout->addWidget(warning);
        main_widget->setLayout(error_layout);
    }
    else
    {
       QGridLayout* main_layout = new QGridLayout;
       QString data = file.readAll();
       QStringList vals = data.split('\n');

       QStringList::iterator begin = vals.begin();
       QStringList::iterator end = vals.end();
       int rows1 = 0;
        while(begin!=end)//iterates through each row of the csv file and adds it to the main_layout grid
       {
            int columns1 = 0;
            QStringList more_vals = (*begin).split(',');
            QStringList::iterator begin2 = more_vals.begin();
            QStringList::iterator end2 = more_vals.end();
            if(rows1 == 0)//the first row is assumed to be the title row
            {
                while(begin2!=end2)
                {
                 BaseCell* cell = new BaseCell(this,2,2,*begin2);
                 main_layout->addWidget(cell,rows1,columns1);
                 ++columns1;
                 ++begin2;
                }
           }
            else{
                while(begin2!=end2)
                {
                    BaseCell* cell = new BaseCell(this, 2,2,*begin2);
                    main_layout->addWidget(cell,rows1,columns1);
                    ++columns1;
                    ++begin2;
                }

            }
           ++begin;
           ++rows1;

       }
       //std::for_each(vals.begin(),vals.end(),[&rows1,&cell,main_layout,&columns1]( QString& x)->QGridLayout*{cell->setText(x);main_layout->addWidget(cell,rows1,columns1);++rows1;return main_layout;});
       main_widget->setLayout(main_layout);
    }
    QScrollArea* the_center = new QScrollArea;//makes the central widget a scroll area
    the_center->setWidget(main_widget);
    the_center->setWidgetResizable(true);
    setCentralWidget(the_center);

    this->setWindowTitle(the_file);

}


