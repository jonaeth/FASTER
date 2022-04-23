//
// Created by jonathan on 19/04/2022.
//

#ifndef FASTER_STATS_UTILS_H
#define FASTER_STATS_UTILS_H
#include <Eigen/Dense>
<<<<<<< HEAD
#include <boost/math/distributions/gamma.hpp>

=======
#include <boost/math/distributions/non_central_chi_squared.hpp>
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8
using namespace std;
using namespace Eigen;
using namespace boost;

<<<<<<< HEAD
double estimate_generalised_chi_squared_critical_value(VectorXd weight_vector, double significance_level);
=======
double compute_non_central_chi_squared_critical_value(VectorXd lambdas, size_t degrees_of_freedom, double significance_level);
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8

#endif //FASTER_STATS_UTILS_H
