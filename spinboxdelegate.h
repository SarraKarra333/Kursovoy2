#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QStyledItemDelegate>

class SpinBoxDelegate : public QStyledItemDelegate
{
public:
    SpinBoxDelegate(QWidget *parent = nullptr);
    ~SpinBoxDelegate();

    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;


    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const;

    void setModeData(QWidget *editor,
                     QAbstractItemModel *model,
                     const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
};

#endif // SPINBOXDELEGATE_H
