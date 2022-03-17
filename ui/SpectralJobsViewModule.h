//
// Created by nidwe on 3/17/22.
//

#ifndef SPECTRACS_SPECTRALJOBSVIEWMODULE_H
#define SPECTRACS_SPECTRALJOBSVIEWMODULE_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>

#include "ui/SpectralJobOverviewViewModule.h"

class SpectralJobsViewModule: public QListWidget {
public:
    explicit SpectralJobsViewModule(QWidget *parent = nullptr);
};


#endif //SPECTRACS_SPECTRALJOBSVIEWMODULE_H
