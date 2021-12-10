#ifndef VISUCONTACTWIDGET_H
#define VISUCONTACTWIDGET_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QLabel>
#include "contact.h"
#include "imagewidget.h"

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

signals:

};

#endif // VISUCONTACTWIDGET_H
