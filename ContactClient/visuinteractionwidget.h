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

signals:

};

#endif // VISUINTERACTIONWIDGET_H
