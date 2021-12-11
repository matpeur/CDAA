#ifndef VISUCONTACTWIDGET_H
#define VISUCONTACTWIDGET_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QLabel>
#include "contact.h"
#include "imagewidget.h"

/**
 * @brief Classe VIsuContactWidget, widget spécialisé pour la visualisation des contacts, calquer sur la boite de dialogue FenetreContact
 * @author BELEGUEULLE Mathieu
 * @date decembre 2021
 */
class VisuContactWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VisuContactWidget(Contact *,QWidget *parent = nullptr);
private :
    Contact *contact;
    ImageWidget * IW;

    QLineEdit *LENom;
    QLineEdit *LEPrenom;
    QLineEdit *LEEntreprise;
    QLineEdit *LETelephone;
    QLineEdit *LEAdresseMail;

    QLabel *Erreur;

    QString nom;
    QString prenom;
    QString entreprise;
    QString mail;
    QString photo;
    QString tel;

    void setTel(const QString &value);
    void setMail(const QString &value);


signals:
    void verouille(bool);
    void efface(Contact *);

public slots :
    void supprimer();
    void sauvegarde();
    void parcourir();
};

#endif // VISUCONTACTWIDGET_H
