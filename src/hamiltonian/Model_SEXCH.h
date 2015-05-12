#ifndef MODEL_SEXCH_H
#define MODEL_SEXCH_H

#include "../mmath/libmmath.h"
using namespace libmmath;

namespace libhamiltonian{


void SEXCH_Ham(double x, MATRIX* H, MATRIX* dH, MATRIX* d2H, vector<double>& params_);
boost::python::list SEXCH_Ham(double x, boost::python::list params_);


}//namespace libhamiltonian

#endif // MODEL_SEXCH
