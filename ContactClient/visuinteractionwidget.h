#ifndef VISUINTERACTIONWIDGET_H
#define VISUINTERACTIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include "contact.h"
/**
 * @brief Classe VisuInteractionWidget, widget spécialisé pour la visualisation des intéractions
 * @author BELEGUEULLE Mathieu
 * @date decembre 2021
 */
class VisuInteractionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VisuInteractionWidget(Interaction*,QWidget *parent = nullptr);

private :

    QDateEdit *DateInter;
    QComboBox *CBTD;
    QTextEdit *LEContenu;
    Interaction * interaction;
    QVector<toDo*> Vtodo;
public slots:
    void envoierequete(int);
signals:
    void afficheToDo(toDo*);
};

#endif // VISUINTERACTIONWIDGET_H
