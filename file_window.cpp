#include "file_window.h"
#include <QByteArray>
#include <QLineEdit>
#include <QStringList>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
File_Window::File_Window(QWidget *parent,int file_month,QString input_file) : QMainWindow(parent),
    month(file_month),
    the_file(input_file)

{
    QWidget* main_widget = new QWidget;
    QGridLayout* main_layout = new QGridLayout;

    QFile file(the_file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString message = the_file + " could not be found" ;
        QLabel* warning = new QLabel(message);
        main_layout->addWidget(warning);
    }
    else
    {

       QString data = file.readAll();
       QStringList vals = data.split(',');

        QLineEdit* tester = new QLineEdit( vals.front());

        main_layout->addWidget(tester,1,1);
    }

    main_widget->setLayout(main_layout);
    setCentralWidget(main_widget);


}


