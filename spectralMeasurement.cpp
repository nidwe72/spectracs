#include "spectralMeasurement.h"

SpectralMeasurement::SpectralMeasurement()
{

}

QMap<float, float> *SpectralMeasurement::getValues()
{
    if(!values){
        values=new QMap<float,float>();
    }
    return values;
}
