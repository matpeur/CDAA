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
/**
 * @brief constructeur  dans lequel on fait appel à la methode connexion() permettant d'activer la connexion de la base de données
 * ,elle permet aussi d'initialiser les variables idContact ,idInter,idtodo avec les indices courant de chaques tables .
 * @author TRAORE MOUSSA
 * @date decembre 2021 constructeur
 *
 */
Basededonnee::Basededonnee()
{
     Connexion();
   QSqlQuery query1;
 if(Nombredecontact()!=0)
 {  query1.prepare("select MAX(id) from contact");
   if(query1.exec())
   {
       if(query1.next())
       {
           idContact=query1.value(0).toInt()+1;
       }
   }

    QSqlQuery query2;
    query2.prepare("select MAX(id) from interraction");
    if(query2.exec())
    {
        if(query2.next())
        {
            idInteraction=query2.value(0).toInt()+1;
        }
    }


   QSqlQuery query3;
   query3.prepare("select MAX(id) from todo");
   if(query3.exec())
   {
       if(query3.next())
       {
           idTodo=query3.value(0).toInt()+1;
       }
   }


} else {
     idContact=0;
     idInteraction=0;
     idTodo=0;
}
getAllContact();
}
/**
 * @brief  implementation des acceceurs des differents attributs  de la classe
 * @author  TRAORE MOUSSA
 * @date decembre 2021
 */
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

/**
 * @brief implementation de la methode connexion qui permet de connecter l'interface à la base de donnees
 * @author  TRAORE MOUSSA
 * @date decembre 2021
 */
void Basededonnee::Connexion()
{

    b = QSqlDatabase::addDatabase("QSQLITE");
    setIDContact(0);
    b.setDatabaseName("/home1/mb398063/Downloads/CDAA-main/ContactClient/base1");

      if(!b.open())
      {
          qDebug() << "Pas de connexion BDD !";
      }
      else
      {
          qDebug() << "Connexion BDD";

       }
}


/**
 * @brief  implementation de la methode ajoutcontact permettant d'ajouter un contact avec toutes ses interractions ainsi que
 * les todos et cela avec les indices appropriés
 * @author  TRAORE Moussa
 * @date decembre 2021
 */
