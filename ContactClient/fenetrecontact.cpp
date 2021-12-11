#include "fenetrecontact.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>
#include <iostream>


FenetreContact::FenetreContact( QWidget *parent): QDialog(parent)
{  
    QVBoxLayout * VL=new QVBoxLayout();

    Erreur = new QLabel(); //sert a afficher des éventeuels messages d'erreurs

    VL->addWidget(Erreur);

    QHBoxLayout * HL1= new QHBoxLayout();

    QVBoxLayout * VL1 = new QVBoxLayout();

    QFormLayout* FL = new QFormLayout();

    QHBoxLayout* HL = new QHBoxLayout();

    QLabel* LNom= new QLabel("Nom : ");
    LENom = new QLineEdit();
    FL->addRow(LNom, LENom);

    QLabel* LPrenom= new QLabel("Prénom : ");
    LEPrenom = new QLineEdit();
    FL->addRow(LPrenom, LEPrenom);

    QLabel* LEntreprise= new QLabel("Entreprise : ");
    LEEntreprise = new QLineEdit();
    FL->addRow(LEntreprise, LEEntreprise);

    QLabel* LTelephone= new QLabel("Téléphone : ");
    LETelephone = new QLineEdit();
    FL->addRow(LTelephone, LETelephone);

    QLabel* LAdresseMail= new QLabel("Adresse mail : ");
    LEAdresseMail = new QLineEdit();
    FL->addRow(LAdresseMail, LEAdresseMail);

    HL1->addLayout(FL);

    IW = new ImageWidget(this,":/anonyme.jpg");
    setCheminPhoto(":/anonyme.jpg");

    VL1->addWidget(IW);

    QPushButton * BParcourir = new QPushButton("Parcourir");

    VL1->addWidget(BParcourir);

    HL1->addLayout(VL1);

    VL->addLayout(HL1);

    QPushButton* BAccepter = new QPushButton("Accepter");
    QPushButton* BRefuser = new QPushButton("Refuser");

    HL->addWidget(BAccepter);
    HL->addWidget(BRefuser);


    VL->addLayout(HL);

    this->setLayout(VL);

    connect(BAccepter, SIGNAL(clicked()), this, SLOT(sauvegarde()));
    connect(this, SIGNAL(fini()), this, SLOT(accept()));
    connect(BRefuser, SIGNAL(clicked()), this, SLOT(reject()));
    connect(BParcourir, SIGNAL(clicked()), this, SLOT(ParcourirImage()));

}

FenetreContact::~FenetreContact()
{
    delete IW;
}

QString FenetreContact::getNom() const
{
    return nom;
}

QString FenetreContact::getPrenom() const
{
    return prenom;
}

QString FenetreContact::getEntreprise() const
{
    return entreprise;
}

QString FenetreContact::getTel() const
{
    return tel;
}

QString FenetreContact::getMail() const
{
    return mail;
}
/**
 * @brief reprise de la fonction éponyme dans FenetreContact. Compare la valeur donnée au modèle d'une adresse e-mail en vérifiant l'absence de motifs interdits
 * @param value Adresse Mail à vérifier
 * @author BELLEGUEULLE Mathieu
 * @date decembre 2021
 */
void FenetreContact::setMail(const QString &value)
{
    if(!value.contains('@')){throw "Adresse mail non valide : absence de @";}
    if(value.contains(".@")){throw "Adresse mail non valide : . devant un @";}
    if(value.contains("..")){throw "Adresse mail non valide : deux . adjacant";}
    if(value.lastIndexOf('@')>value.lastIndexOf('.')){throw "Adresse mail non valide : adresse de domaine invalide";}
    mail = value;
}

QString FenetreContact::getCheminPhoto() const
{
    return cheminPhoto;
}

void FenetreContact::setCheminPhoto(const QString &value)
{
    cheminPhoto = value;
}

void FenetreContact::setNom(const QString &value)
{
    nom = value;
}

void FenetreContact::setPrenom(const QString &value)
{
    prenom = value;
}

void FenetreContact::setEntreprise(const QString &value)
{
    entreprise = value;
}
/**
 * @brief Compare la valeur donnée au modèle d'un numéro de téléphone par une expression régulière.
 * @param value Numéro de téléphone à vérifier
 * @author BELLEGUEULLE Mathieu
 * @date decembre 2021
 */
void FenetreContact::setTel(const QString &value)
{
    QRegExp eval("^\\+{0,1}(\\d|\\-|\\s|\\((\\d|\\-?)*\\))*$");
    bool test = eval.exactMatch(value);
    if(!test){throw "Numéro de téléphone invalide";}
    tel = value;
}

void FenetreContact::ParcourirImage()
{
    QString fileName = QFileDialog::getOpenFileName (this ,"Ouvrir une image", ".");
    try
    {
        IW->setImage(fileName);
        setCheminPhoto(fileName);
        Erreur->setText("");
    } catch (const char* s) {Erreur->setText(s);}
}

void FenetreContact::sauvegarde()
{
    try
    {
        setNom(LENom->text());
        setPrenom(LEPrenom->text());
        setEntreprise(LEEntreprise->text());
        setTel(LETelephone->text());
        setMail(LEAdresseMail->text());
        emit fini();
    } catch (std::string string) {
        Erreur->setText(QString::fromStdString(string));
    } catch (const char* s) {
        Erreur->setText(s);
    }

}
