//
// Created by jonathan on 18/04/2022.
//

#ifndef FASTER_HYPOTHESIS_TESTING_H
#define FASTER_HYPOTHESIS_TESTING_H

#include <Eigen/Dense>
<<<<<<< HEAD
#include <iostream>
#include "stats_utils.h"
#include "../RandomWalker/NodeRandomWalkData.h"
#include "clustering_utils.h"

using namespace std;
using namespace Eigen;

bool hypothesis_test_path_symmetric_nodes(vector<NodeRandomWalkData> nodes_of_type, size_t number_of_walks, size_t max_num_paths, size_t length_of_walks, double theta_p);
MatrixXd covariance_matrix_of_count_residues(size_t N, size_t V, size_t P, VectorXd &c_vector);
void append_null_counts(MatrixXd &node_path_counts, size_t N);
bool Q_test(double Q_critical, MatrixXd &c_matrix, VectorXd &c_vector, size_t V, size_t P);
=======
#include "stats_utils.h"

using namespace Eigen;

bool hypothesis_test_path_symmetric_nodes(MatrixXd &node_path_counts, size_t number_of_walks, double theta_p);
MatrixXd covariance_matrix_of_count_residues(size_t N, size_t V, size_t P, VectorXd &c_vector);
void append_null_counts(MatrixXd &node_path_counts, size_t N);
bool Q_test_if_single_path();
bool Q_test_if_multiple_paths(double Q_critical, MatrixXd &c_matrix, VectorXd &c_vector, size_t V, size_t P);
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8

#endif //FASTER_HYPOTHESIS_TESTING_H
