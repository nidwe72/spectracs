//
// Created by nidwe on 3/17/22.
//

#include "HomeViewModule.h"

HomeViewModule::HomeViewModule(QWidget *parent) : QWidget(parent) {

    QGridLayout* layout=new QGridLayout();
    setLayout(layout);

    QWidget* jobsViewModule=new QWidget();

    auto spectralJobsViewModule=new SpectralJobsViewModule(this);
    layout->addWidget(spectralJobsViewModule,0,0,1,2);

    createSpectralJobButton=new QPushButton();
    createSpectralJobButton->setText("New measurement");
    layout->addWidget(createSpectralJobButton,1,0,1,1);

    QPushButton* settingsButton=new QPushButton();
    settingsButton->setText("Settings");
    layout->addWidget(settingsButton,1,1,1,1);



}

QPushButton *HomeViewModule::getCreateSpectralJobButton() {
    return createSpectralJobButton;
}
