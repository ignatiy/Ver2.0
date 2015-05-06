#include "mainwindow.h"
#include <QToolBar>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent){
setMinimumSize(640,480);

tbar = new QToolBar;
tbar->addAction(tr("Открыть"),this,SLOT(open()));
tbar->addSeparator();
tbar->addAction(tr("Сохранить"),this,SLOT(save()));
tbar->addSeparator();
tbar->addAction(tr("Редактировать"),this,SLOT(edit()));
tbar->addSeparator();
tbar->addAction(tr("Удалить"),this,SLOT(erase()));
tbar->addSeparator();
tbar->addAction(tr("О программе"),this,SLOT(help()));

this->addToolBar(tbar);

text1 = new QTextEdit;
text1= new QTextEdit(this);
text1->setGeometry(110,30,200,420);

text2 = new QTextEdit;
text2= new QTextEdit(this);
text2->setGeometry(330,30,200,420);

lay = new QVBoxLayout(this);
lay->addWidget(text2);

lay1 = new QVBoxLayout(this);
lay1->addWidget(text1);


setWindowTitle(tr("STM32_DumpEDIT"));

}

void MainWindow::open(){
    qDebug()<<"open";



    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt)"));

   if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
     text2->setText(in.readAll());
         }


 }
void MainWindow::save(){
    qDebug()<<"save";


    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
    tr("Text Files (*.txt)"));

    if (fileName != "") {
       QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {

       } else {
            QTextStream stream(&file);
           stream << text2->toPlainText();
           stream.flush();
           file.close();
       }
    }


}



void MainWindow::edit(){
    qDebug()<<"edit";


}


void MainWindow::erase(){
    qDebug()<<"delete";


//QFile("").remove();


}


void MainWindow::help(){
    qDebug()<<"help";


}
