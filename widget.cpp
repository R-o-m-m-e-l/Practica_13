#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QMessageBox>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    ui->cmbIdioma->addItem("Seleccione el idioma");
    ui->cmbIdioma->addItem("Español", "es");
    ui->cmbIdioma->addItem("Inglés", "en");


    ui->cmbNivel->addItem("Básico");
    ui->cmbNivel->addItem("Intermedio");
    ui->cmbNivel->addItem("Avanzado");
    ui->cmbNivel->addItem("Experto");


    connect(ui->cmbIdioma, SIGNAL(currentIndexChanged(int)), this, SLOT(cambiarIdioma(int)));
    connect(ui->btnMensaje, SIGNAL(clicked()), this, SLOT(mostrarMensaje()));


    cambiarIdioma(1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::cambiarIdioma(int index)
{

    QString codigoIdioma = ui->cmbIdioma->itemData(index).toString();


    qApp->removeTranslator(&traductor);


    if (codigoIdioma == "es") {

        if (!traductor.load("C:/POO/Rommel/español.qm")) {
            qWarning() << "No se pudo cargar el archivo de traducción español.";
        }
    } else if (codigoIdioma == "en") {

        if (!traductor.load("C:/POO/Rommel/ingles.qm")) {
            qWarning() << "No se pudo cargar el archivo de traducción inglés.";
        }
    }


    qApp->installTranslator(&traductor);
    ui->retranslateUi(this);
}

void Widget::mostrarMensaje()
{

    QString textoIngresado = ui->lineEdit->text();
    QString nivelSeleccionado = ui->cmbNivel->currentText();


    QString mensaje;
    if (ui->cmbIdioma->currentIndex() == 2) {  // Si está en inglés
        if (nivelSeleccionado == "Básico") {
            mensaje = tr("Basic Level:\nInformation displayed correctly: ") + textoIngresado;
        } else if (nivelSeleccionado == "Intermedio") {
            mensaje = tr("Intermediate Level:\nInformation displayed correctly: ") + textoIngresado;
        } else if (nivelSeleccionado == "Avanzado") {
            mensaje = tr("Advanced Level:\nInformation displayed correctly: ") + textoIngresado;
        } else if (nivelSeleccionado == "Experto") {
            mensaje = tr("Expert Level:\nInformation displayed correctly: ") + textoIngresado;
        }
    } else {
        if (nivelSeleccionado == "Básico") {
            mensaje = tr("Nivel Básico:\nInformación mostrada correctamente: ") + textoIngresado;
        } else if (nivelSeleccionado == "Intermedio") {
            mensaje = tr("Nivel Intermedio:\nInformación mostrada correctamente: ") + textoIngresado;
        } else if (nivelSeleccionado == "Avanzado") {
            mensaje = tr("Nivel Avanzado:\nInformación mostrada correctamente: ") + textoIngresado;
        } else if (nivelSeleccionado == "Experto") {
            mensaje = tr("Nivel Experto:\nInformación mostrada correctamente: ") + textoIngresado;
        }
    }


    QMessageBox::information(this, tr("Mensaje"), mensaje);
}
