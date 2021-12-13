#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include "gestioncontact.h"
#include "contact.h"
#include "interaction.h"
#include "todo.h"
#include "basededonnee.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   return a.exec();
}




