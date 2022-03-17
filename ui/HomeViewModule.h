//
// Created by nidwe on 3/17/22.
//

#ifndef SPECTRACS_HOMEVIEWMODULE_H
#define SPECTRACS_HOMEVIEWMODULE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

#include "ui/SpectralJobsViewModule.h"

class HomeViewModule : public QWidget {

public:
    explicit HomeViewModule(QWidget *parent = nullptr);
    QPushButton* getCreateSpectralJobButton();

private:
    QPushButton* createSpectralJobButton;
};


#endif //SPECTRACS_HOMEVIEWMODULE_H
