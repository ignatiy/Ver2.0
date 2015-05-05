#include "mainwindow.h"
#include <QToolBar>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent){
setMinimumSize(640,480);

QToolBar * tbar = new QToolBar;
tbar = new QToolBar(this);
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


//QTextEdit *text = new QTextEdit;
text1= new QTextEdit(this);
text1->setGeometry(110,30,200,420);

text2 = new QTextEdit;
//QTextEdit *text1 = new QTextEdit;
text2= new QTextEdit(this);
text2->setGeometry(330,30,200,420);

//QVBoxLayout *Layout = new QVBoxLayout;  //здесь я хотел добавить на форму Layout и на нем попытаться распложить текстовые поля
 // Layout->addWidget(textedit);


QVBoxLayout *lay = new QVBoxLayout(this);
lay->addWidget(text2);

//QVBoxLayout *lay1 = new QVBoxLayout(this);
//lay1->addWidget(text1);



QVBoxLayout *layout = new QVBoxLayout;
   layout->addWidget(text2);
  // layout->addWidget(text1);
  this->setLayout(layout);


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


}


void MainWindow::help(){
    qDebug()<<"help";


}
