#include "visucontactwidget.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>

VisuContactWidget::VisuContactWidget(Contact *c,QWidget *parent) : QWidget(parent)
{
    contact = c;

    QVBoxLayout * VL=new QVBoxLayout();

    Erreur = new QLabel(); //sert a afficher des éventeuels messages d'erreurs

    VL->addWidget(Erreur);

    QHBoxLayout * HL1= new QHBoxLayout();

    QVBoxLayout * VL1 = new QVBoxLayout();

    QFormLayout* FL = new QFormLayout();

    QHBoxLayout* HL = new QHBoxLayout();

    QLabel* LNom= new QLabel("Nom : ");
    LENom = new QLineEdit(QString::fromStdString(contact->getNom()));
    LENom->setEnabled(false);
    FL->addRow(LNom, LENom);

    QLabel* LPrenom= new QLabel("Prénom : ");
    LEPrenom = new QLineEdit(QString::fromStdString(contact->getPrenom()));
    LEPrenom->setEnabled(false);
    FL->addRow(LPrenom, LEPrenom);

    QLabel* LEntreprise= new QLabel("Entreprise : ");
    LEEntreprise = new QLineEdit(QString::fromStdString(contact->getEntreprise()));
    LEEntreprise->setEnabled(false);
    FL->addRow(LEntreprise, LEEntreprise);

    QLabel* LTelephone= new QLabel("Téléphone : ");
    LETelephone = new QLineEdit(QString::fromStdString(contact->getTelephone()));
    LETelephone->setEnabled(false);
    FL->addRow(LTelephone, LETelephone);

    QLabel* LAdresseMail= new QLabel("Adresse mail : ");
    LEAdresseMail = new QLineEdit(QString::fromStdString(contact->getMail()));
    LEAdresseMail->setEnabled(false);
    FL->addRow(LAdresseMail, LEAdresseMail);

    HL1->addLayout(FL);

    IW = new ImageWidget(this,QString::fromStdString(c->getPhoto()));

    VL1->addWidget(IW);

    QPushButton * BParcourir = new QPushButton("Parcourir");

    VL1->addWidget(BParcourir);

    HL1->addLayout(VL1);

    VL->addLayout(HL1);

    QPushButton* BModifier = new QPushButton("Modifier");
    QPushButton* BSupprimer = new QPushButton("Supprimer");

    HL->addWidget(BModifier);
    HL->addWidget(BSupprimer);


    VL->addLayout(HL);

    this->setLayout(VL);
}
