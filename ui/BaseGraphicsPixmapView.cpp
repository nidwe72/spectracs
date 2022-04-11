//
// Created by nidwe on 4/11/22.
//

#include "BaseGraphicsPixmapView.h"

BaseGraphicsPixmapView::BaseGraphicsPixmapView(QWidget *parent) {

    QGraphicsScene *scene = new QGraphicsScene (this);
    pixMapItem=new QGraphicsPixmapItem(QPixmap::fromImage(QImage("/home/nidwe/testPhilips.png")));
    scene->addItem(pixMapItem);

    QGraphicsLineItem *lineItem = new QGraphicsLineItem(600, 1200, 2592, 1200);

    QPen pen;  // creates a default pen

    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    pen.setBrush(Qt::red);
    lineItem->setPen(pen);

    scene->addItem(lineItem);
    
    setScene(scene);
}

void BaseGraphicsPixmapView::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    fitInView(pixMapItem, Qt::KeepAspectRatio);
}
