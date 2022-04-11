//
// Created by nidwe on 3/17/22.
//

#ifndef SPECTRACS_SPECTRALJOBVIEWMODULE_H
#define SPECTRACS_SPECTRALJOBVIEWMODULE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QChart>
#include <QChartView>

#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QImageCapture>
#include <QImage>

#include <QCameraFormat>

#include <QMessageBox>
#include "spectralMeasurementBarChart.h"

#include "logic/camera/CameraLogicModule.h"

#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

#include <xtensor/xadapt.hpp>

#include <iostream>

#include <QThread>

#include <QGraphicsScene>

#include <QGraphicsView>

#include <QPixmap>

#include <QGraphicsLineItem>

#include <QLineF>


#include "ui/BaseGraphicsPixmapView.h"







class SpectralJobViewModule: public QWidget {
public:
    explicit SpectralJobViewModule(QWidget *parent = nullptr);

private:
    QImageCapture* imageCapture= nullptr;
    QMediaCaptureSession* captureSession= nullptr;
    QCamera *camera= nullptr;
    void prepareCamera();
    void applyCameraFormat();
    void processCapturedImageBridge();

private slots:

    void handleButton();
    void processCapturedImage(int requestId, const QImage &img);
    void displayCaptureError(int, QImageCapture::Error, const QString &errorString);


};


#endif //SPECTRACS_SPECTRALJOBVIEWMODULE_H
