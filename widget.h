//Ingresar la carpeta POO en el Disco C: para que funcione gracias :)
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTranslator>
#include <QComboBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void cambiarIdioma(int index);
    void mostrarMensaje();

private:
    Ui::Widget *ui;
    QTranslator traductor;
};

#endif // WIDGET_H
