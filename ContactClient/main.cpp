#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include "gestioncontact.h"
#include "contact.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::string m= "Martin";
    GestionContact ContactClient;
    ContactClient.addContact(m,"Pierre","FournierSARL","0756321487","photo.jpg");
    std::list<Contact> liste = ContactClient.getContactList();
    for (auto & it : liste)
    {
        it.addInteraction("Rendez-vous client RAS\n@todo rappeler pour le @date 17/12/2021\n@todo comfirmer sa commande\n@todo rappeler pour le @date 05/01/2022");
        std::cout<<it<<std::endl;
    }
    for (auto & it : liste)
    {
        list<Interaction> lI = it.getGestionInteraction().getInteractionList();
        for (auto & it2 : lI )
            std::cout<<it2<<std::endl;
    }

    return a.exec();
}
