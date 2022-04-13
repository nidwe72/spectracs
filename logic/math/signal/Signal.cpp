//
// Created by nidwe on 4/13/22.
//

#include "Signal.h"

void Signal::savgolCoefficients(int windowLength, int polynomialOrder, int derivation, double delta) {

    auto divResult = std::div(windowLength, 2);
    int halfLen=divResult.quot;
    int rem=divResult.rem;

    double pos;

    if(rem==0){
        pos = halfLen - 0.5;
    }else{
        pos = halfLen;
    }

/*
    nc::NdArray<int> a0 = { {1, 2}, {3, 4} };
    nc::NdArray<int> a1 = { {1, 2}, {3, 4}, {5, 6} };
    a1.reshape(2, 3);
    auto a2 = a1.astype<double>();
    std::cout << "a2" << a2 << std::endl;
*/

    if(derivation>polynomialOrder){
        auto result=nc::zeros<double>(windowLength);
    }

    auto x=nc::arange<double>(-pos, windowLength- pos);
    auto order = nc::arange<int>(polynomialOrder + 1).reshape(-1, 1);

    /*
#####https://www.colmryan.org/posts/savitsky_golay/
function design_matrix(order, window_length)
    half_length = (window_length-1) / 2

    A = Matrix{Float64}(undef, window_length, order+1)

    for i in 1:window_length, j in 1:order+1
        A[i,j] = (i-1-half_length)^(j-1)
    end
    A
end
     */

    //in scipy
    // A = x ** order



}
