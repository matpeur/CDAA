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
    /*
    Interface Inter;
    Contact c;
    Interaction I(&Inter, &c, "Test");
    std::string s = "@todo quelquechose@date 17/02/2022";
    toDo td1(&I,s);
     //std::cout<<td1.toString();
    Date d;
        td1.setDate(d.getDateToString());
    //std::cout<<td1.toString();
    I.addToDo(td1);
    Contact C(&Inter,"dfg","dfgh","dfgh","dfgh","df","sdfg","sdf");
    C.createInteraction("fghjk");
   //qDebug()<<(I.getGestionToDo().getSize());
    Basededonnee b;
    C.addInteraction(I);

  // qDebug()<<QString::fromStdString(td.getContenu());
   //C.getGestionInteraction().get(0).addToDo(td);
    qDebug()<<QString::fromStdString(C.getGestionInteraction().get(6).getGestionToDo().get(0).toString());
   qDebug()<<C.getGestionInteraction().get(6).getGestionToDo().getSize();
  b.AjoutContact(C);
  */
   return a.exec();
}




