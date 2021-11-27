#include "basededonnee.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "contact.h"
Basededonnee::Basededonnee()
{
   Connexion();
}


void Basededonnee::Connexion()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/basededonnees1.sqlite");

      if(!db.open())
      {
          qDebug() << "Pas de connexion BDD !";
      }
      else
      {
          qDebug() << "Connexion BDD ok";


       }
}

void Basededonnee::AjoutContact(Contact P)
{


   if(db.open())
   {
    QSqlQuery query;
    query.prepare("INSERT IN TO Conatct(nom,prenom,entreprise,mail,telephone,photo,date)" "VALUES(:A,:B,:C,:D:,:E,:F,:G)");
    query.bindValue(":A",QString::fromStdString(P.getNom()));
    query.bindValue(":B",QString::fromStdString(P.getPrenom()));
    query.bindValue(":C",QString::fromStdString(P.getEntreprise()));
    query.bindValue(":D",QString::fromStdString(P.getPhoto()));
    query.bindValue(":E",QString::fromStdString(P.getTelephone()));
    query.bindValue(":F",QString::fromStdString(P.getPhoto()));
    query.bindValue(":G",QString::fromStdString(P.getDate()));

    if(!query.exec())
    {
        qDebug()<<"erreur lors de la  requete";



    }


  }




}

void Basededonnee::SupprimeContact(Contact P)
{
   if(db.open())
   {
    QSqlQuery query;
    query.prepare("DELETE FROM personne WHERE nom=:A and prenom=:B and entreprise=:C and mail=:D and telephone=:E and photo=:F and date=:G");
    query.bindValue(":A",QString::fromStdString(P.getNom()));
    query.bindValue(":B",QString::fromStdString(P.getPrenom()));
    query.bindValue(":C",QString::fromStdString(P.getEntreprise()));
    query.bindValue(":D",QString::fromStdString(P.getPhoto()));
    query.bindValue(":E",QString::fromStdString(P.getTelephone()));
    query.bindValue(":F",QString::fromStdString(P.getPhoto()));
    query.bindValue(":G",QString::fromStdString(P.getDate()));

    if(!query.exec())
    {
        qDebug()<<"erreur lors de la requete";



    }
  }


}


void Basededonnee::ModifiContact(Contact C, Contact old)
{
    QSqlQuery query ;

    query.prepare( "UPDATE Contact  SET nom=:a , prenom=:b , entreprise=:c,mail=:d,telephone=:e,photo:f,date=:g WHERE nom=:A and prenom=:B and entreprise=:C and mail=:D and telephone=:E and photo=:F and date=:G" ) ;
    query.bindValue(":A",QString::fromStdString(C.getNom()));
    query.bindValue(":B",QString::fromStdString(C.getPrenom()));
    query.bindValue(":C",QString::fromStdString(C.getEntreprise()));
    query.bindValue(":D",QString::fromStdString(C.getPhoto()));
    query.bindValue(":E",QString::fromStdString(C.getTelephone()));
    query.bindValue(":F",QString::fromStdString(C.getPhoto()));
    query.bindValue(":G",QString::fromStdString(C.getDate()));

    query.bindValue(":a",QString::fromStdString(old.getNom()));
    query.bindValue(":b",QString::fromStdString(old.getPrenom()));
    query.bindValue(":c",QString::fromStdString(old.getEntreprise()));
    query.bindValue(":d",QString::fromStdString(old.getPhoto()));
    query.bindValue(":e",QString::fromStdString(old.getTelephone()));
    query.bindValue(":f",QString::fromStdString(old.getPhoto()));
    query.bindValue(":g",QString::fromStdString(old.getDate()));

    if(!query.exec())
    {
        qDebug()<<"erreur lors de la requete";



    }
}
