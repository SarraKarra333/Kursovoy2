#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "midi.h"
#include "list.h"
#include "comboboxdelegate.h"
#include "spinboxdelegate.h"

#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readPosition();


    connect(ui->tableWidget,SIGNAL(activated(QModelIndex)),ui->tableWidget,SLOT(edit(QModelIndex)));
    ui->tableWidget->setItemDelegateForColumn(4, new ComboBoxDelegate(this));
    ui->tableWidget->setItemDelegateForColumn(5, new ComboBoxDelegate(this));
    ui->tableWidget->setItemDelegateForColumn(8, new SpinBoxDelegate(this));
    ui->tableWidget->setItemDelegateForColumn(9, new SpinBoxDelegate(this));


    m_menu = new QMenu( this );

    QAction* actionAdd = m_menu->addAction(tr("Add New"));
    QAction* actionDelete = m_menu->addAction(tr("Delete"));
    QAction* exitAction = m_menu->addAction(tr("Exit"));
    connect(actionAdd, &QAction::triggered, this, &MainWindow::on_actionAdd_triggered);
    connect(actionDelete, SIGNAL(triggered()), this, SLOT(on_actionDelete_triggered()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(on_actionExit_triggered()));

    connect(ui->pushButtonDel,SIGNAL(clicked()),this,SLOT(on_actionDelete_triggered()));
    connect(ui->pushButtonExit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButtonAdd,SIGNAL(clicked()),this,SLOT(on_actionAdd_triggered()));

}

MainWindow::~MainWindow()
{
    writePosition();
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    ui->tableWidget->clear();
    NewList.clear();
    midi NewMIDI;
    QString in;
    QString fileName=QFileDialog::getOpenFileName(this);
    QFile file1(fileName);
    if (fileName != "")
        {
        if (!file1.open(QIODevice::ReadOnly))
            {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
            }                           // Открытие файла
        QTextStream stream(&file1);
        while (!stream.atEnd())
        {
            line = stream.readLine();
            lineElems = line.split(";");
            midi newElem;

            newElem.SetBrand(lineElems.at(0));
            newElem.SetModel(lineElems.at(1));
            newElem.SetPrice(lineElems.at(2).toFloat());
            newElem.SetNumber_of_keys(lineElems.at(3).toInt());
            newElem.SetColor(lineElems.at(4));
            newElem.SetBacklight(lineElems.at(5));
            newElem.SetSize_of_keys(lineElems.at(6));

            NewList.append(newElem);
        }

        qDebug() << NewList.at(0).GetModel();

    }



    file1.close();
    TableUpdate();
}

void MainWindow::TableUpdate()
{


    ui->tableWidget->setColumnCount(7);
    QStringList Header;
    Header.append(tr("Brand"));
    Header.append(tr("Model"));
    Header.append(tr("Price"));
    Header.append(tr("Number of keys"));
    Header.append(tr("Color"));
    Header.append(tr("Backlight"));
    Header.append(tr("Size of keys"));
    ui->tableWidget->setRowCount(NewList.size());
    ui->tableWidget->setHorizontalHeaderLabels(Header); //присвоение заголовков
    int i = 0;
    int j = 0;

    for (int m=0;m<NewList.size();m++)
    {
        j= 0;

        QTableWidgetItem *one = new QTableWidgetItem(NewList.at(m).GetBrand());
        ui->tableWidget->setItem(i,j,one);
        j++;
        QTableWidgetItem *two = new QTableWidgetItem(NewList.at(m).GetModel());
        ui->tableWidget->setItem(i,j,two);
        j++;
        QTableWidgetItem *three = new QTableWidgetItem(QString::number(NewList.at(m).GetPrice()));
        ui->tableWidget->setItem(i,j,three);
        j++;
        QTableWidgetItem *four = new QTableWidgetItem(QString::number(NewList.at(m).GetNumber_of_keys()));
        ui->tableWidget->setItem(i,j,four);
        j++;
        QTableWidgetItem *five = new QTableWidgetItem(NewList.at(m).GetColor());
        ui->tableWidget->setItem(i,j,five);
        j++;
        QTableWidgetItem *six = new QTableWidgetItem(NewList.at(m).GetBacklight());
        ui->tableWidget->setItem(i,j,six);
        j++;
        QTableWidgetItem *seven = new QTableWidgetItem(NewList.at(m).GetSize_of_keys());
        ui->tableWidget->setItem(i,j,seven);
        i++;

    }

}

