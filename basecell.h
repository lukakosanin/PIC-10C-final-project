#ifndef BASECELL_H
#define BASECELL_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QRect>
/* an abstract class for the cells that will be in the file_window box. It is abstract becuase
 I want to make cells that are either title cells or data cells that will inherit from this class
 but no base cells should be made */

class BaseCell : public QWidget
{
    Q_OBJECT
public:
    explicit BaseCell(QWidget *parent = nullptr, int height = 1,int width = 1, QString the_data = " ");
    virtual ~BaseCell();
    virtual void set_height(int new_height);
    virtual void set_width(int new_width);

signals:

public slots:

private:
     QRect the_shape;
    int cell_height;
    int cell_width;
    QString cell_data;
    QLabel* display;
    QHBoxLayout* the_box;
};


#endif // BASECELL_H
