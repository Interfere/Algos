/**
 * Selection Sort
 */

#include "Common.hpp"

static int Choose_Min(const std::vector<int>& v, int start, int end) {
    int min = start;
    for (;start < end;++start) {
        if (v[start] < v[min])
            min = start;
    }
    return min;
}

// Invariant: v[0..j] is sorted and {v[i] >= v[j], i > j}
static void Selection_Sort(std::vector<int>& v) {
    // Initialization: empty vector is trivially sorted
    if (v.size() == 0)
        return;

    // Induction: invariant is true, then choose the smallest elemen from v[j+1..N] where N = size(v)
    //            and insert it at j+1. so v[0..j+1] is sorted because v[j+1] >= v[j]
    //            and {v[i] > v[j+1], i > j+1}
    for (int j = 0; j < v.size(); ++j) {
        int min = Choose_Min(v, j, v.size());
        if (j != min) 
            std::swap(v[min], v[j]);
    }

    // Finalization: last j is j == size(v)
    // v[0..size(v)] is sorted, then algo is correct
}

int main() {
    return TestSortingAlgo(Selection_Sort);
}
