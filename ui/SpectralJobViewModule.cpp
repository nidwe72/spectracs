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
    SpectralMeasurementBarChart* spectralMeasurementBarChart=new SpectralMeasurementBarChart();
    layout->addWidget(spectralMeasurementBarChart,1,0,1,2);
    */

    //CameraLogicModule *cameraLogicModule = new CameraLogicModule();

    camera=new QCamera(QMediaDevices::defaultVideoInput());

    buttonImport->setText(camera->cameraDevice().description());

    captureSession=new QMediaCaptureSession();
    captureSession->setCamera(camera);

    imageCapture = new QImageCapture;
    captureSession->setImageCapture(imageCapture);


    QVideoWidget* viewfinder = new QVideoWidget;
    captureSession->setVideoOutput(viewfinder);

    layout->addWidget(viewfinder,1,0,1,2);
    viewfinder->show();

    camera->start();

    if(imageCapture->isReadyForCapture()){
        buttonImport->setText("ready for capture");
    }else{
        buttonImport->setText("not for capture");
    }

    imageCapture->setResolution(640,480);
    imageCapture->setFileFormat(imageCapture->JPEG);

    QPushButton* backButton=new QPushButton();
    backButton->setText("Back");
    layout->addWidget(backButton,3,0,1,1);

    QPushButton* saveButton=new QPushButton();
    saveButton->setText("Save");
    layout->addWidget(saveButton,3,1,1,1);

    connect(saveButton, &QPushButton::released, this, &SpectralJobViewModule::handleButton);


    connect(imageCapture, &QImageCapture::imageCaptured, this, &SpectralJobViewModule::processCapturedImage);
    connect(imageCapture, &QImageCapture::errorOccurred, this, &SpectralJobViewModule::displayCaptureError);

}

void SpectralJobViewModule::handleButton() {
    qDebug() << "handleButton//1";
    //imageCapture->capture();

    if (camera->cameraFormat().isNull()) {
        auto formats = camera->cameraDevice().videoFormats();
        if (!formats.isEmpty()) {
            // Choose a decent camera format: Maximum resolution at at least 30 FPS
            // we use 29 FPS to compare against as some cameras report 29.97 FPS...
            QCameraFormat bestFormat;
            for (const auto &fmt : formats) {
                if (bestFormat.maxFrameRate() < 29 && fmt.maxFrameRate() > bestFormat.maxFrameRate())
                    bestFormat = fmt;
                else if (bestFormat.maxFrameRate() == fmt.maxFrameRate() &&
                         bestFormat.resolution().width()*bestFormat.resolution().height() <
                         fmt.resolution().width()*fmt.resolution().height())
                    bestFormat = fmt;
            }

            qDebug()<< "width: " << bestFormat.resolution().width();
            qDebug()<< "height: " << bestFormat.resolution().height();

            camera->setCameraFormat(bestFormat);
        }
    }

    QThread::msleep(500);

    qDebug() << "handleButton//2";

    imageCapture->capture();
}

void SpectralJobViewModule::processCapturedImage(int requestId, const QImage &img) {
    qDebug() << "processCapturedImage()";

    //imageCapture->captureToFile("/home/nidwe/testCapture.jpg");

    std::vector<double> v = {1., 2., 3., 4., 5., 6. };
    std::vector<std::size_t> shape = { 1, 6 };
    auto a1 = xt::adapt(v, shape);

    a1(1,1)=100;

    std::cout << a1 << std::endl;


}

void SpectralJobViewModule::displayCaptureError(int id, const QImageCapture::Error error, const QString &errorString)
{
    Q_UNUSED(id);
    Q_UNUSED(error);
    QMessageBox::warning(this, tr("Image Capture Error"), errorString);
}
