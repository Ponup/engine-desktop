#include "Random.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <algorithm>
using std::random_shuffle;

bool Random::started = false;

int Random::nextInt(int min, int max) {
    if (started == false) {
        srand(time(0));
        started = true;
    }

    return min + (rand() % (max - min + 1));
}

int* Random::nextArray(vector<int> list, unsigned int limit) {
    int* result = new int[limit];

    srand(time(nullptr));
    random_shuffle(list.begin(), list.end());

    for (unsigned int i = 0; i < limit; i++) {
        result[i] = list[i];
    }

    return result;
}

int* Random::nextArray(int* list, int size, unsigned int limit) {
    int* result = new int[limit];

    srand(time(nullptr));
    random_shuffle(list, list + size);

    for (unsigned int i = 0; i < limit; i++) {
        result[i] = list[i];
    }

    return result;
}

vector<int> Random::nextVector(vector<int> list, unsigned int limit) {
    vector<int> result(limit);

    srand(time(nullptr));
    random_shuffle(list.begin(), list.end());

    for (unsigned int i = 0; i < limit; i++) {
        result[i] = list[i];
    }

    return result;
}

