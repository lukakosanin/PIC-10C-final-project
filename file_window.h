#ifndef FILE_WINDOW_H
#define FILE_WINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>


class File_Window : public QMainWindow
{
    Q_OBJECT
public:

    explicit File_Window(QWidget *parent = nullptr, QString input_file = " " );

signals:

public slots:

private:
    QString the_file;


};

#endif // FILE_WINDOW_H
