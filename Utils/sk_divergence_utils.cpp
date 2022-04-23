//
// Created by jonathan on 18/04/2022.
//

#include "sk_divergence_utils.h"

double kl_divergence(map<string, double> p, map<string, double> q){
    double total_kl_divergence{0};
    set<string> paths_p = get_keys(p);
    set<string> paths_q = get_keys(q);
    for(auto &path_p:paths_p){
        if(has(paths_q, path_p) && p[path_p]!=0){
            total_kl_divergence+=p[path_p]* log(p[path_p]/q[path_p]);
        }
    }
    return total_kl_divergence;
}

map<string, double> compute_average_distribution(map<string, double> p, map<string, double> q) {
    map<string, double> average_distribution;
    for(auto &path:p){
        average_distribution[path.first] = 0.5 * path.second;
    }
    for(auto &path:q){
<<<<<<< HEAD
        if(average_distribution.count(path.first)){
=======
        if(!average_distribution.count(path.first)){
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8
            average_distribution[path.first] += 0.5 * path.second;
        } else{
            average_distribution[path.first] = 0.5 * path.second;
        }
    }
    return average_distribution;
}

double sk_divergence(map<string, double> &p, map<string, double> &q, map<string, double> &average_distribution) {
    if(average_distribution.empty()){
        average_distribution = compute_average_distribution(p, q);
    }
    return 0.5 * kl_divergence(p, average_distribution) + 0.5 * kl_divergence(q, average_distribution);
}

double compute_threshold_sk_divergence(size_t number_of_walks, map<string, double> &average_paths_probabilities, size_t number_of_top_paths, double significance_level) {

    vector<double> path_probabilities = get_values(average_paths_probabilities);
    sort(path_probabilities.begin(),path_probabilities.end(), greater<>());
<<<<<<< HEAD
    number_of_top_paths = min(path_probabilities.size(), number_of_top_paths);
    VectorXd top_path_probabilities = Map<VectorXd, Unaligned>(
            vector<double>(path_probabilities.begin(),path_probabilities.begin()+number_of_top_paths).data(),
            path_probabilities.size());
    //VectorXd top_path_probabilities(vector<double>(path_probabilities.begin(),path_probabilities.begin() + number_of_top_paths).data());
    VectorXd lambdas = (1/(double)number_of_walks) * (VectorXd::Ones(number_of_top_paths) - top_path_probabilities);
    double theta_sk = estimate_generalised_chi_squared_critical_value(lambdas, significance_level);
=======

    number_of_top_paths = min(path_probabilities.size(), number_of_top_paths);
    Map<VectorXd> top_path_probabilities(vector<double>(path_probabilities.begin(),
                                                        path_probabilities.begin() + number_of_top_paths).data(),
                                         number_of_top_paths);

    VectorXd lambdas = (1/number_of_walks) * (VectorXd::Ones(number_of_top_paths) - top_path_probabilities);

    double theta_sk = compute_non_central_chi_squared_critical_value(lambdas, 1, significance_level);
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8

    return theta_sk;
}

pair<double, double> compute_sk_divergence_of_top_n_paths(NodeClusterRandomWalkData node_cluster1,
                                                          NodeClusterRandomWalkData node_cluster2,
                                                          size_t number_of_top_paths,
                                                          size_t number_of_walks,
                                                          double significance_level) {

    map<string, double> node1_paths_probabilities = node_cluster1.get_top_n_path_probabilities(number_of_top_paths,
                                                                                               number_of_walks);
    map<string, double> node2_paths_probabilities = node_cluster2.get_top_n_path_probabilities(number_of_top_paths,
                                                                                               number_of_walks);
    map<string, double> average_paths_probabilities = compute_average_distribution(node1_paths_probabilities, node2_paths_probabilities);

    double sk_div = sk_divergence(node1_paths_probabilities, node2_paths_probabilities, average_paths_probabilities);

    double theta_sk = compute_threshold_sk_divergence(number_of_walks,average_paths_probabilities,number_of_top_paths,significance_level);

    return {sk_div, theta_sk};
}