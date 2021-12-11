#include "basededonnee.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include "contact.h"
#include "interaction.h"
#include "todo.h"
#include "gestioncontact.h"
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
             Contact C(query.value(0).toString().toStdString(),
                       query.value(1).toString().toStdString(),
                       query.value(2).toString().toStdString(),
                       query.value(3).toString().toStdString(),
                       query.value(4).toString().toStdString(),
                       query.value(5).toString().toStdString(),
                       query.value(6).toString().toStdString());
              C.setId(query.value(7).toInt());

              QSqlQuery query1;
              query1.prepare("SELECT * FROM interraction where idCONTACT=:a");
              query1.bindValue(":a",C.getId());
              if(!query1.exec())
              {  qDebug()<<"erreur lors de la requete2 ";}
              else{
                          while(query1.next())
                          {

                            QString r=query1.value(1).toString();
                            Interaction I(&C,r.toStdString());
                            I.setID(query1.value(3).toInt());


                            QSqlQuery query2;
                              query2.prepare("SELECT * FROM todo where idINTERAC=:a");
                              query2.bindValue(":a",I.getID());
                               if(query2.exec())
                                 {
                                   while(query2.next())
                                   {
                                       std::string s=query2.value(1).toString().toStdString();
                                       toDo t ;
                                       t.setContenu(s);
                                       t.setOwner(&I);
                                       t.setID(query2.value(2).toInt());
                                       t.setDate(query2.value(3).toString().toStdString());
                                       I.addToDo(t);

                                   }
                                 }else { qDebug()<<"erreur lors de la requete de todo ";}

                               C.addInteraction(I);
                         }

              }
              LC.addContact(C);
            }

         }

       }

    return LC;
}

std::list<Contact> Basededonnee::recherchercontactparNom(std::string nom)
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
             lc.push_back(C);
      }

   }

  }
    return  lc;
}

std::list<Contact> Basededonnee::recherchercontactparDates(std::string date, std::string date2)
{
    Contact C;
    std::list<Contact>  lc;
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
             lc.push_back(C);
      }

   }

  }
    return lc;

}

std::list<Contact> Basededonnee::recherchecontact(std::string nom, std::string date, std::string date2,bool parNom,bool parDate )
{

 if(parNom&&parDate)
 {
     list<Contact> lc;
     for(auto &it:recherchercontactparNom(nom))
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
std::list<Interaction> Basededonnee::recherchelisteinterractionpardate(string date ,string date2)
{
   std::list<Interaction> LI;

   for(auto &it:recherchercontactparDates(date,date2))
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
std::list<Interaction> Basededonnee::recherchelisteinterractionparContact(Contact C)
{
    std::list<Interaction> LC;
    QSqlQuery query ;
    query.prepare("select * from interraction where idCONTACT=:a");
    query.bindValue(":a",C.getId());
    if(query.exec())
    {
        while(query.next())
        {
           Interaction I(&C,query.value(1).toString().toStdString());
           I.setID(query.value(3).toInt());
           LC.push_back(I);
        }

    }
    return  LC;
}
std::list<Interaction> Basededonnee::rechercheInterraction(std::string date, std::string date2,Contact C, bool pardate, bool parcontact)
{


    if(pardate&&parcontact)
    {
        list<Interaction> lc;
        for(auto &it:recherchelisteinterractionpardate(date,date2))
            lc.push_back(it);
        for(auto &it:recherchelisteinterractionparContact(C))
            lc.push_back(it);
        return lc;
    }else {

        if(pardate)
            return  recherchelisteinterractionpardate(date,date2);
        else {
            if(parcontact)
                       return recherchelisteinterractionparContact(C);
            }

 }

}
std::list<toDo> Basededonnee::recherchelistetodopardate(string date ,string date2)
{
   std::list<toDo> LI;
   if(b.open() )
   {
        QSqlQuery query;
        query.prepare("SELECT * FROM todo WHERE   dates>=:a and dates<=:b");
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
              toDo t;
              t.setID(query.value(2).toInt());
              t.setContenu(query.value(1).toString().toStdString());
              t.setDate(query.value(3).toString().toStdString());
              LI.push_back(t);
         }

         }
     }


     return LI;
}
std::list<toDo> Basededonnee::recherchelistetodoparinterraction( Interaction I)
{
    std::list<toDo> LC;
    QSqlQuery query ;
    query.prepare("select * from todo where idINTERAC=:a");
    query.bindValue(":a",I.getID());
    if(query.exec())
    {
        while(query.next())
        {
           toDo t;
           t.setID(query.value(2).toInt());
           t.setOwner(&I);
           t.setContenu(query.value(1).toString().toStdString());
           t.setDate(query.value(3).toString().toStdString());
           LC.push_back(t);
        }

    }
    return  LC;


}

std::list<toDo> Basededonnee::recherchelistetodoparContact(Contact C)
{

    std::list<toDo> LC;
    QSqlQuery query ;
    query.prepare("select * from interraction where idCONTACT=:a");
    query.bindValue(":a",C.getId());
    if(query.exec())
    {
        while(query.next())
        {
           Interaction I(&C,query.value(1).toString().toStdString());
           I.setID(query.value(3).toInt());
          for(auto &it:recherchelistetodoparinterraction(I))
               LC.push_back(it);
        }

    }


    return LC;

}

std::list<toDo> Basededonnee::recherchelistetodo(std::string date, std::string date2,Contact C, bool parDATE,bool parCONTACT)
{
      std::list<toDo> lc;
    if(parDATE&&parCONTACT)
    {

        for(auto &it:recherchelistetodopardate(date,date2))
         {   lc.push_back(it);}
        for(auto &itt: recherchelistetodoparContact(C))
           { lc.push_back(itt);}
        return lc;

    }
    else {

            if(parDATE)
                 return  recherchelistetodopardate(date,date2);
             else {
                 if(parCONTACT)
                            return recherchelistetodoparContact(C);
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






















