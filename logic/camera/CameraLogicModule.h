//
// Created by nidwe on 4/1/22.
//

#ifndef SPECTRACS_CAMERALOGICMODULE_H
#define SPECTRACS_CAMERALOGICMODULE_H

#include <QObject>
#include <QtMultimedia>
#include <QCamera>

class CameraLogicModule:public QObject {
    Q_OBJECT

public:
    explicit CameraLogicModule(QObject *parent = nullptr);
    bool checkCameraAvailability();

    QCamera* getCamera();
};


#endif //SPECTRACS_CAMERALOGICMODULE_H
