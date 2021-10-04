#ifndef SPECTRALMEASUREMENTBARCHART_H
#define SPECTRALMEASUREMENTBARCHART_H

#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>






#include "spectralMeasurement.h"
#include "applicationContext.h"

class SpectralMeasurementBarChart : public QChartView
{
       Q_OBJECT
public:
    explicit SpectralMeasurementBarChart();

public slots:
    void foo(SpectralMeasurement* spectralMeasurement);


};

#endif // SPECTRALMEASUREMENTBARCHART_H