void Basededonnee::AjoutContact(Contact* C)
{


   if(b.open())
   {
   //on ajoute en un premier tant les données du contact
     QSqlQuery query;
     query.prepare("INSERT INTO contact (nom,prenom,entreprise,mail,telephone,photo,dates,id)" "VALUES (:A,:B,:C,:D,:E,:F,:G,:H)");
     query.bindValue(":A",QString::fromStdString(C->getNom()));
     query.bindValue(":B",QString::fromStdString(C->getPrenom()));
     query.bindValue(":C",QString::fromStdString(C->getEntreprise()));
     query.bindValue(":D",QString::fromStdString(C->getMail()));
     query.bindValue(":E",QString::fromStdString(C->getTelephone()));
     query.bindValue(":F",QString::fromStdString(C->getPhoto()));
     query.bindValue(":G",QString::fromStdString(C->getDate()));
     query.bindValue(":H",getIDContact());
     if(!query.exec())
     {
         qDebug()<<"erreur lors de la  requete1";

     }
     else
     {//ensuite on test si il à des interractions si oui on les ajoute dans  la table interraction
       if(!C->getGestionInteraction().getInteractionList().empty())
       {
           for(int i=0;i<C->getGestionInteraction().getSize();i++)
            {  QSqlQuery query1;
               query1.prepare("INSERT INTO interraction(idCONTACT,contenu,dates,id)" "VALUES(:A,:B,:C,:D)");
               query1.bindValue(":A",getIDContact());
               query1.bindValue(":B",QString::fromStdString(C->getGestionInteraction().get(i)->getContenu()));
               query1.bindValue(":C",QString::fromStdString(C->getGestionInteraction().get(i)->getDate()));
               query1.bindValue(":D",getIDInteraction());
               if(!query1.exec()){qDebug()<<"error";}

          //ensuite pour chaque interraction on test si elle a une liste de todos si oui on les ajoute dans la table todo
              if(!C->getGestionInteraction().get(i)->getGestionToDo().getToDoList().empty())
              {
                if(query1.exec())
                 {
                  for (int j=0;j<C->getGestionInteraction().get(i)->getGestionToDo().getSize();j++)
                   {  qDebug()<<"j'ai des todos";
                      QSqlQuery query2;
                      query2.prepare("INSERT INTO todo(idINTERAC,contenu,id,dates)" "VALUES(:A,:B,:C,:D)");
                      query2.bindValue(":A",getIDInteraction());
                      query2.bindValue(":B",QString::fromStdString(C->getGestionInteraction().get(i)->getGestionToDo().get(j)->getContenu()));
                      query2.bindValue(":C",getIDTodo());
                      query2.bindValue(":D",QString::fromStdString(C->getGestionInteraction().get(i)->getGestionToDo().get(j)->getDate()));
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
/**
 * @brief Ajoute une interaction à la base de donnée
 * @param Inter
 * @author BELLEGUEULLE TRAORE
 */
void Basededonnee::AjoutInter(Interaction * Inter)
{
    if(b.open())
    {
    //on ajoute en un premier toutes les données de l'interaction
      QSqlQuery query;
      query.prepare("INSERT INTO interraction(idCONTACT,contenu,dates,id)" "VALUES(:A,:B,:C,:D)");
      query.bindValue(":A",Inter->getContact()->getId());
      query.bindValue(":B",QString::fromStdString(Inter->getContenu()));
      query.bindValue(":C",QString::fromStdString(Inter->getDate()));
      query.bindValue(":D",getIDInteraction());
      if(!query.exec())
      {
          qDebug()<<"erreur lors de la  requete1";

      }
      else
      {
         // on test si elle a une liste de todos si oui on les ajoute dans la table todo
        if(!Inter->getGestionToDo().getToDoList().empty())
        {
            for(int i=0;i<Inter->getGestionToDo().getSize();i++)
             {
                QSqlQuery query2;
                query2.prepare("INSERT INTO todo(idINTERAC,contenu,id,dates)" "VALUES(:A,:B,:C,:D)");
                query2.bindValue(":A",getIDInteraction());
                query2.bindValue(":B",QString::fromStdString(Inter->getGestionToDo().get(i)->getContenu()));
                query2.bindValue(":C",getIDTodo());
                query2.bindValue(":D",QString::fromStdString(Inter->getGestionToDo().get(i)->getDate()));
                setIDTodo(getIDTodo()+1);//on incremente l'id des todos
                 if(!query2.exec())
                    qDebug()<<"erreur";
             }
         }
       }
    }
    setIDInteraction(getIDInteraction()+1);
}
/**
 * @brief  implementaion de la methode supprimecontact(Contact *c ) permettant de supprimer un contact de la base de donnée
 * @author  TRAORE MOUSSA
 * @date decembre 2021
 */
void Basededonnee::SupprimeContact(Contact *C)
{
    if(b.open())
    {
     QSqlQuery query;
     query.prepare("DELETE FROM contact WHERE id= :A");
     query.bindValue(":A",QString::number(C->getId()));

     if(query.exec())
     {
         if(!C->getGestionInteraction().getInteractionList().empty())
         {
             for(int i=0;i<C->getGestionInteraction().getSize();i++)
              {
                QSqlQuery query1;
                query1.prepare("DELETE FROM interraction WHERE idContact=:A");
                query1.bindValue(":A",C->getId());
                if(query1.exec())
                {
                     if(!C->getGestionInteraction().get(i)->getGestionToDo().getToDoList().empty())
                     {
                        for (int j=0;j<C->getGestionInteraction().get(i)->getGestionToDo().getSize();j++)
                        {
                        QSqlQuery query2;
                        query2.prepare("DELETE FROM todo WHERE idContact=:A");
                        query2.bindValue(":A",C->getId());
                        if(!query2.exec()){qDebug()<<"erreur";}else {C->setId(C->getId()+1);}//on incremente l'id
                        }
                     }
                }
             }
         }

     }
   }





 }

/**
 * @brief implementation de la methode modifiecontact
 * @author  TRAORE MOUSSA
 * @date decembre 2021
 */


void Basededonnee::ModifiContact(Contact *C)
{


    QSqlQuery query ;

    query.prepare( "UPDATE contact  SET nom=:a , prenom=:b , entreprise=:c,mail=:d,telephone=:e,photo=:f,dates=:g WHERE id=:A"  ) ;
    query.bindValue(":A",QString::number(C->getId()));


    query.bindValue(":a",QString::fromStdString(C->getNom()));
    query.bindValue(":b",QString::fromStdString(C->getPrenom()));
    query.bindValue(":c",QString::fromStdString(C->getEntreprise()));
    query.bindValue(":d",QString::fromStdString(C->getMail()));
    query.bindValue(":e",QString::fromStdString(C->getTelephone()));
    query.bindValue(":f",QString::fromStdString(C->getPhoto()));
    query.bindValue(":g",QString::fromStdString(C->getDate()));

    if(!query.exec())
    {
        qDebug()<<"erreur";
    }
}

/**
 * @brief implementation de la methode getAllcontact() qui permet de recurperer et de stocker toutes les données  de la
 * base de données avec des indices precis
 * @author  TRAORE MOUSSA
 * @date decembre 2021
 */
void Basededonnee::getAllContact()
{
    Contact C;
    GestionContact G;
    if(gc.getSize()>0)
        for(auto it : gc.getContactList())
            gc.removeContact(it);
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
                            I->setdatedb(query1.value(2).toString().toStdString());

                            qDebug()<<QString::fromStdString(I->getDate());

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
              this->gc.addContact(C);
            }

         }

       }

}
/**
 * @brief  implementation des methodes de recherches  avancées
 * @author  TRAORE MOUSSA
 * @date decembre 2021
 */
std::list<Contact*> Basededonnee::recherchercontactparNom(std:: string nom)
{


    std::list<Contact*> LC;
   if(!gc.getContactList().empty())
   {
    for (auto it:gc.getContactList())
    {
     if(nom==it->getNom())
        LC.push_back(it);
    }

   }
    return LC;
}


std::list<Contact*> Basededonnee::recherchercontactparDates(std::string date, std::string date2)
{
    QSqlQuery query("SELECT dates, id FROM contact");
    std::list<Contact*> LI;
    Date d1(date);
    QDate datedebut(d1.getDate()->tm_year+1900, d1.getDate()->tm_mon+1, d1.getDate()->tm_mday);
    Date d2(date2);
    QDate datefin(d2.getDate()->tm_year+1900, d2.getDate()->tm_mon+1, d2.getDate()->tm_mday);
    while(query.next())
    {
    Date c(query.value(0).toString().toStdString());
    QDate datetest(c.getDate()->tm_year+1900, c.getDate()->tm_mon+1, c.getDate()->tm_mday);
     if ((datetest>=datedebut)&&(datetest<=datefin))
     {
         if(gc.getContactByID(query.value(1).toInt())!=nullptr)
           LI.push_back(gc.getContactByID(query.value(1).toInt()));
     }
    }
    return LI;

}

std::list<Contact*> Basededonnee::recherchecontact(std::string nom, std::string  date, std::string  date2,bool parNom,bool parDate )
{

  if(parNom&&parDate)
  {
     list<Contact*> lc;

    if(!recherchercontactparNom(nom).empty()&&!recherchercontactparDates(date,date2).empty())
     { for(auto it:recherchercontactparNom(nom))
       {    for(auto itt:recherchercontactparDates(date,date2))
            {
                if(it==itt)
                    lc.push_back(it);
            }
       }
   }else{
               if(recherchercontactparDates(date,date2).empty())
                   return recherchercontactparNom(nom);
               else {
                   if(recherchercontactparNom(nom).empty())
                   {
                       return  recherchercontactparDates(date,date2);
                   }
               }
        }


     return lc;
 }else {


     if(parNom)
          return recherchercontactparNom(nom);
       else {if(parDate)
              return recherchercontactparDates(date,date2);}
      }

}

std::list<Interaction*> Basededonnee::recherchelisteinterractionpardate(string date ,string date2)
{

    QSqlQuery query("SELECT dates, id FROM interraction");
    std::list<Interaction*> LI;
    Date d1(date);
    QDate datedebut(d1.getDate()->tm_year+1900, d1.getDate()->tm_mon+1, d1.getDate()->tm_mday);
    Date d2(date2);
    QDate datefin(d2.getDate()->tm_year+1900, d2.getDate()->tm_mon+1, d2.getDate()->tm_mday);
    while(query.next())
    {
    Date c(query.value(0).toString().toStdString());
    QDate datetest(c.getDate()->tm_year+1900, c.getDate()->tm_mon+1, c.getDate()->tm_mday);
     if ((datetest>=datedebut)&&(datetest<=datefin))
     {
         if(gc.getInterractionByID(query.value(1).toInt())!=nullptr)
           LI.push_back(gc.getInterractionByID(query.value(1).toInt()));
     }
    }
    return LI;
}

std::list<Interaction*> Basededonnee::recherchelisteinterractionparContact(int idCONTACT)
{std::list<Interaction*> LI;
    for(auto it:gc.getContactByID(idCONTACT)->getGestionInteraction().getInteractionList())
    {
          LI.push_back(it);
    }
    return  LI;
}
std::list<Interaction*> Basededonnee::rechercheInterraction(std::string date, std::string date2,int idContact, bool parDate, bool parCONTACT)
{

    if(parCONTACT&&parDate)
    {
        std::list<Interaction*> lc;
        if(!recherchelisteinterractionparContact(idContact).empty()&&!recherchelisteinterractionpardate(date,date2).empty())
         { for(auto it:recherchelisteinterractionparContact(idContact))
           {    for(auto itt:recherchelisteinterractionpardate(date,date2))
                {
                    if(it==itt)
                        lc.push_back(it);
                }
           }
       }else{
                   if(recherchelisteinterractionpardate(date,date2).empty())
                       return recherchelisteinterractionparContact(idContact);
                   else {
                       if(recherchelisteinterractionparContact(idContact).empty())
                       {
                           return  recherchelisteinterractionpardate(date,date2);
                       }
                   }
            }
        return lc;
    }else {


        if(parCONTACT)
             return recherchelisteinterractionparContact(idContact);
          else {if(parDate)
                 return recherchelisteinterractionpardate(date,date2);}

    }

}
std::list<toDo*> Basededonnee::recherchelistetodopardate(string date ,string date2)
{
    std::list<toDo*> LT;

    QSqlQuery query("SELECT dates, id FROM todo");
    Date d1(date);
    QDate datedebut(d1.getDate()->tm_year+1900, d1.getDate()->tm_mon+1, d1.getDate()->tm_mday);
    Date d2(date2);
    QDate datefin(d2.getDate()->tm_year+1900, d2.getDate()->tm_mon+1, d2.getDate()->tm_mday);
    while(query.next())
    {
    Date c(query.value(0).toString().toStdString());
    QDate datetest(c.getDate()->tm_year+1900, c.getDate()->tm_mon+1, c.getDate()->tm_mday);
     if ((datetest>=datedebut)&&(datetest<=datefin))
     {
         if(gc.gettoDoByID(query.value(1).toInt())!=nullptr)
           LT.push_back(gc.gettoDoByID(query.value(1).toInt()));
     }
    }
    return LT;
}

std::list<toDo*> Basededonnee::recherchelistetodopaContact(int idCONTACT)
{  std::list<toDo*> LT;
  for(int i=0;i<gc.getContactByID(idCONTACT)->getGestionInteraction().getSize();i++){

   if(!gc.getContactByID(idCONTACT)->getGestionInteraction().get(i)->getGestionToDo().getToDoList().empty())
   {
     for(auto it:gc.getContactByID(idCONTACT)->getGestionInteraction().get(i)->getGestionToDo().getToDoList())
      {
          LT.push_back(it);
       }
   }
  }
    return  LT;

}

std::list<toDo*> Basededonnee::recherchelistetodo(std::string date, std::string date2,int idCONTACT,bool parDATE,bool parCONTACT)
{
    list<toDo*> lc;

if(parDATE&&parCONTACT)
  { if(!recherchelistetodopaContact(idCONTACT).empty()&&!recherchelistetodopardate(date,date2).empty())
    {
      for(auto it:recherchelistetodopaContact(idCONTACT))
      {    for(auto itt:recherchelistetodopardate(date,date2))
        {
            if(it==itt)
                lc.push_back(it);
        }
     }

      return lc;

     }else{
           if((! recherchelistetodopardate(date,date2).empty()))
                 return recherchelistetodopaContact(idCONTACT);
           else {
               if(recherchelistetodopaContact(idCONTACT).empty())
                {
                   return  recherchelistetodopardate(date,date2);
                 }
            }
       }

      }
        else{
                 if(parCONTACT)
                      return recherchelistetodopaContact(idCONTACT);
                   else {if(parDATE)
                          return recherchelistetodopardate(date,date2);
                 }
             }
}
/**
 * @brief  implementation de la methode Nombredecontact()
 * @author  TRAORE MOUSSA
 * @date decembre 2021
 */


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

/**
 * @brief sauvegarde de la base de onnée
 * @author BELLEGUEULLE Mathieu
 * @date Décembre 2021
 */
void Basededonnee::sauvegarder()
{

  GestionContact gctotal = gc; //liste actuel
  getAllContact(); //gc contient la base de donnée
  GestionContact gc1 =gc;
  for(auto it:gctotal.getContactList())
  {
      if(it->getId()!=-1)
      {
           Contact * test = gc1.getContactByID(it->getId());
           if(test==nullptr)
           {
                  AjoutContact(it);
           }
          else
          {
             ModifiContact(it);
             if(it->getGestionInteraction().getSize()!=0)
                for(auto inter : it->getGestionInteraction().getInteractionList())
                    if (inter->getID()==-1)
                        AjoutInter(inter);
          }
      }
      //identifiant inconnu
      else
      {
          AjoutContact(it);
      }
  }
}

