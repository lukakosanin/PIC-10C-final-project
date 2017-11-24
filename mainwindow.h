#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <QFileDialog>
#include <QLineEdit>
#include <QStringList>
#include <QComboBox>

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
     void choose_month(int);
     void new_window();
private:
    Ui::MainWindow *ui;
    QString chosen_file;
    QLineEdit* show_file;
    int chosen_month;
    QComboBox* months;
};


#endif // MAINWINDOW_H
