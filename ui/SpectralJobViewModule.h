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

#include "spectralMeasurementBarChart.h"

#include "logic/camera/CameraLogicModule.h"

class SpectralJobViewModule: public QWidget {
public:
    explicit SpectralJobViewModule(QWidget *parent = nullptr);
};


#endif //SPECTRACS_SPECTRALJOBVIEWMODULE_H
