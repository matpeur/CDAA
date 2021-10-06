#ifndef TODO_H
#define TODO_H

#include <QObject>

class toDo : public QObject
{
    Q_OBJECT
public:
    explicit toDo(QObject *parent = nullptr);

signals:

};

#endif // TODO_H
