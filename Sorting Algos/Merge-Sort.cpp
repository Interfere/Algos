/**
 * Merge Sort
 */

#include "Common.hpp"
#include <cassert>

static void Merge(std::vector<int>& v, std::vector<int>&& left, std::vector<int>&& right) {
    assert(v.size() == left.size() + right.size());
    auto i = std::begin(v);
    auto j = std::begin(left);
    auto k = std::begin(right);

    while (i != std::end(v)) {
        if (j == std::end(left))
            *i++ = *k++;
        else if (k == std::end(right))
            *i++ = *j++;
        else
            *i++ = *j < *k ? *j++ : *k++;
    }
}

static void Merge_Sort(std::vector<int>& v) {
    if (v.size() <= 1)
        return;

    int pivot = v.size() / 2;
    std::vector<int> left(v.begin(), v.begin() + pivot);
    std::vector<int> right(v.begin() + pivot, v.end());
    Merge_Sort(left);
    Merge_Sort(right);
    Merge(v, std::move(left), std::move(right));
}

int main() {
    return TestSortingAlgo(Merge_Sort);
}
