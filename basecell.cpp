#include "basecell.h"

BaseCell::BaseCell(QWidget *parent, int height, int width, QString the_data) : QWidget(parent),
    cell_height(height), cell_width( width), cell_data(the_data), display(new QLabel),
     the_shape(QRect(0,height,width,height)),the_box(new QHBoxLayout)
{
    //the_shape->adjust(0,cell_height,cell_width,cell_height);
    display->setText(the_data);
    the_box->addWidget(display);
    the_box->setGeometry(the_shape);
    this->setLayout(the_box);
    this->show();
}
void BaseCell::set_height(int new_height)
{
    cell_height = new_height;
}
void BaseCell::set_width(int new_width)
{
    cell_width = new_width;
}
BaseCell::~BaseCell()
{
    delete display;
    delete the_box;
}

