#include "visuinteractionwidget.h"

VisuInteractionWidget::VisuInteractionWidget(Interaction * i,QWidget *parent) : QWidget(parent)
{
    interaction = i;
    QVBoxLayout *VL = new QVBoxLayout();
        Date date(i->getDate());
        QDate d(date.getDate()->tm_yday+1900, date.getDate()->tm_mon+1, date.getDate()->tm_mday);
        DateInter = new QDateEdit(d);
        DateInter->setEnabled(false);
    VL->addWidget(DateInter);
        LEContenu = new QTextEdit(QString::fromStdString(i->getContenu()));
        LEContenu->setEnabled(false);
    VL->addWidget(LEContenu);
        CBTD = new QComboBox();
        for (auto& it : i->getGestionToDo().getToDoList())
        {
            CBTD->addItem(QString::fromStdString(it.getContenu()));
        }

}
