#ifndef SPECTRALMEASUREMENT_H
#define SPECTRALMEASUREMENT_H

#include <QObject>
#include<QMap>

class SpectralMeasurement: public QObject
{
    Q_OBJECT

public:
    explicit SpectralMeasurement(QObject *parent = nullptr);
    QMap<float,float>* getValues();
private:
    QMap<float,float>* values=0;
};

#endif // SPECTRALMEASUREMENT_H
