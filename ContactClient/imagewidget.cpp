#include "imagewidget.h"
#include <iostream>

ImageWidget::ImageWidget(QWidget *parent, QString chemin) : QWidget(parent)
{
    setImage(chemin);
}
void ImageWidget::paintEvent ( QPaintEvent* e )
{

    QWidget::paintEvent(e);

    QPainter paint (this);
    while(loaded == 0){}

    QPixmap pixmap = QPixmap::fromImage(Image.scaled(this->width(), this->height()));
    paint.drawPixmap(0, 0, pixmap) ;


};

void ImageWidget::setImage(QString chemin)
{

    loaded = 0;
    QImage Test;
    int i=0;
    while(loaded==0&&i<10)
    {
        loaded = Test.load(chemin);
        i++;
    }
    if(Test.isNull())
    {
        throw "Impossible de charger l'image";
    }
    Image.load(chemin);
    repaint();

}
