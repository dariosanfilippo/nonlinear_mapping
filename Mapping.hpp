/*******************************************************************************
 *      Base class for linear and nonlinear mapping functions.
 *
 *      These function implement three main nonlinear behaviours to map a
 *      float input in the [0.0; 1.0] range into an arbitrary [y0; y1] output.
 *      
 *      The three behaviours are:
 *          - increasing slope;
 *          - decreasing slope;
 *          - step curve.
 *      
 *      The behaviours are implemented using three different functions:
 *      logarithmic, exponential, and power.
 *
 *      Particularly, the mapping functions can be called with a tension
 *      parameter that determines the steepness of the curves. Positive
 *      tension values result in increasing slopes and step curves with 
 *      higher resolution over the mid input range. Negative tension values
 *      result in decreasing slopes and step curves with higher resolution
 *      at the sides of the input range.
 *
 *      The tension values are limited to the following values:
 *          [-100.0, -.01] and [.01; 100.0]. A zero-tension value is
 *          essentially a linear curve.
 *
 *      The behaviour of the functions can be visualised here: 
 *          https://www.desmos.com/calculator/6hshyfcyzh.
 *
 *      Copyright (C) 2021 Dario Sanfilippo – sanfilippo.dario@gmail.com
 *
 ******************************************************************************/

#include <iostream>
#include <cmath>
#include <limits>

#pragma once

class Mapping {
    protected:
        double y0; // lower edge
        double y1; // upper edge
        double range; // y1 - y0
        double t; // tension parameter
        double clipin(double x);
        double clipout(double x);
        double clipt(double x);
        double sign(double x);
    public:
        Mapping(double lo, double hi, double tension);
        ~Mapping(void);
};

double Mapping::clipin(double x) {
    return std::max(0.0, std::min(1.0, x));
}

double Mapping::clipout(double x) {
    return std::max(y0, std::min(y1, x));
}

double Mapping::clipt(double x) {
    if (x < 0.0) {
        return std::max(-100.0, std::min(-.01, x));
    } else {
        return std::min(100.0, std::max(.01, x));
    }
}

double Mapping::sign(double x) {
    if (x < 0.0)
        return -1.0;
    if (x > 0.0)
        return 1.0;
    return 0.0;
}

Mapping::Mapping(double lo, double hi, double tension) {
    y0 = lo;
    y1 = hi;
    range = y1 - y0;
    t = clipt(tension);
}

Mapping::~Mapping(void) {
}

