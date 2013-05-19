#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    char calcularLetra (QString d);
    char calcularDC (QString d);

private:
    Ui::MainWindow *ui;
    QValidator *val_dni;

};

#endif // MAINWINDOW_H
