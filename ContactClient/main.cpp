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
//    w.show();
    Interface Inter;
    Contact c;
    Interaction I(&Inter, &c, "Test");
    std::string s = "@todo quelquechose@date 17/02/2022";
    toDo td1(&I,s);
     //std::cout<<td1.toString();
    Date d;
        td1.setDate(d.getDateToString());
    std::cout<<td1.toString();
    I.addToDo(td1);
  //  I.getGestionToDo().createtodO(&I,"kkkkkkkk");
    Contact C(&Inter,"MAMADOU","TRAORE","MYWO","dfgh","df","6-12-2021","sdf");
    Contact K(&Inter,"MAMADU","DIARR","MYW","dfgh","7-12-2021","sdfg","sdf");
    Contact L(&Inter,"MAdu","TRAORE","BNDA","dfgh","df","7-12-2021","sdf");
    Contact H(&Inter,"Mouss","DIARR","BCEAO","dfgh","8-12-2021","sdfg","sdf");
    C.createInteraction("fghjk");
   //qDebug()<<(I.getGestionToDo().getSize());
    Basededonnee b;
    C.addInteraction(I);
    L.addInteraction(I);
    K.addInteraction(I);
    H.addInteraction(I);
    b.AjoutContact(C);
    b.AjoutContact(L);
    b.AjoutContact(K);
    b.AjoutContact(H);


    std::list<Contact> lC;
   // GestionContact k=*b.getAllContact();

  /* for(auto &it:b.getAllContact().getContactList())
    {   for(auto &itt:it.getGestionInteraction().getInteractionList())
        {
           for(auto &ittt:itt.getGestionToDo().getToDoList())
           {
             // qDebug()<<QString::fromStdString(ittt.toString());
           }
     //  qDebug()<<QString::fromStdString(itt.getContenu());
       }
     }
*/
 /*  qDebug()<<"le nombre de contact est :";
   qDebug()<<b.Nombredecontact();*/

   /*for(auto &it:b.cherchercontactparDates("6-12-2021","8-12-2021"))
     {
          qDebug()<<QString::fromStdString(it.getNom());

    }
    for(auto &it:b.chercheinterraction("6-12-2021","8-12-2021"))
    {

        qDebug()<<QString::fromStdString(it.getContenu());



}

   for(auto &it:b.cherchelistetodo("6-12-2021","8-12-2021"))
   {
       qDebug()<<QString::fromStdString(it.toString());

   }*/


   return a.exec();
}




