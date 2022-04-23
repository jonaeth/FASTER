//
// Created by jonathan on 21/03/2022.
//

#ifndef FASTER_COMMUNITIES_H
#define FASTER_COMMUNITIES_H

#include "HyperGraph.h"
#include "RandomWalker.h"
#include "Community.h"
#include "map_utils.h"
#include "clustering_utils.h"

class Communities{
private:
    HyperGraph hypergraph;
    RandomWalker random_walker;
    map<size_t, Community> communities;

    void check_arguments(); //TODO Shouldn't that be in RandomWalker?

public:
    Communities(HyperGraph hypergraph, RandomWalkerConfig config);
    ~Communities();
<<<<<<< HEAD

    void print();
    Community get_community(size_t &source_node, RandomWalkerConfig config);
    size_t size();
    HyperGraph &get_hypergraph();
    map<size_t, Community> get_communities();
=======
    size_t size();
    HyperGraph &get_hypergraph();
    void print();
    map<size_t, Community> get_communities();
    Community get_community(size_t &source_node, RandomWalkerConfig config);

>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8

};
#endif //FASTER_COMMUNITIES_H
