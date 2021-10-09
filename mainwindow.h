#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QGridLayout>
#include <QPushButton>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QTextEdit>
#include <QLineSeries>
#include <QPointF>
#include <QChart>
#include <QChartView>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QVariantMap>

#include "spectrasServerResponseHandler.h"

#include "spectralMeasurementBarChart.h"

#include "applicationContext.h"

#include "spectralMeasurementDbEntity.h"

#include "qdbmanager/qdbmanager.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTextEdit* testText;

public slots:    
    void handleMeasurementRequest();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
