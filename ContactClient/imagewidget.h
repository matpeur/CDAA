#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QString>
#include <QImage>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = nullptr, QString chemin = nullptr);

    void setImage(QString chemin);

private:
    QImage Image;
    bool loaded;
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // IMAGEWIDGET_H
