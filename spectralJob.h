#ifndef SPECTRALJOB_H
#define SPECTRALJOB_H

#include "spectralMeasurement.h"

class SpectralJob
{
public:
    SpectralJob();
    SpectralMeasurement* getSpectralMeasurement();

private:
    SpectralMeasurement* spectralMeasurement=0;
};

#endif // SPECTRALJOB_H
