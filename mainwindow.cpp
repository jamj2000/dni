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

char MainWindow::calcularLetra(QString d){
   //val_dni->validate(ui->dni, d.toInt());
   //qDebug () << d.toInt();
   ui->letra->setText(QString("TRWAGMYFPDXBNJZSQVHLCKE"[d.toInt()%23]));
}

char MainWindow::calcularDC (QString d) {}
