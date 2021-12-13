#include "imagewidget.h"
#include <iostream>

ImageWidget::ImageWidget(QWidget *parent, QString chemin) : QWidget(parent)
{
    setImage(chemin);
}
/**
 * @brief Modifie l'affichage du widget pour qu'il affiche l'image placé au chemin en paramètre
 * @param e
 * @author BELLEGUEULLE Mathieu
 */
void ImageWidget::paintEvent ( QPaintEvent* e )
{

    QWidget::paintEvent(e);

    QPainter paint (this);
    while(loaded == 0){}

    QPixmap pixmap = QPixmap::fromImage(Image.scaled(this->width(), this->height()));
    paint.drawPixmap(0, 0, pixmap) ;


};
/**
 * @brief Essaie de lire l'image placé à l'URI donné en paramètre
 * @param chemin Adresse de l'image à ouvrir
 * @throw Chaine indiquant l'impossibilité de lire l'image
 * @author BELLEGUEULLE Mathieu
 */
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
