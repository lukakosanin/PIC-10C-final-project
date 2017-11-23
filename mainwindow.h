#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <QFileDialog>
#include <QLineEdit>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
     void file_chooser();
private:
    Ui::MainWindow *ui;
    QString chosen_file;
    QLineEdit* show_file;
};


#endif // MAINWINDOW_H
