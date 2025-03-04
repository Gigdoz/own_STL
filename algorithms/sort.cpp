#include "sort.hpp"

int SwapSort(std::vector<int> &vec, bool ascending) {
    if (vec.empty()) {
        return 0;
    }
    int count = 0;
    int k = 0;
    while (k < vec.size() - 1) {
        int max = vec[k];
        for (int j = k + 1; j < vec.size(); j++) {
            if (max > vec[j] && ascending) {
                vec[k] = vec[j];
                vec[j] = max;
                max = vec[k];
            } if (max < vec[j] && !ascending) {
                vec[k] = vec[j];
                vec[j] = max;
                max = vec[k];
            } else if (j == vec.size() - 1) {
                k++;
            }

            count++;
       }
    }

    return count;
}

namespace {
int partion(std::vector<int>& vec, int left, int right) {
    int pivot = vec[right];
    int p_i = left;

    for (int i = left; left < right; i++) {
        if (vec[i] <= pivot) {
            std::swap(vec[i], vec[p_i]);
            p_i++;
        }
    }

    std::swap(vec[right], vec[p_i]);
    return p_i;
}

void sort(std::vector<int>& vec, int left, int right) {
    if (vec.size() > 1) {
        int pivot = partion(vec, left, right);
        sort(vec, left, pivot-1);
        sort(vec, pivot+1, right);
    }
}
}

void Qsort(std::vector<int>& vec) {
    sort(vec, 0, vec.size());
}
