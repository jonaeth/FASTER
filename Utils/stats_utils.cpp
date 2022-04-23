//
// Created by jonathan on 19/04/2022.
//

<<<<<<< HEAD
#include <iostream>
#include "stats_utils.h"

double estimate_generalised_chi_squared_critical_value(VectorXd weight_vector, double significance_level){

    // mean of generalised chi-squared distribution
    double mean_gen = weight_vector.sum();

    // variance of generalised chi-squared distribution
    double var_gen = 2 * weight_vector.dot(weight_vector);

    // estimated gamma scale parameter
    double scale = var_gen / mean_gen;

    // estimated gamma shape parameter
    double shape = mean_gen / scale;

    math::gamma_distribution gamma_distr(shape, scale);
    double critical_value = quantile(complement(gamma_distr, significance_level));

    return critical_value;
=======
#include "stats_utils.h"

double compute_non_central_chi_squared_critical_value(VectorXd lambdas, size_t degrees_of_freedom, double significance_level){

    // mean of generalised chi-squared distribution
    double mean_gen = pow(degrees_of_freedom, 2) * lambdas.sum();

    // variance of generalised chi-squared distribution
    double var_gen = 2 * pow(degrees_of_freedom, 2) * lambdas.dot(lambdas);

    // estimated non-centrality chi-squared parameter
    double non_centrality = var_gen / 2 - mean_gen;       // called "lambda" in Boost library

    // estimated degrees of freedom chi-squared parameter
    double chi_squared_degrees_of_freedom = 2 * mean_gen - var_gen/2; // called "nu" in Boost library

    math::non_central_chi_squared_distribution non_central_chi_distr(chi_squared_degrees_of_freedom, non_centrality);
    double non_central_chi_squared_critical_value = quantile(complement(non_central_chi_distr, significance_level));

    return non_central_chi_squared_critical_value;
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8
}