#include "mainwindow.h"
//#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    setGeometry(0,0,400,600);
    stackedWidget = new QStackedWidget();

/*
    QWidget* mainWidget=new QWidget;

    QGridLayout* layout=new QGridLayout;
    mainWidget->setLayout(layout);

    QPushButton* button=new QPushButton();
    button->setText("measure");

    layout->addWidget(button,0,0,1,1);

    connect(button, &QPushButton::released, this, &MainWindow::handleMeasurementRequest);


    testText=new QTextEdit();
    layout->addWidget(testText,1,0,1,1);

    QLineSeries *seriesOil1Thick = new QLineSeries();
*/

    //light bulb only
    /*
Red    :30798.29296875
Orange :49087.12890625
Yellow :43969.29296875
Green  :55889.83203125
Blue   :22674.767578125
Violet :23755.4453125
*/

    /*
    series->append(450, 30798.29296875f);
    series->append(500, 49087.12890625f);
    series->append(550, 43969.29296875f);
    series->append(600, 55889.83203125f);
    series->append(650, 22674.76757812f);
    series->append(700, 23755.4453125f);
    */


    //oil#1
    /*
Red    :4314.064453125
Orange :3739.27978515625
Yellow :3350.059326171875
Green  :7258.037109375
Blue   :1194.5640869140625
Violet :271.0093078613281
    */

/*
    seriesOil1Thick->append(450, 4314.064453125f);
    seriesOil1Thick->append(500, 3739.27978515625f);
    seriesOil1Thick->append(550, 3350.059326171875f);
    seriesOil1Thick->append(570, 7258.037109375f);
    seriesOil1Thick->append(600, 1194.5640869140625f);
    seriesOil1Thick->append(650, 271.0093078613281f);
*/

/*
Red    :13729.08203125
Orange :22176.126953125
Yellow :26082.470703125
Green  :38454.82421875
Blue   :12098.138671875
Violet :1437.032470703125
*/

/*
    QLineSeries *seriesOil2 = new QLineSeries();
    seriesOil2->append(450, 13729.08203125f);
    seriesOil2->append(500, 22176.126953125f);
    seriesOil2->append(550, 26082.470703125f);
    seriesOil2->append(570, 38454.82421875f);
    seriesOil2->append(600, 12098.138671875f);
    seriesOil2->append(650, 1437.032470703125f);
*/

    /*
    QLineSeries *seriesOil2Reflex = new QLineSeries();
    seriesOil2Reflex->append(650, 2851.779052734375f);
    seriesOil2Reflex->append(600, 2927.6982421875f);
    seriesOil2Reflex->append(570, 2962.71484375f);
    seriesOil2Reflex->append(550, 2235.59326171875f);
    seriesOil2Reflex->append(500, 2048.3193359375f);
    seriesOil2Reflex->append(450, 496.4708251953125f);
    */

/*
    QLineSeries *seriesOil2Reflex = new QLineSeries();
    seriesOil2Reflex->append(650, 4386.8564453125f);
    seriesOil2Reflex->append(600, 2497.695556640625f);
    seriesOil2Reflex->append(570, 3259.364013671875f);
    seriesOil2Reflex->append(550, 1892.8314208984375f);
    seriesOil2Reflex->append(500, 2814.272705078125f);
    seriesOil2Reflex->append(450, 710.54541015625f);
*/


/*
Red    :
Orange :
Yellow :
Green  :
Blue   :
Violet :
*/

    //*series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    HomeViewModule* homeViewModule=new HomeViewModule();
    stackedWidget->addWidget(homeViewModule);

    auto createSpectralJobButton=homeViewModule->getCreateSpectralJobButton();
    connect(createSpectralJobButton, &QPushButton::released, this, &MainWindow::navigateToSpectralJobViewModule);

    SpectralJobViewModule* spectralJobViewModule=new SpectralJobViewModule(this);
    stackedWidget->addWidget(spectralJobViewModule);

    stackedWidget->setCurrentIndex(0);
    setCentralWidget(stackedWidget);

    ApplicationContext *applicationContext = applicationContext->getInstance();

    /*
    QDBManager *dbm = QDBManager::create("test", "QSQLITE");
    dbm->register_entity<SpectralMeasurementDbEntity>();

    dbm->openDB("testdb.sqlite");
    dbm->createTable<SpectralMeasurementDbEntity>();

    SpectralMeasurementDbEntity* spectralMeasurementDbEntity=new SpectralMeasurementDbEntity();
    spectralMeasurementDbEntity->set_mac("Test");

    int id = 0;

    qDebug()<<"ID "<<id<<"\trows affected "<<dbm->insertOrUpdate<SpectralMeasurementDbEntity>(spectralMeasurementDbEntity);

    QListSpectralMeasurementDbEntity testEntities = dbm->listAll<SpectralMeasurementDbEntity>();
    qDebug()<<testEntities.count();
    foreach (SpectralMeasurementDbEntity* testEntity, testEntities) {
        qDebug()<<testEntity->toString();
    }

    dbm->closeDB();

    auto foo =qRegisterOrmEntity<TestEntity>;
    QOrmSession session;

    QOrmSessionConfiguration qOrmSessionConfiguration=session.configuration();

    auto token = session.declareTransaction(QOrm::TransactionPropagation::Require,
                                                    QOrm::TransactionAction::Commit);

    TestEntity* testEntity=new TestEntity();
    testEntity->setName("test");
    session.merge(testEntity);
    //session.commitTransaction();


    TestEntity* testEntity2=new TestEntity();
    testEntity2->setName("test2");
    session.merge(testEntity2);


    TestEntity* te = nullptr;

    //session.commitTransaction();


    QList<TestEntity*> testEntitityResult = session.from<TestEntity>()
                                           .select()
                                           .toVector();

    for(auto item : testEntitityResult)    {
        qDebug() << "id:" <<item ->getId() << " name: "<<item ->getName();
    }

    //session.remove(testEntity);
    */

}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::handleMeasurementRequest(){
    //QUrl qrl("http://localhost:8877/?action=measurement");
    //QUrl qrl("http://192.168.1.109:8877/?action=measurement");
    QUrl qrl("http://localhost:8877/?action=measurement");
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);


    ApplicationContext *applicationContext = applicationContext->getInstance();
    SpectrasServerResponseHandler* spectrasServerResponseHandler=applicationContext->getSpectrasServerResponseHandler();

    QObject::connect(
            manager,
            SIGNAL(finished(QNetworkReply*)),
            spectrasServerResponseHandler,
            SLOT(handleResponse(QNetworkReply*))
            );

    manager->get(QNetworkRequest(qrl));
}

void MainWindow::navigateToSpectralJobViewModule() {
    stackedWidget->setCurrentIndex(1);
}





