#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include "gestioncontact.h"
#include "contact.h"
#include "interaction.h"
#include "todo.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    /*
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
    */

    Interface Inter;
    Contact c;
    Interaction I(&Inter, &c, "Test");
    std::string s = "@todo quelquechose@date 17/02/2022";
    toDo td1(&I,s);

    std::cout<<td1.toString();
    I.addToDo(td1);
    std::cout<<I<<std::endl;
    GestionContact gestion;
    gestion.addContact("Jean","Pierre","SAS","0214587823","photo.jpg");
        std::list<Contact> liste = gestion.getContactList();
    for (auto & it : liste)
    {
        it.addInteraction("Rendez-vous client RAS\n@todo rappeler pour le @date 17/12/2021\n@todo comfirmer sa commande\n@todo rappeler pour le @date 05/01/2022");
        std::cout<<it<<std::endl;
    }
    return a.exec();
}
