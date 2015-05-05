#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTextEdit>
class MainWindow : public QMainWindow
{
Q_OBJECT
public: QTextEdit * text2;
    QTextEdit * text1;
explicit MainWindow(QWidget *parent = 0);
signals:
public slots:
    void open();
    void save();
    void edit();
    void erase();
    void help();
};
#endif // MAINWINDOW_H
