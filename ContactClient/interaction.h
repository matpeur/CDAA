#ifndef INTERACTION_H
#define INTERACTION_H

#include <QObject>

class Interaction : public QObject
{
    Q_OBJECT
public:
    explicit Interaction(QObject *parent = nullptr);

signals:

};

#endif // INTERACTION_H
