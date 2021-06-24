#include "comboboxdelegate.h"
#include <QComboBox>

ComboBoxDelegate::ComboBoxDelegate(QObject *parent) :
    QItemDelegate(parent)
{

}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    QComboBox *combobox = new QComboBox(parent);


    if (index.column() == 4)
    {
        combobox->addItem("black");
        combobox->addItem("grey");
        combobox->addItem("white");
        combobox->addItem("black-white");
        combobox->addItem("black-read");
        combobox->addItem("red");
    }
    if (index.column() == 5)
    {
        combobox->addItem("YES");
        combobox->addItem("NO");

    }

    (void)option;
    (void)index;

    return combobox;
}

void ComboBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    QComboBox *combobox = static_cast<QComboBox *>(editor);
    combobox->setCurrentText(index.data().toString());
}

void ComboBoxDelegate::setModelData(QWidget *editor,
                                    QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QComboBox *combobox = static_cast<QComboBox *>(editor);
    model->setData(index, combobox->currentText());
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    (void)index;
}