void MainWindow::on_actionSave_triggered()
{
    QFile save;
    QString savefile;
    savefile=QFileDialog::getSaveFileName(this, tr("Save File"), "",tr("Text file(*.txt);; Data File(*.dat);; Database File(*.db)") );
    save.setFileName(savefile);
    if(save.open(QIODevice::WriteOnly))
    {


        QTextStream outStream(&save);
        for (int i=0;i< ui->tableWidget->rowCount();i++)
        {   for (int j = 0; j< 8;j++)
            {
                outStream <<ui->tableWidget->item(i,j)->text()<<";";
            }
            outStream<<"\n";

        }
        save.close();
    }
}

void MainWindow::on_actionAdd_triggered()
{
    int r;
    r=ui->tableWidget->currentRow()+1;
    ui->tableWidget->insertRow(ui->tableWidget->currentRow()+1);
    midi newt;
    NewList.insert(r,newt);
}

void MainWindow::on_actionExit_triggered()
{

}

void MainWindow::on_actionAbout_triggered()
{
       QMessageBox::warning(this, tr("Information"),tr("Made by Ilya Klepikov IEUIS 2-5"), QMessageBox::Ok);
}

void MainWindow::on_actionDelete_triggered()
{
    if(ui->tableWidget->rowCount()==0)
    {
        QMessageBox::warning(this, tr("delete"),tr("List is empty"), QMessageBox::Ok);
    }
    else
    {
        int num = ui->tableWidget->currentRow();
        NewList.removeAt(num);
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());

    }
}

void MainWindow::writePosition() // Записывает расположение и размер окна
{
    QSettings qsettings( "pos1");
    qsettings.setValue( "geometry", saveGeometry() );

}

void MainWindow::readPosition()
{
    QSettings qsettings( "pos1");
    restoreGeometry(qsettings.value( "geometry", saveGeometry() ).toByteArray());

}

void MainWindow::on_pushButtonDiagram_clicked()
{

}

void MainWindow::contextMenuEvent( QContextMenuEvent* e )
{

    if( m_menu )
    {
        m_menu->exec( e->globalPos() ); //считывание позиции где было вызвано меню
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    e->setAccepted(true);
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *e)
{
    e->setAccepted(true);
}
void MainWindow::dropEvent(QDropEvent *e) //отпускание кнопки мыши
{

    QString data = e->mimeData()->text();
    QStringList list = data.split(";"); //разбиение строки ;


    QTableWidgetItem *ptr;



    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

    for(int i = 0 ; i<8 ; i++)
    {
        ptr = new QTableWidgetItem(list[i]);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,i,ptr); //вставка
    }


}

void MainWindow::on_actionRUS_triggered()
{
    QStringList Header;
    Header.append(tr("Брэнд"));
    Header.append(tr("Модель"));
    Header.append(tr("Цена"));
    Header.append(tr("Количество клавиш"));
    Header.append(tr("Цвет"));
    Header.append(tr("Подсветка"));
    Header.append(tr("Размер клавиш"));
    ui->tableWidget->setRowCount(NewList.size());
     ui->tableWidget->setHorizontalHeaderLabels(Header);
    ui->pushButtonAdd->setText("Добавить");
    ui->pushButtonDel->setText("Удалить");
    ui->pushButtonDiagram->setText("Диаграмма");
    ui->pushButtonExit->setText("Выход");
    ui->menuFile->setTitle("Файл");
    ui->actionAdd->setText("Добавить");
    ui->actionDelete->setText("Удалить");

    ui->actionNew->setText("Новый файл");
    ui->actionSave->setText("Сохранить");
    ui->actionExit->setText("Выход");

    ui->menuChange->setTitle("Изменить");
    ui->menuLanguage->setTitle("Язык");
    ui->menuAbout->setTitle("О программе");
    ui->actionAbout->setText("О программе");

}

void MainWindow::on_actionENG_triggered()
{
    QStringList Header;
    Header.append(tr("Brand"));
    Header.append(tr("Model"));
    Header.append(tr("Price"));
    Header.append(tr("Number of keys"));
    Header.append(tr("Color"));
    Header.append(tr("Backlight"));
    Header.append(tr("Size of keys"));
    ui->tableWidget->setRowCount(NewList.size());
     ui->tableWidget->setHorizontalHeaderLabels(Header);
    ui->pushButtonAdd->setText("Add");
    ui->pushButtonDel->setText("Delete");
    ui->pushButtonDiagram->setText("Diagram");
    ui->pushButtonExit->setText("Exit");
    ui->menuFile->setTitle("File");
    ui->actionAdd->setText("Add");
    ui->actionDelete->setText("delete");

    ui->actionNew->setText("New");
    ui->actionSave->setText("Save");
    ui->actionExit->setText("Exit");
    ui->actionAbout->setText("About");

    ui->menuChange->setTitle("Change");
    ui->menuLanguage->setTitle("Language");
    ui->menuAbout->setTitle("About programm");
}
