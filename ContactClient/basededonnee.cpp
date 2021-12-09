#include "basededonnee.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "contact.h"
#include "interaction.h"
#include "todo.h"
#include "gestioncontact.h"
Basededonnee::Basededonnee()
{  idContact=0;
   idInteraction=0;
   idTodo=0;
   Connexion();


}
void setIDInteraction(int i);
int getIDInteractiont();
void setIDTodo(int i);
int getIDTodo();
void Basededonnee:: setIDContact(int i){idContact=i;}
int  Basededonnee::getIDContact(){return this->idContact;}

void Basededonnee:: setIDInteraction(int k){idInteraction=k;}
int  Basededonnee:: getIDInteraction(){return this->idInteraction;}

void Basededonnee:: setIDTodo(int i){idTodo=i;}
int  Basededonnee:: getIDTodo(){return this->idTodo;}
void Basededonnee::Connexion()
{

    b = QSqlDatabase::addDatabase("QSQLITE");
    setIDContact(0);
    b.setDatabaseName("/tmp/basee1");

      if(!b.open())
      {
          qDebug() << "Pas de connexion BDD !";
      }
      else
      {
          qDebug() << "Connexion BDD";

       }
}


void Basededonnee::AjoutContact(Contact C)
{


   if(b.open())
   {
   //on ajoute en un premier tant les données du contact
     QSqlQuery query;
     query.prepare("INSERT INTO contact (nom,prenom,entreprise,mail,telephone,photo,dates,idd)" "VALUES (:A,:B,:C,:D,:E,:F,:G,:H)");
     query.bindValue(":A",QString::fromStdString(C.getNom()));
     query.bindValue(":B",QString::fromStdString(C.getPrenom()));
     query.bindValue(":C",QString::fromStdString(C.getEntreprise()));
     query.bindValue(":D",QString::fromStdString(C.getMail()));
     query.bindValue(":E",QString::fromStdString(C.getTelephone()));
     query.bindValue(":F",QString::fromStdString(C.getPhoto()));
     query.bindValue(":G",QString::fromStdString(C.getDate()));
     query.bindValue(":H",getIDContact());
     if(!query.exec())
     {
         qDebug()<<"erreur lors de la  requete1";

     }
     else
     {//ensuite on test si il à des interractions si oui on les ajoute dans  la table interraction
       if(!C.getGestionInteraction().getInteractionList().empty())
       {
           for(int i=0;i<C.getGestionInteraction().getSize();i++)
            {  QSqlQuery query1;
               query1.prepare("INSERT INTO interraction(id,contenu,dates)" "VALUES(:A,:B,:C)");
               query1.bindValue(":A",getIDContact());
               query1.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i)->getContenu()));
               query1.bindValue(":C",QString::fromStdString(C.getDate()));
               if(query1.exec()){/*++idInteraction*/;}else{qDebug()<<"error";}
          //ensuite pour chaque interraction on test si elle a une liste de todos si oui on les ajoute dans la table todo
              if(!C.getGestionInteraction().get(i)->getGestionToDo().getToDoList().empty())
              {
                if(query1.exec())
                 {
                  for (int j=0;j<C.getGestionInteraction().get(i)->getGestionToDo().getSize();j++)
                   {
                      QSqlQuery query2;
                      query2.prepare("INSERT INTO todo(id,contenu)" "VALUES(:A,:B)");
                      query2.bindValue(":A",getIDContact());
                      query2.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i)->getGestionToDo().get(j)->getContenu()));
                       if(query1.exec()){  /*++idTodo*/;}else{qDebug()<<"error";}
                   }
                }else {qDebug()<<"error";}
              }
            }
      }else {qDebug()<<"requete reuissie";}

    }

      // setIDContact(getIDContact()+1);
}

}



