//
// Created by nidwe on 3/17/22.
//

#include "SpectralJobViewModule.h"




SpectralJobViewModule::SpectralJobViewModule(QWidget *parent) : QWidget(parent) {
    QGridLayout* layout=new QGridLayout();
    setLayout(layout);

    QPushButton* button=new QPushButton();
    button->setText("measure");
    layout->addWidget(button,0,0,1,1);

    QPushButton* buttonImport=new QPushButton();
    buttonImport->setText("import");
    layout->addWidget(buttonImport,0,1,1,1);

    /*
    QChart *chart = new QChart();
    chart->legend()->hide();


    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    */

    SpectralMeasurementBarChart* spectralMeasurementBarChart=new SpectralMeasurementBarChart();

    //layout->addWidget(chartView,2,0,1,1);
    layout->addWidget(spectralMeasurementBarChart,1,0,1,2);

    QPushButton* backButton=new QPushButton();
    backButton->setText("Back");
    layout->addWidget(backButton,2,0,1,1);

    QPushButton* saveButton=new QPushButton();
    saveButton->setText("Save");
    layout->addWidget(saveButton,2,1,1,1);

    CameraLogicModule *cameraLogicModule = new CameraLogicModule();
    bool hasCamera = cameraLogicModule->checkCameraAvailability();
    if(hasCamera){
        buttonImport->setText("has Camera");
    }



}
