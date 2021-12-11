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

    try {
        IW = new ImageWidget(this,QString::fromStdString(c->getPhoto()));
    } catch (const char* s) {Erreur->setText(s);}

    VL1->addWidget(IW);

    QPushButton * BParcourir = new QPushButton("Parcourir");

    VL1->addWidget(BParcourir);

    HL1->addLayout(VL1);

    VL->addLayout(HL1);

    QPushButton* BModifier = new QPushButton("Modifier");
    QPushButton* BSauvegarder = new QPushButton("Sauvegarder");
    BSauvegarder->hide();
    QPushButton* BSupprimer = new QPushButton("Supprimer");

    HL->addWidget(BModifier);
    HL->addWidget(BSauvegarder);
    HL->addWidget(BSupprimer);


    VL->addLayout(HL);

    this->setLayout(VL);

    connect(BModifier, SIGNAL(clicked()), BSauvegarder, SLOT(show()));
    connect(BModifier, SIGNAL(clicked()), BModifier, SLOT(hide()));
    connect(BModifier, SIGNAL(clicked(bool)), LENom, SLOT(setDisabled(bool)));
    connect(BModifier, SIGNAL(clicked(bool)), LEPrenom, SLOT(setDisabled(bool)));
    connect(BModifier, SIGNAL(clicked(bool)), LEEntreprise, SLOT(setDisabled(bool)));
    connect(BModifier, SIGNAL(clicked(bool)), LEAdresseMail, SLOT(setDisabled(bool)));
    connect(BModifier, SIGNAL(clicked(bool)), LETelephone, SLOT(setDisabled(bool)));
    connect(BModifier, SIGNAL(clicked(bool)), BParcourir, SLOT(setDisabled(bool)));
    connect(BSupprimer, SIGNAL(clicked()), this, SLOT(supprimer()));
    connect(BSauvegarder, SIGNAL(clicked()),this, SLOT(sauvegarde()));
    connect(BParcourir, SIGNAL(clicked()), this, SLOT(parcourir()));
}
/**
 * @brief reprise de la fonction ParcourirImages dans FenetreContact. Ouvre une fenêtre de dialogue pour sélectionner une image de profil.
 * @author BELLEGUEULLE Mathieu
 * @date decembre 2021
 */
void VisuContactWidget::parcourir()
{
    QFileDialog *fd = new QFileDialog(this ,"Ouvrir une image", ".");
    fd->exec();
    if(fd->AcceptOpen)
    {
        QString fileName = QFileDialog::getOpenFileName (this ,"Ouvrir une image", ".");

        try
        {
            IW->setImage(fileName);
             photo = fileName.toStdString();
             Erreur->setText("");
        } catch (const char* s) {Erreur->setText(s);}
    }
}
/**
 * @brief reprise de la fonction éponyme dans FenetreContact. Compare la valeur donnée au modèle d'une adresse e-mail en vérifiant l'absence de motifs interdits
 * @param value Adresse Mail à vérifier
 * @author BELLEGUEULLE Mathieu
 * @date decembre 2021
 */
void VisuContactWidget::setMail(const QString &value)
{
    if(!value.contains('@')){throw "Adresse mail non valide : absence de @";}
    if(value.contains(".@")){throw "Adresse mail non valide : . devant un @";}
    if(value.contains("..")){throw "Adresse mail non valide : deux . adjacant";}
    if(value.lastIndexOf('@')>value.lastIndexOf('.')){throw "Adresse mail non valide : adresse de domaine invalide";}
    mail = value.toStdString();
}
/**
 * @brief reprise de la méthode de éponyme dans FenetreContact. Compare la valeur donnée au modèle d'un numéro de téléphone par une expression régulière.
 * @param value Numéro de téléphone à vérifier
 * @author BELLEGUEULLE Mathieu
 * @date decembre 2021
 */
void VisuContactWidget::setTel(const QString &value)
{
    QRegExp eval("^\\+{0,1}(\\d|\\-|\\s|\\((\\d|\\-?)*\\))*$");
    bool test = eval.exactMatch(value);
    if(!test){throw "Numéro de téléphone invalide";}
    tel = value.toStdString();
}
