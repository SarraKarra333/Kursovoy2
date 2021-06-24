#include "spinboxdelegate.h"
#include <QSpinBox>

SpinBoxDelegate::SpinBoxDelegate(QWidget *parent):
    QStyledItemDelegate(parent)
{

}

SpinBoxDelegate::~SpinBoxDelegate()
{

}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &option,
                                       const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);

    editor->setMinimum(1);
    editor->setMaximum(10);

    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.data().toInt();

    QSpinBox *spinBox = qobject_cast<QSpinBox *>(editor);
    spinBox->setValue(value);
}

void SpinBoxDelegate::setModeData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinbox = qobject_cast<QSpinBox *>(editor);

    int value = spinbox->value();

    model->setData(index, value);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
