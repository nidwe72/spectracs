#include "spectralJob.h"

SpectralJob::SpectralJob()
{

}

SpectralMeasurement *SpectralJob::getSpectralMeasurement()
{
    if(!spectralMeasurement){
        spectralMeasurement=new SpectralMeasurement();
    }
    return spectralMeasurement;

}
