//
// Created by jonathan on 01/04/2022.
//

#ifndef FASTER_VECTOR_UTILS_H
#define FASTER_VECTOR_UTILS_H
#include <vector>
#include <numeric>
#include <algorithm>
#include <Eigen/Dense>


using namespace std;
using namespace Eigen;

vector<double> to_vector(VectorXd &v1);

template<typename T>
vector<T> flatten(std::vector<std::vector<T>> const &vec)
{
    int size = 0;
    for (auto &v: vec) {
        size += v.size();
    }

    std::vector<T> flattened;
    flattened.reserve(size);

    for (auto &v: vec) {
        for (auto &e: v) {
            flattened.push_back(e);
        }
    }

    return flattened;
}

<<<<<<< HEAD


=======
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8
template <typename T>
vector<size_t> sort_indexes(const vector<T> &v, bool ascending) {

    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    if(ascending) {
        stable_sort(idx.begin(), idx.end(),
                    [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });
    }else{stable_sort(idx.begin(), idx.end(),
                      [&v](size_t i1, size_t i2) { return v[i1] > v[i2]; });}

    return idx;
}

#endif //FASTER_VECTOR_UTILS_H
