#include "basededonnee.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "contact.h"
#include "interaction.h"
#include "todo.h"
#include "gestioncontact.h"
#include <string.h>
#include <stdio.h>
Basededonnee::Basededonnee()
{
     Connexion();
   QSqlQuery query1;
   query1.prepare("select MAX(id) from contact");
   if(query1.exec())
   {
       if(query1.next())
       {
           idContact=query1.value(0).toInt()+1;
       }
   }
    qDebug()<<idContact;

    QSqlQuery query2;
    query2.prepare("select MAX(id) from interraction");
    if(query2.exec())
    {
        if(query2.next())
        {
            idInteraction=query2.value(0).toInt()+1;
        }
    }

    qDebug()<<idInteraction;

   QSqlQuery query3;
   query3.prepare("select MAX(id) from todo");
   if(query3.exec())
   {
       if(query3.next())
       {
           idTodo=query3.value(0).toInt()+1;
       }
   }
   qDebug()<<idTodo;


getAllContact();
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
GestionContact Basededonnee::getGC(){return this->gc;}
void Basededonnee::Connexion()
{

    b = QSqlDatabase::addDatabase("QSQLITE");
    setIDContact(0);
    b.setDatabaseName("/tmp/base1");

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
     query.prepare("INSERT INTO contact (nom,prenom,entreprise,mail,telephone,photo,dates,id)" "VALUES (:A,:B,:C,:D,:E,:F,:G,:H)");
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
               query1.prepare("INSERT INTO interraction(idCONTACT,contenu,dates,id)" "VALUES(:A,:B,:C,:D)");
               query1.bindValue(":A",getIDContact());
               query1.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i)->getContenu()));
               query1.bindValue(":C",QString::fromStdString(C.getDate()));
               query1.bindValue(":D",getIDInteraction());
               if(!query1.exec()){qDebug()<<"error";}

          //ensuite pour chaque interraction on test si elle a une liste de todos si oui on les ajoute dans la table todo
              if(!C.getGestionInteraction().get(i)->getGestionToDo().getToDoList().empty())
              {
                if(query1.exec())
                 {
                  for (int j=0;j<C.getGestionInteraction().get(i)->getGestionToDo().getSize();j++)
                   {  qDebug()<<"j'ai des todos";
                      QSqlQuery query2;
                      query2.prepare("INSERT INTO todo(idINTERAC,contenu,id,dates)" "VALUES(:A,:B,:C,:D)");
                      query2.bindValue(":A",getIDInteraction());
                      query2.bindValue(":B",QString::fromStdString(C.getGestionInteraction().get(i)->getGestionToDo().get(j)->getContenu()));
                      query2.bindValue(":C",getIDTodo());
                      query2.bindValue(":D",QString::fromStdString(C.getGestionInteraction().get(i)->getGestionToDo().get(j)->datestring));
                      setIDTodo(getIDTodo()+1);//on incremente l'id des todos
                       if(!query2.exec())
                          qDebug()<<"erruer";
                   }
                }else {qDebug()<<"error";}
              }
              setIDInteraction(getIDInteraction()+1);
            }
      }else {qDebug()<<"requete reuissie";}

    }
      setIDContact(getIDContact()+1);
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


void  Basededonnee::getAllContact()
{
    Contact C;

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
             Contact *C = new Contact(query.value(0).toString().toStdString(),
                       query.value(1).toString().toStdString(),
                       query.value(2).toString().toStdString(),
                       query.value(3).toString().toStdString(),
                       query.value(4).toString().toStdString(),
                       query.value(5).toString().toStdString(),
                       query.value(6).toString().toStdString());
              C->setId(query.value(7).toInt());

              QSqlQuery query1;
              query1.prepare("SELECT * FROM interraction where idCONTACT=:a");
              query1.bindValue(":a",C->getId());
              if(!query1.exec())
              {  qDebug()<<"erreur lors de la requete2 ";}
              else{
                          while(query1.next())
                          {

                            QString r=query1.value(1).toString();
                            Interaction *I =new Interaction(C,r.toStdString());
                            I->setID(query1.value(3).toInt());


                            QSqlQuery query2;
                              query2.prepare("SELECT * FROM todo where idINTERAC=:a");
                              query2.bindValue(":a",I->getID());
                               if(query2.exec())
                                 {
                                   while(query2.next())
                                   {
                                       std::string s=query2.value(1).toString().toStdString();
                                       toDo *t = new toDo();
                                       t->setContenu(s);
                                       t->setOwner(I);
                                       t->setID(query2.value(2).toInt());
                                       t->setDate(query2.value(3).toString().toStdString());
                                       I->addToDo(t);

                                   }
                                 }else { qDebug()<<"erreur lors de la requete de todo ";}

                               C->addInteraction(I);
                         }

              }
              getGC().addContact(C);
            }

         }

       }


}

std::list<Contact*> Basededonnee::recherchercontactparNom(std:: string nom)
{


    std::list<Contact*> LC;
    for (auto it:getGC().getContactList())
    {
     if(nom==it->getNom())
        LC.push_back(it);
    }
    return LC;
}


