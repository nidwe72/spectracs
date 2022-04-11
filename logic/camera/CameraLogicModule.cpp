//
// Created by nidwe on 4/1/22.
//

#include "CameraLogicModule.h"

CameraLogicModule::CameraLogicModule(QObject *parent) : QObject(parent) {
}

bool CameraLogicModule::checkCameraAvailability() {
    bool result= false;
    if (QMediaDevices::videoInputs().count() > 0){
        result= true;
    }
    return result;
}


QCamera* CameraLogicModule::getCamera() {
    QCamera* result= nullptr;
    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    for (const QCameraDevice &cameraDevice : cameras) {
        if (cameraDevice.description().contains("OBS"))
            result = new QCamera(cameraDevice);
    }
    return result;
}
