#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QIntValidator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // val_dni = new QIntValidator(0, 99999999, ui->dni);
    connect (ui->dni, SIGNAL(textChanged(QString)), this, SLOT(calcularLetra(QString)) );
    ui->dni->setCursorPosition(0);

    connect (ui->entidad, SIGNAL(textChanged(QString)), this, SLOT(calcularDC(QString)) );
    connect (ui->oficina, SIGNAL(textChanged(QString)), this, SLOT(calcularDC(QString)) );
    connect (ui->cuenta, SIGNAL(textChanged(QString)), this, SLOT(calcularDC(QString)) );
    ui->entidad->setCursorPosition(0);
    ui->oficina->setCursorPosition(0);
    ui->cuenta->setCursorPosition(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcularLetra(QString d){
   ui->letra->setText(QString("TRWAGMYFPDXBNJZSQVHLCKE"[d.toInt()%23]));
}

void MainWindow::calcularDC (QString d) {
    int valores[10] = {1, 2, 4, 8, 5, 10, 9, 7, 3, 6};
    int control1 = 0, control2 = 0;

    QString s = ui->entidad->text() + ui->oficina->text();

    for (int i=0; i<=7; i++)
        control1 +=  s[i].digitValue() * valores[i+2];

    control1 = 11 - (control1 % 11);
    if (control1 == 11) control1 = 0;
    else if (control1 == 10) control1 = 1;

    for (int i=0; i<=9; i++)
        control2 +=  ui->cuenta->text()[i].digitValue() * valores [i];

    control2 = 11 - (control2 % 11);
    if (control2 == 11) control2 = 0;
    else if (control2 == 10) control2 = 1;

    ui->dc->setNum(control1*10+control2);
}
