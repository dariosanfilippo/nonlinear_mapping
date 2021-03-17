/*******************************************************************************
 *      Power mapping class.
 *      
 *      Particularly, the mapping functions can be called with a tension
 *      parameter that determines the steepness of the curves. Positive
 *      tension values result in increasing slopes and step curves with 
 *      higher resolution over the mid input range. Negative tension values
 *      result in decreasing slopes and step curves with higher resolution
 *      at the sides of the input range.
 *
 *      The tension values are limited to the following values:
 *          [-100.0; -.01] and [.01; 100.0]. A zero-tension value is
 *          essentially a linear curve.
 *
 *      The behaviour of the functions can be visualised here: 
 *          https://www.desmos.com/calculator/6hshyfcyzh.
 *
 *      Copyright (C) 2021 Dario Sanfilippo – sanfilippo.dario@gmail.com
 ******************************************************************************/

#include "Mapping.hpp"

class Power : public Mapping {
    private :
        double exponent;
    public:
        Power(double lo, double hi, double tension);
        ~Power(void);
        double map(double x);
};

Power::Power(double lo, double hi, double tension)
    : Mapping(lo, hi, tension) {
    exponent = std::pow(std::abs(t + sign(t)), sign(t));
}

Power::~Power(void) {
}

double Power::map(double x) {
    return clipout(std::pow(clipin(x), exponent) * range + y0);
}
