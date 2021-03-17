/*******************************************************************************
 *      Linear mapping class.
 *      
 *      Copyright (C) 2021 Dario Sanfilippo – sanfilippo.dario@gmail.com
 *
 ******************************************************************************/

#include "Mapping.hpp"

class Linear : public Mapping {
    public:
        Linear(double lo, double hi, double tension);
        ~Linear(void);
        double map(double x);
};

Linear::Linear(double lo, double hi, double tension = 0.0) 
    : Mapping(lo, hi, tension) {
}

Linear::~Linear(void) {
}

double Linear::map(double x) {
    return clipin(x) * range + y0;
}

