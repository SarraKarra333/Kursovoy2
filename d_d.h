#ifndef d_d_H
#define d_d_H

#include <QTableWidget>
#include <QMouseEvent>

class d_d : public QTableWidget //drag and drop
{
    Q_OBJECT
public:
    d_d(QWidget* parent = nullptr);
private:

 //mousePressEvent метод улавливания позиции нажатия ЛКМ
 //event указатель на событие
    void mousePressEvent  (QMouseEvent * event );

 //mouseMoveEvent метод перетаскивания из mimedata в сторонние программы
    void mouseMoveEvent   (QMouseEvent * event );

 //dds координаты точки начала Drag & Drop
    QPoint dds;

};

#endif // d_d_H