std::list<Contact*> Basededonnee::recherchercontactparDates(std::string date, std::string date2)
{
    std::list<Contact*> LC;
    bool drapeau=true;
    int compteur=0;
    int indiceDate=0;
    int indiceDate2=0;
    for(auto it:getGC().getContactList())
    {
        if(it->getDate()==date&&drapeau)
         {
            indiceDate=compteur;
            drapeau=false;
        }
        else
        {
            if(it->getDate()==date2)
             {
                indiceDate2=compteur;
             }
        }
        compteur++;
    }

     for (int i=indiceDate;i<indiceDate2;i++)
     {
           LC.push_back(getGC().getContactByID(i));
     }

    return LC;

}

std::list<Contact*> Basededonnee::recherchecontact(std::string nom, std::string date, std::string date2,bool parNom,bool parDate )
{

 if(parNom&&parDate)
 {
     list<Contact*> lc;
     for(auto it:recherchercontactparNom(nom))
         lc.push_back(it);
     for(auto &it:recherchercontactparDates(date,date2))
         lc.push_back(it);
     return lc;
 }else {


     if(parNom)
          return recherchercontactparNom(nom);
       else {if(parDate)
              return recherchercontactparDates(date,date2);}
 }
}
std::list<Interaction*> Basededonnee::recherchelisteinterractionpardate(int idCONTACT ,string date ,string date2)
{

    std::list<Interaction*> LI;
    bool drapeau=true;
    int compteur=0;
    int indiceDate=0;
    int indiceDate2=0;
    for(auto it:getGC().getContactByID(idCONTACT)->getGestionInteraction().getInteractionList())
    {
        if(it->getDate()==date&&drapeau)
         {
            indiceDate=compteur;
            drapeau=false;
        }
        else
        {
            if(it->getDate()==date2)
             {
                indiceDate2=compteur;
             }
        }
        compteur++;
    }

     for (int i=indiceDate;i<indiceDate2;i++)
     {
           LI.push_back(getGC().getInterractionByID(i));
     }

    return LI;
}
std::list<Interaction*> Basededonnee::recherchelisteinterractionparContact(int idCONTACT)
{std::list<Interaction*> LI;
    for(auto it:getGC().getContactByID(idCONTACT)->getGestionInteraction().getInteractionList())
    {
          LI.push_back(it);
    }
    return  LI;
}
std::list<Interaction*> Basededonnee::rechercheInterraction(std::string date, std::string date2,int idContact, bool parDate, bool parNom)
{



    if(parNom&&parDate)
    {
        list<Interaction*> lc;
        for(auto it:recherchelisteinterractionparContact(idContact))
            lc.push_back(it);
        for(auto &it:recherchelisteinterractionpardate(idContact,date,date2))
            lc.push_back(it);
        return lc;
    }else {


        if(parNom)
             return recherchelisteinterractionparContact(idContact);
          else {if(parDate)
                 return recherchelisteinterractionpardate(idContact,date,date2);}
    }

}
std::list<toDo*> Basededonnee::recherchelistetodopardate(int idCONTACT,int idINTERAC,string date ,string date2)
{
    std::list<toDo*> LT;

    bool drapeau=true;
    int compteur=0;
    int indiceDate=0;
    int indiceDate2=0;
        for(auto it:getGC().getContactByID( idCONTACT)->getGestionInteraction().get(idINTERAC)->getGestionToDo().getToDoList())
        {
            if(it->datestring==date&&drapeau)
             {
                indiceDate=compteur;
                drapeau=false;
            }
            else
            {
                if(it->datestring==date2)
                 {
                    indiceDate2=compteur;
                 }
            }
            compteur++;
        }



     for(int i=indiceDate;i<indiceDate2;i++)
     {
      LT.push_front(getGC().gettoDoByID(i));
     }


        return  LT;




}

std::list<toDo*> Basededonnee::recherchelistetodoparinterraction(int idCONTACT,int idINTERAC)
{  std::list<toDo*> LT;
    for(auto it:getGC().getContactByID(idCONTACT)->getGestionInteraction().get(idINTERAC)->getGestionToDo().getToDoList())
    {
          LT.push_back(it);
    }
    return  LT;

}

std::list<toDo*> Basededonnee::recherchelistetodo(std::string date, std::string date2,int idCONTACT,int  idINTERAC ,bool parDATE,bool parCONTACT)

  {

        if(parCONTACT&&parDATE)
        {
            list<toDo*> lc1;
            list<toDo*> lc;
            for(auto it:recherchelistetodoparinterraction(idCONTACT,idINTERAC))
                lc1.push_back(it);
            for(auto it:recherchelistetodoparinterraction(idCONTACT,idINTERAC))
                lc1.push_back(it);
            return lc;
        }else {


            if(parDATE)
                 return recherchelistetodoparinterraction(idCONTACT,idINTERAC);
              else {if(parDATE)
                     return recherchelistetodoparinterraction(idCONTACT,idINTERAC);
            }
        }

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






















