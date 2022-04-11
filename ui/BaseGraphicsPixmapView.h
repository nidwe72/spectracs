//
// Created by nidwe on 4/11/22.
//

#ifndef SPECTRACS_BASEGRAPHICSPIXMAPVIEW_H
#define SPECTRACS_BASEGRAPHICSPIXMAPVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <QPixmap>
#include <QImage>
#include <QPen>


class BaseGraphicsPixmapView : public QGraphicsView {
public:
    explicit BaseGraphicsPixmapView(QWidget *parent = nullptr);

private:
    QGraphicsPixmapItem* pixMapItem;

protected:
    void resizeEvent(QResizeEvent *event) override;

};


#endif //SPECTRACS_BASEGRAPHICSPIXMAPVIEW_H
