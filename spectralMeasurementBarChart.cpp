#include "spectralMeasurementBarChart.h"

SpectralMeasurementBarChart::SpectralMeasurementBarChart():QChartView()
{
    QChart* chart = new QChart();
    setChart(chart);

    ApplicationContext* applicationContext=ApplicationContext::getInstance();
    SpectrasServerResponseHandler* spectrasServerResponseHandler=applicationContext->getSpectrasServerResponseHandler();

    QObject::connect(
        spectrasServerResponseHandler,
        &SpectrasServerResponseHandler::onSpectralMeasurement,
        this,
                &SpectralMeasurementBarChart::foo,Qt::QueuedConnection);


}

void SpectralMeasurementBarChart::foo(SpectralMeasurement *spectralMeasurement)
{
    QChart* chart=new QChart();
    this->setChart(chart);

    QMap<float, float>* spectralMeasurementValues=spectralMeasurement->getValues();

    QBarSet* set0 = new QBarSet("measurement");
    QStringList categories;

    float maximalValue=0;
    foreach( float nanometer, spectralMeasurementValues->keys() ){
        set0->append(spectralMeasurementValues->value(nanometer));
        if(maximalValue>maximalValue){
          maximalValue=spectralMeasurementValues->value(nanometer);
        }
        categories.append(QString::number(nanometer));
    }


    QBarSeries *series = new QBarSeries();
    series->append(set0);

    chart->addSeries(series);
    chart->setTitle("");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,maximalValue);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

}
