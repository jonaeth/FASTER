//
// Created by jonathan on 21/03/2022.
//

#ifndef FASTER_HIERARCHICALCLUSTERER_H
#define FASTER_HIERARCHICALCLUSTERER_H

#include <iostream>
#include "HyperGraph.h"

using namespace std;

struct HierarchicalClustererConfig{
    size_t min_cluster_size;
    double max_lambda2;
};

class HierarchicalClusterer{
private:
    size_t min_cluster_size;
    double max_lambda2;
    HyperGraph hypergraph;
    vector<UndirectedGraph> graph_clusters;
    vector<HyperGraph> hypergraph_clusters;

public:
    HierarchicalClusterer(HyperGraph hypergraph, HierarchicalClustererConfig config);
    ~HierarchicalClusterer();

    vector<HyperGraph> & run_hierarchical_clustering();
    void get_clusters(UndirectedGraph &graph); //TODO void?
};
#endif //FASTER_HIERARCHICALCLUSTERER_H