#include <gtest/gtest.h>
#include <vector>
#include "sort.hpp"

TEST(SwapSort, Ascending) {
    std::vector<int> v = {4, 2, -1, 5, 0, 1, 5};
    std::vector<int> ex_v = {-1, 0, 1, 2, 4, 5, 5};
    SwapSort(v);
    for (int i = 0; i < v.size(); i++) {
        ASSERT_EQ(v.at(i), ex_v.at(i));
    }
}

TEST(SwapSort, Descending) {
    std::vector<int> v = {4, 2, -1, 5, 0, 1, 5};
    std::vector<int> ex_v = {5, 5, 4, 2, 1, 0, -1};
    SwapSort(v, false);
    for (int i = 0; i < v.size(); i++) {
        ASSERT_EQ(v.at(i), ex_v.at(i));
    }
}

TEST(Sort, Qsort) {
    std::vector<int> v = {4, 2, -1, 5, 0, 1, 5};
    std::vector<int> ex_v = {-1, 0, 1, 2, 4, 5, 5};
    Qsort(v);
    for (int i = 0; i < v.size(); i++) {
        ASSERT_EQ(v.at(i), ex_v.at(i));
    }
}