void Basededonnee::SupprimeContact(Contact C)
{
    if(b.open())
    {
     QSqlQuery query;
     query.prepare("DELETE FROM contact WHERE nom=:A and prenom=:B and entreprise=:C and mail=:D and telephone=:E and photo=:F and dates=:G");
     query.bindValue(":A",QString::fromStdString(C.getNom()));
     query.bindValue(":B",QString::fromStdString(C.getPrenom()));
     query.bindValue(":C",QString::fromStdString(C.getEntreprise()));
     query.bindValue(":D",QString::fromStdString(C.getMail()));
     query.bindValue(":E",QString::fromStdString(C.getTelephone()));
     query.bindValue(":F",QString::fromStdString(C.getPhoto()));
     query.bindValue(":G",QString::fromStdString(C.getDate()));

     if(query.exec())
     {
         if(!C.getGestionInteraction().getInteractionList().empty())
         {
             for(int i=0;i<C.getGestionInteraction().getSize();i++)
              {
                                QSqlQuery query1;
                                query1.prepare("DELETE FROM interraction WHERE id=:A and contenu=:B and dates=:C");
                                query1.bindValue(":A",C.getId());
                                query1.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i)->getContenu()));
                                query1.bindValue(":C",QString::fromStdString(C.getDate()));
                                if(query1.exec())
                                 {
                                   if(!C.getGestionInteraction().get(i)->getGestionToDo().getToDoList().empty())
                                   {
                                      for (int j=0;j<C.getGestionInteraction().get(i)->getGestionToDo().getSize();j++)
                                      {
                                       QSqlQuery query2;
                                       query2.prepare("DELETE FROM todo WHERE id=:A and contenu=:B");
                                       query2.bindValue(":A",C.getId());
                                       query2.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i)->getGestionToDo().get(j)->getContenu()));
                                       if(!query2.exec()){qDebug()<<"erreur";}else {C.setId(C.getId()+1);}//on incremente l'id
                                      }
                                   }
                                  }
             }
         }

     }
   }





 }



void Basededonnee::ModifiContact(Contact old, Contact C)
{


    QSqlQuery query ;

    query.prepare( "UPDATE contact  SET nom=:a , prenom=:b , entreprise=:c,mail=:d,telephone=:e,photo=:f,dates=:g WHERE nom=:A and prenom=:B and entreprise=:C and mail=:D and telephone=:E and photo=:F and date=:G" ) ;
    query.bindValue(":A",QString::fromStdString(C.getNom()));
    query.bindValue(":B",QString::fromStdString(C.getPrenom()));
    query.bindValue(":C",QString::fromStdString(C.getEntreprise()));
    query.bindValue(":D",QString::fromStdString(C.getMail()));
    query.bindValue(":E",QString::fromStdString(C.getTelephone()));
    query.bindValue(":F",QString::fromStdString(C.getPhoto()));
    query.bindValue(":G",QString::fromStdString(C.getDate()));

    query.bindValue(":a",QString::fromStdString(old.getNom()));
    query.bindValue(":b",QString::fromStdString(old.getPrenom()));
    query.bindValue(":c",QString::fromStdString(old.getEntreprise()));
    query.bindValue(":d",QString::fromStdString(old.getMail()));
    query.bindValue(":e",QString::fromStdString(old.getTelephone()));
    query.bindValue(":f",QString::fromStdString(old.getPhoto()));
    query.bindValue(":g",QString::fromStdString(old.getDate()));

    if(!query.exec())
    {
        qDebug()<<"erreur";



    }
}

Contact Basededonnee::cherchercontactparNom(std::string nom)
{


    Contact C;
    std::list<Contact> lc;
    if(b.open() )
    {

         QSqlQuery query;
         query.prepare("SELECT * FROM contact WHERE nom=:a");
         query.bindValue(":a",QString::fromStdString(nom));

         if(!query.exec())
         {
             qDebug()<<"erreur1";
         }
         else
         {
          while(query.next())
          {
             QString r=query.value(0).toString();
             C.setNom(r.toStdString());
             r=query.value(1).toString();
             C.setPrenom(r.toStdString());
             r=query.value(2).toString();
             C.setEntrprise(r.toStdString());
             r=query.value(3).toString();
             C.setMail(r.toStdString());
             r=query.value(4).toString();
             C.setTelephone(r.toStdString());
             r=query.value(5).toString();
             C.setPhoto(r.toStdString());
             r=query.value(6).toString();
             C.setDate(r.toStdString());
             C.setId(query.value(7).toInt());

      }

   }

  }
    return  C;
}


