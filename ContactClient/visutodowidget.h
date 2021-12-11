#ifndef VISUTODOWIDGET_H
#define VISUTODOWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QTextEdit>
#include "contact.h"

class VisuTodoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VisuTodoWidget(toDo*,QWidget *parent = nullptr);

private :
    toDo *Todo;
signals:

};

#endif // VISUTODOWIDGET_H
