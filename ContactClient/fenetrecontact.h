#ifndef FENETRECONTACT_H
#define FENETRECONTACT_H

#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QLabel>
#include "imagewidget.h"


class FenetreContact : public QDialog
{

    Q_OBJECT

    public:
        FenetreContact(QWidget *parent = nullptr);
        ~FenetreContact();

        QString getNom() const;
        void setNom(const QString &value);

        QString getPrenom() const;
        void setPrenom(const QString &value);

        QString getEntreprise() const;
        void setEntreprise(const QString &value);

        QString getTel() const;
        void setTel(const QString &value);

        QString getMail() const;
        void setMail(const QString &value);

        QString getCheminPhoto() const;
        void setCheminPhoto(const QString &value);

private:
        ImageWidget * IW;
        QString nom;
        QString prenom;
        QString entreprise;
        QString tel;
        QString mail;
        QString cheminPhoto;

        QLineEdit *LENom;
        QLineEdit *LEPrenom;
        QLineEdit *LEEntreprise;
        QLineEdit *LETelephone;
        QLineEdit *LEAdresseMail;

        QLabel *Erreur;

    public slots:
        void ParcourirImage();
        void sauvegarde();
    signals :
        void fini();

};

#endif // FENETRECONTACT_H
