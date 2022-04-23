cmake_minimum_required(VERSION 3.16)
project(FASTER)

set(CMAKE_CXX_STANDARD 20)
<<<<<<< HEAD
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

include_directories(SYSTEM /home/dominic/C++/boost_1_78_0 ./Communities ./Graphs ./RandomWalker ./Utils /home/dominic/C++/eigen-3.4.0)
=======

include_directories(SYSTEM /home/jonathan/Applications/boost_1_66_0 ./Communities ./Graphs ./RandomWalker ./Utils /home/jonathan/Applications/eigen-3.4.0)
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8

add_executable(FASTER main.cpp
        Graphs/UndirectedGraph.cpp Graphs/UndirectedGraph.h
        Graphs/HyperGraph.cpp Graphs/HyperGraph.h
        Graphs/HierarchicalClusterer.cpp Graphs/HierarchicalClusterer.h
<<<<<<< HEAD
        RandomWalker/NodeClusterRandomWalkData.cpp
        RandomWalker/NodeClusterRandomWalkData.h
        RandomWalker/NodeRandomWalkData.cpp
        RandomWalker/NodeRandomWalkData.h
        RandomWalker/RandomWalker.cpp
        RandomWalker/RandomWalker.h
        Utils/vector_utils.cpp Utils/vector_utils.h
        Utils/clustering_utils.cpp Utils/clustering_utils.h
        Utils/map_utils.cpp Utils/map_utils.h Utils/random_utils.h
        Utils/random_utils.cpp Utils/set_utils.h Utils/hypothesis_testing.cpp
        Utils/hypothesis_testing.h Utils/sk_divergence_utils.cpp
        Utils/sk_divergence_utils.h Utils/stats_utils.cpp Utils/stats_utils.h
        Communities/Community.cpp Communities/Community.h
        Communities/Communities.cpp Communities/Communities.h
        Communities/CommunityPrinter.cpp Communities/CommunityPrinter.h)
=======
        Utils/map_utils.cpp Utils/map_utils.h
        RandomWalker/RandomWalker.cpp RandomWalker/RandomWalker.h
        RandomWalker/NodeRandomWalkData.cpp RandomWalker/NodeRandomWalkData.h
        RandomWalker/NodeClusterRandomWalkData.cpp RandomWalker/NodeClusterRandomWalkData.h
        Communities/Community.cpp Communities/Community.h
        Communities/Communities.cpp Communities/Communities.h
        Communities/CommunityPrinter.cpp Communities/CommunityPrinter.h Utils/vector_utils.cpp Utils/vector_utils.h Utils/random_utils.cpp Utils/random_utils.h Utils/set_utils.cpp Utils/set_utils.h Utils/clustering_utils.cpp Utils/clustering_utils.h Utils/hypothesis_testing.cpp Utils/hypothesis_testing.h Utils/sk_divergence_utils.cpp Utils/sk_divergence_utils.h Utils/stats_utils.cpp Utils/stats_utils.h)
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8

