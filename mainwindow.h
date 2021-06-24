#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QSettings>
#include <QDebug>

#include<QSettings>
#include<QTranslator>
#include <QApplication>
#include <QContextMenuEvent>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QActionGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAdd_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionDelete_triggered();

    void TableUpdate();

     void writePosition();

     void readPosition();

     void on_pushButtonDiagram_clicked();

     void contextMenuEvent( QContextMenuEvent* e );


     void on_actionRUS_triggered();

     void on_actionENG_triggered();

protected:

//dragEnterEvent - реализация Drag and drop вход в окно
    virtual void dragEnterEvent(QDragEnterEvent *event);

//dragLeaveEvent - реализация Drag and drop выход их окна
    virtual void dragLeaveEvent(QDragLeaveEvent *e);

//dropEvent - Метод, отвечающий за "сбрасывание " данных в сторонние программы
    virtual void dropEvent(QDropEvent *e);

private:
    Ui::MainWindow *ui;

    QMenu* m_menu;
};
#endif // MAINWINDOW_H
