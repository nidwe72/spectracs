#ifndef SPECTRALMEASUREMENT_H
#define SPECTRALMEASUREMENT_H

#include<QMap>

class SpectralMeasurement
{
public:
    SpectralMeasurement();
    QMap<float,float>* getValues();
private:
    QMap<float,float>* values;
};

#endif // SPECTRALMEASUREMENT_H
