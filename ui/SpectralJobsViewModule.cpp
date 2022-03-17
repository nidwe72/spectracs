//
// Created by nidwe on 3/17/22.
//

#include "SpectralJobsViewModule.h"

SpectralJobsViewModule::SpectralJobsViewModule(QWidget *parent): QListWidget(parent) {

    /*
    auto item = new QListWidgetItem();

    auto createButton=new QPushButton();
    createButton->setText("new Measurement");

    item->setSizeHint(createButton->sizeHint());
    this->addItem(item);
    setItemWidget(item,createButton);
*/

    auto spectralJobOverviewViewModule=new SpectralJobOverviewViewModule();
    auto spectralJobOverviewViewModuleItem = new QListWidgetItem();
    spectralJobOverviewViewModuleItem->setSizeHint(spectralJobOverviewViewModule->sizeHint());
    this->addItem(spectralJobOverviewViewModuleItem);
    setItemWidget(spectralJobOverviewViewModuleItem,spectralJobOverviewViewModule);
}
