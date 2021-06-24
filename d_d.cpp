#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "d_d.h"

#include <QMimeData>
#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include <QMouseEvent>
#include <QString>

d_d::d_d(QWidget *parent): QTableWidget(parent)
{

}

void d_d::mousePressEvent(QMouseEvent *event)
{
QTableWidget::mousePressEvent(event);
dds = event->pos();
}

void d_d::mouseMoveEvent(QMouseEvent *event)
{
    QString str;
     if (( event->buttons() & Qt::LeftButton ) && QApplication::startDragDistance() <= ( event->pos() - dds ).manhattanLength())
     {

    QModelIndex id = indexAt(event->pos());
    if(id.isValid())
    {
        setDragDropMode(QAbstractItemView::DragDrop);

        for (int i = 0; i < 10; i++)
        {
            str += item(currentItem()->row(), i)->text() + ";";
        }
          QDrag *drag = new QDrag(this);
          QMimeData * mimeData = new QMimeData();
          mimeData -> setText(str);
          drag -> setMimeData(mimeData);
          drag -> exec();
        }
    else
    {
        setDragDropMode(QAbstractItemView::NoDragDrop);
    }
  }
}
