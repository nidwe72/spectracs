#include "spectralMeasurement.h"

SpectralMeasurement::SpectralMeasurement(QObject *parent) : QObject(parent)
{

}

QMap<float, float> *SpectralMeasurement::getValues()
{
    if(!values){
        values=new QMap<float,float>();
    }
    return values;
}
