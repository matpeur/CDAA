#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>

class Contact : public QObject
{
    Q_OBJECT
public:
    explicit Contact(QObject *parent = nullptr);

signals:

};

#endif // CONTACT_H
