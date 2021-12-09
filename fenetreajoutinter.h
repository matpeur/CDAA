#ifndef FENETREAJOUTINTER_H
#define FENETREAJOUTINTER_H

#include <QDialog>
#include <QVBoxLayout>
#include <QComboBox>
#include <QVector>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QDateEdit>
#include "gestioncontact.h"
#include "contact.h"

class FenetreAjoutInter : public QDialog
{
    Q_OBJECT
public:
    explicit FenetreAjoutInter(QWidget *parent = nullptr, GestionContact * = nullptr);
    ~FenetreAjoutInter();

private :
    QVBoxLayout * VL;
    QVector<Contact> Contacts;
    QLabel * Nom;
    QTextEdit * Contenu;
    Contact cont;
    QVector<QLineEdit*> VLE;
    QVector<QDateEdit*> VDE;
    int nbTD;
signals:
    void fini();

public slots:
    void selection(int);
    void ajoutTache();
    void sauvegarde();
};

#endif // FENETREAJOUTINTER_H
