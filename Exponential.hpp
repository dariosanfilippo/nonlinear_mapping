/*******************************************************************************
 *      Exponential mapping class.
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

#include "Mapping.hpp"

class Exponential : public Mapping {
    private:
        double exptminusone;
    public:
        Exponential(double lo, double hi, double tension);
        ~Exponential(void);
        double map(double x);
};

Exponential::Exponential(double lo, double hi, double tension) 
    : Mapping(lo, hi, tension) {
    exptminusone = std::exp(t) - 1.0;
}

Exponential::~Exponential(void) {
}

double Exponential::map(double x) {
    return clipout(((std::exp(t * clipin(x)) - 1.0) / exptminusone) 
        * range + y0);
}
