//
// Created by nidwe on 4/13/22.
//

#ifndef SPECTRACS_SIGNAL_H
#define SPECTRACS_SIGNAL_H
#include <cstdlib>

/*
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
 */

#include"NumCpp.hpp"


class Signal {

public:
    static void savgolCoefficients(int windowLength, int polynomialOrder, int derivation=0, double delta=1.0);
};


#endif //SPECTRACS_SIGNAL_H
