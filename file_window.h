#ifndef FILE_WINDOW_H
#define FILE_WINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>


class File_Window : public QMainWindow
{
    Q_OBJECT
public:

    explicit File_Window(QWidget *parent = nullptr, int file_month = 0, QString input_file = " " );
    //virtual ~File_Window();
signals:

public slots:

private:
    int month;
    QString the_file;


};

#endif // FILE_WINDOW_H
