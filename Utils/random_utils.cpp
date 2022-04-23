//
// Created by jonathan on 13/04/2022.
//

#include "random_utils.h"

<<<<<<< HEAD
int uniform_random(int min, int max, mt19937 rng){
=======
int uniform_random(int min, int max){
    random_device rd;     // only used once to initialise (seed) engine
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
>>>>>>> b47f392532a1af69a0ec09940d45eef75bd3c0e8
    uniform_int_distribution<int> distr(min, max);
    return distr(rng);
}