GestionContact  Basededonnee::getAllContact()
{
    Contact C;
    GestionContact LC;
    if(b.open())
     {
         QSqlQuery query("SELECT * FROM contact  ");

       if(!query.exec())
         {
         qDebug()<<"erreur lors de la selection";
        }
       else {
         while(query.next())
         {
             QString r=query.value(0).toString();
             C.setNom(r.toStdString());
             r=query.value(1).toString();
             C.setPrenom(r.toStdString());
             r=query.value(2).toString();
             C.setEntrprise(r.toStdString());
             r=query.value(3).toString();
             C.setMail(r.toStdString());
             r=query.value(4).toString();
             C.setTelephone(r.toStdString());
             r=query.value(5).toString();
             C.setPhoto(r.toStdString());
             r=query.value(6).toString();
             C.setDate(r.toStdString());
             C.setId(query.value(7).toInt());
             LC.addContact(C);
         }
          for(auto &it:LC.getContactList())
          {


              QSqlQuery query1;
              query1.prepare("SELECT * FROM interraction where id=:a");
              query1.bindValue(":a",it.getId());
              if(!query1.exec())
              {  qDebug()<<"erreur lors de la requete1 ";}
              else{
                          while(query1.next())
                          {

                              QString r=query1.value(1).toString();
                              it.createInteraction(r.toStdString());

                          }



                        for(auto &itt:it.getGestionInteraction().getInteractionList())
                          {
                            //ici on recupere le nombre de todo ayant le meme id que l'interaction it
                            QSqlQuery query11;
                            query11.prepare("SELECT COUNT(*)FROM todo where id=:a");
                            query11.bindValue(":a",itt.getID());
                            int row=0;
                            query11.exec();
                            if(query11.next())
                            {
                              row+=query11.value(0).toInt();
                             }

                           if(row!=0)
                             { QSqlQuery query2;
                              query2.prepare("SELECT * FROM todo where id=1");
                              query2.bindValue(":a",itt.getID());
                               if(query2.exec())
                                 {
                                   while(query2.next())
                                   {   qDebug()<<itt.getID();
                                       std::string s=query2.value(1).toString().toStdString();
                                       toDo t ;
                                       t.setContenu(s);
                                       t.setOwner(&itt);
                                       Date d;
                                       t.setDate(d.getDateToString());
                                       itt.addToDo(t);

                                   }
                                 }else { qDebug()<<"erreur lors de la requete de todo ";}

              }         }
            }

         }

       }
  }
    return LC;
}

GestionContact Basededonnee::cherchercontactparDates(std::string date, std::string date2)
{
    Contact C;
    GestionContact  lc;
    if(b.open() )
    {

         QSqlQuery query;
         query.prepare("SELECT * FROM contact WHERE   dates>=:a and dates<=:b");
         query.bindValue(":a",QString::fromStdString(date));
         query.bindValue(":b",QString::fromStdString(date2));
         if(!query.exec())
         {
             qDebug()<<"erreur1";
         }
         else
         {
          while(query.next())
          {
             QString r=query.value(0).toString();
             C.setNom(r.toStdString());
             r=query.value(1).toString();
             C.setPrenom(r.toStdString());
             r=query.value(2).toString();
             C.setEntrprise(r.toStdString());
             r=query.value(3).toString();
             C.setMail(r.toStdString());
             r=query.value(4).toString();
             C.setTelephone(r.toStdString());
             r=query.value(5).toString();
             C.setPhoto(r.toStdString());
             r=query.value(6).toString();
             C.setDate(r.toStdString());
             C.setId(query.value(7).toInt());
             lc.addContact(C);
      }

   }

  }
    return lc;

}
std::list<Interaction> Basededonnee::chercheinterraction(string date ,string date2)
{
   std::list<Interaction> LI;

   for(auto &it:cherchercontactparDates(date,date2).getContactList())
  {

  if(b.open() )
  {
       QSqlQuery query;
       query.prepare("SELECT * FROM interraction WHERE   dates>=:a and dates<=:b");
       query.bindValue(":a",QString::fromStdString(date));
       query.bindValue(":b",QString::fromStdString(date2));
       if(!query.exec())
       {
           qDebug()<<"erreur1";
       }
       else
       {
        while(query.next())
        {
           QString r=query.value(1).toString();
           it.createInteraction(r.toStdString());


        }
        for(auto &itt:it.getGestionInteraction().getInteractionList())
        {
                LI.push_back(itt);


        }

   }
    }

  }
    return LI;
}




std::list<toDo> Basededonnee::cherchelistetodo(string date ,string date2)
{
   std::list<toDo> LI;
   Interface I;
 qDebug()<<this->chercheinterraction(date,date2).size();
 for(auto &it:chercheinterraction(date,date2))
  {
  if(b.open() )
  {
       QSqlQuery query;
       query.prepare("SELECT * FROM todo WHERE id=:a");
       query.bindValue(":a",it.getID());
       if(!query.exec())
       {
           qDebug()<<"erreur1";
       }
       else
       {

        while(query.next())
        {
           QString r=query.value(1).toString();
           toDo t;
           t.setContenu(r.toStdString());
           it.getGestionToDo().addToDo(t);

        }
        qDebug()<<"le mali";
        for(auto &itt:it.getGestionToDo().getToDoList())
        {
                LI.push_back(itt);

        }


       }

    }

  }
    return LI;
}


int Basededonnee::Nombredecontact()
{

    QSqlQuery query11;
    query11.prepare("SELECT COUNT(*) FROM contact");
    int row=0;
    query11.exec();
    if(query11.next())
    {
      row+=query11.value(0).toInt();
     }




  return row ;
}
