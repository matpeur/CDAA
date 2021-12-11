#include "visutodowidget.h"

VisuTodoWidget::VisuTodoWidget(toDo *t,QWidget *parent) : QWidget(parent)
{
    Todo = t;
    QVBoxLayout *VL = new QVBoxLayout();
    try {
        Date date(Todo->getDate());
        QDate d(date.getDate()->tm_year+1900, date.getDate()->tm_mon+1, date.getDate()->tm_mday);
        QDateEdit *DateInter = new QDateEdit(d);
        DateInter->setEnabled(false);
        VL->addWidget(DateInter);
    }  catch (char const* s) {
        std::cout<<s;
    }
        QTextEdit *LEContenu = new QTextEdit(QString::fromStdString(Todo->getContenu()));
        LEContenu->setEnabled(false);
    VL->addWidget(LEContenu);
    this->setLayout(VL);
}
