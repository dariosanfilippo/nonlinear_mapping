/*******************************************************************************
 *      Test program for nonlinear mapping functions.
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

#include "Linear.hpp"
#include "Logarithmic.hpp"
#include "Exponential.hpp"
#include "Power.hpp"
#include "StepLog.hpp"
#include "StepExp.hpp"
#include "StepPow.hpp"

int main(void) {
    double low = 0.0;
    double high = 1.0;
    double tension = -40.0;
    double steps = 10;
    double incr = 1.0 / (steps - 1.0);
    int i = 0;
    Linear linear(low, high, tension);
    Logarithmic logarithmic(low, high, tension);
    Exponential exponential(low, high, tension);
    Power power(low, high, tension);
    StepLog steplog(low, high, tension);
    StepExp stepexp(low, high, tension);
    StepPow steppow(low, high, tension);
    std::cout.precision(32);
    for (double x = 0.0; x < 1.0 + incr; x += incr) {
        i++;
        std::cout << linear.map(x) << "\t" << "linear" << std::endl 
        << logarithmic.map(x) << "\t" << "logarithmic" << std::endl 
        << exponential.map(x) << "\t" << "exponential" << std::endl 
        << power.map(x) << "\t" << "power" << std::endl 
        << steplog.map(x) << "\t" << "steplog" << std::endl 
        << stepexp.map(x) << "\t" << "stepexp" << std:: endl 
        << steppow.map(x) << "\t" << "steppow" << std:: endl 
        << x << "\t" << "input" << std::endl 
        << i << "\t" << "step #" << std::endl << std::endl;
    }
    return 0;
}
