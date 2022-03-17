//
// Created by nidwe on 3/17/22.
//

#include "SpectralJobOverviewViewModule.h"

SpectralJobOverviewViewModule::SpectralJobOverviewViewModule(QWidget *parent) :QWidget(parent)
{
    auto layout=new QGridLayout();
    setLayout(layout);

    auto label=new QLabel();
    label->setText("<b>[14.03.2022 16:05] first measurement</b><br/>Quality: excellent");
    layout->addWidget(label,0,0,1,1);
}
