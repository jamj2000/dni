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

char MainWindow::calcularDC (QString d) {
    /*
     // Todo correcto, calculamos el dígito de control
    var numeroCuenta = f.entidad.value + "" + f.oficina.value + "--" + f.cuenta.value;

    valores = new Array(1, 2, 4, 8, 5, 10, 9, 7, 3, 6);
    var controlCS = 0;
    var controlCC = 0;
    for (i=0; i<=7; i++)
    {controlCS += parseInt(numeroCuenta.charAt(i)) * valores[i+2];
    }
    controlCS = 11 - (controlCS % 11);
    if (controlCS == 11) controlCS = 0;
    else if (controlCS == 10) controlCS = 1;

    for (i=10; i<=19; i++)
    controlCC += parseInt(numeroCuenta.charAt(i)) * valores[i-10];
    controlCC = 11 - (controlCC % 11);
    if (controlCC == 11) controlCC = 0;
    else if (controlCC == 10) controlCC = 1;

    f.dc.value = controlCS + "" + controlCC;
    */

}
