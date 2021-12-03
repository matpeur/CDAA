#include "basededonnee.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "contact.h"
#include "interaction.h"
Basededonnee::Basededonnee()
{
   Connexion();
}


void Basededonnee::Connexion()
{

    b = QSqlDatabase::addDatabase("QSQLITE");
    b.setDatabaseName("/tmp/basee.sqlite");

      if(!b.open())
      {
          qDebug() << "Pas de connexion BDD !";
      }
      else
      {
          qDebug() << "Connexion BDD ok";

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
     query.bindValue(":H",C.getId());
     if(!query.exec())
     {
         qDebug()<<"erreur lors de la  requete1";

     }
     else
     {//ensuite on test si il à des interractions si oui on les ajoute dans  la table interraction
       if(!C.getGestionInteraction().getInteractionList().empty())
       {
           for(int i=0;i<C.getGestionInteraction().getInteractionList().size();i++)
            {  QSqlQuery query1;
               query1.prepare("INSERT INTO interraction(id,contenu,dates)" "VALUES(:A,:B,:C)");
               query1.bindValue(":A",C.getId());
               query1.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i).getContenu()));
               query1.bindValue(":C",QString::fromStdString(C.getDate()));
               if(!query1.exec()){qDebug()<<"error";}

          //ensuite pour chaque interraction on test si elle a une liste de todos si oui on les ajoute dans la table todo
              if(!C.getGestionInteraction().get(i).getGestionToDo().getToDoList().empty())
              {
                if(query1.exec())
                 {
                  for (int j=0;j<C.getGestionInteraction().get(i).getGestionToDo().getSize();j++)
                   {  qDebug()<<"j'ai des todos";
                      QSqlQuery query2;
                      query2.prepare("INSERT INTO todo(id,contenu)" "VALUES(:A,:B)");
                      query2.bindValue(":A",C.getId());
                      query2.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i).getGestionToDo().get(j).getContenu()));
                      if(!query2.exec())
                          qDebug()<<"erruer";
                   }
                }else {qDebug()<<"error";}
              }
            }
      }else {qDebug()<<"requete reuissie";}

    }


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
     {   qDebug()<<"bien";
         if(!C.getGestionInteraction().getInteractionList().empty())
         {
             for(int i=0;i<C.getGestionInteraction().getInteractionList().size();i++)
              {
                                QSqlQuery query1;
                                query1.prepare("DELETE FROM interraction WHERE id=:A and contenu=:B and dates=:C");
                                query1.bindValue(":A",C.getId());
                                query1.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i).getContenu()));
                                query1.bindValue(":C",QString::fromStdString(C.getDate()));
                                if(query1.exec())
                                 {
                                   if(!C.getGestionInteraction().get(i).getGestionToDo().getToDoList().empty())
                                   {
                                      for (int j=0;j<C.getGestionInteraction().get(i).getGestionToDo().getSize();j++)
                                      {
                                       QSqlQuery query2;
                                       query2.prepare("DELETE FROM todo WHERE id=:A and contenu=:B");
                                       query2.bindValue(":A",C.getId());
                                       query2.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i).getGestionToDo().get(j).getContenu()));
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

    query.prepare( "UPDATE Conta  SET nom=:a , prenom=:b , entreprise=:c,mail=:d,telephone=:e,photo=:f,date=:g WHERE nom=:A and prenom=:B and entreprise=:C and mail=:D and telephone=:E and photo=:F and date=:G" ) ;
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

