#include "fenetreajoutinter.h"
#include <iostream>
#include <QHBoxLayout>
#include "date.h"



FenetreAjoutInter::FenetreAjoutInter(QWidget *parent, GestionContact *gC) : QDialog(parent)
{
    nbTD=0;
    VL = new QVBoxLayout(this);

    QComboBox *CB = new QComboBox(this);
    Nom = new QLabel(this);


    for (auto& it : gC->getContactList())
    {
        CB->addItem(QString::fromStdString(it.getPrenom()+" "+it.getNom()+" de "+it.getEntreprise()));
        Contacts.append(it);
    }

    VL->addWidget(CB);

    this->setLayout(VL);

    connect(CB, SIGNAL(currentIndexChanged(int)), this, SLOT(selection(int)));
}

FenetreAjoutInter::~FenetreAjoutInter()
{

}

void FenetreAjoutInter::selection(int i)
{

    cont = Contacts.at(i);
    Nom->setText(QString::fromStdString("Vous avez choisi "+cont.getPrenom()+" "+cont.getNom()+" de "+cont.getEntreprise()));
    if (VL->count()==1)
    {
    VL->addWidget(Nom);
    QHBoxLayout *HL = new QHBoxLayout();
    Contenu = new QTextEdit(this);
    HL->addWidget(Contenu);
    QPushButton *BTodo = new QPushButton("Ajouter une tâche à faire");
    HL->addWidget(BTodo);
    VL->addLayout(HL);

    QHBoxLayout *HL1 = new QHBoxLayout();
    QPushButton *BAccepter = new QPushButton("Enregistrer");
    QPushButton *BQuitter = new QPushButton("Quitter");
    HL1->addWidget(BAccepter);
    HL1->addWidget(BQuitter);

    VL->addLayout(HL1);

    connect(BTodo, SIGNAL(clicked()), this, SLOT(ajoutTache()));
    connect(BQuitter, SIGNAL(clicked()), this, SLOT(reject()));
    connect(BAccepter, SIGNAL(clicked()), this, SLOT(sauvegarde()));
    connect(this, SIGNAL(fini()), this, SLOT(accept()));
    }
}

void FenetreAjoutInter::ajoutTache()
{
    QHBoxLayout * HLa = new QHBoxLayout();
    QLabel *LaC = new QLabel("Contenu : ");
    QLineEdit * LEC = new QLineEdit();
    VLE.append(LEC);
    QLabel * LaD = new QLabel("Date");
    QDateEdit * DE = new QDateEdit();
    VDE.append(DE);

    Date d;
    tm *date = d.getDate();
    DE->setDate(QDate(date->tm_year+1900, date->tm_mon+1,date->tm_mday));


    HLa->addWidget(LaC);
    HLa->addWidget(LEC);
    HLa->addWidget(LaD);
    HLa->addWidget(DE);

    VL->insertLayout(3+nbTD,HLa);

    nbTD++;
}

void FenetreAjoutInter::sauvegarde()
{
    std::string interaction = Contenu->document()->toRawText().toStdString();
    for (int t=0; t<nbTD;t++)
    {
       std::string C = VLE[t]->text().toStdString();
        if(C!="")
        {
            interaction +="\n@todo "+C;
            QDate date = VDE[t]->date();
            if(QDate::currentDate()!=date)
            {
                interaction+=" @date "+to_string(date.day())+"/"+to_string(date.month())+"/"+to_string(date.year());
            }
        }
    }
    cont.createInteraction(interaction);
    for (auto & it2 : cont.getGestionInteraction().getInteractionList() )
        std::cout<<it2<<std::endl;
    emit fini();
}
