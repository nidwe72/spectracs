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

class SpectralJobViewModule: public QWidget {
public:
    explicit SpectralJobViewModule(QWidget *parent = nullptr);

private:
    QImageCapture* imageCapture= nullptr;
    QMediaCaptureSession* captureSession= nullptr;
    QCamera *camera= nullptr;

private slots:

    void handleButton();
    void processCapturedImage(int requestId, const QImage &img);
    void displayCaptureError(int, QImageCapture::Error, const QString &errorString);


};


#endif //SPECTRACS_SPECTRALJOBVIEWMODULE_H
