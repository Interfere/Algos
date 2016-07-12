/**
 * Inplace Merge Sort
 */

#include "Common.hpp"
#include <cassert>

static void Merge(std::vector<int>& v, size_t lidx, size_t lend, size_t ridx, size_t rend, size_t outidx) {
    while (lidx < lend && ridx < rend)
        std::swap(v[outidx++], v[lidx] < v[ridx] ? v[lidx++] : v[ridx++]);
    while (lidx < lend)
        std::swap(v[outidx++], v[lidx++]);
    while (ridx < rend)
        std::swap(v[outidx++], v[ridx++]);
}

static void Internal_Sort(std::vector<int>& v, size_t start, size_t end, size_t outidx) {
    assert(end > start);
    if (end - start == 1) {
        std::swap(v[start], v[outidx]);
        return;
    }

    size_t pivot = (end - start) / 2;
    Internal_Sort(v, start, start + pivot, end - pivot);
    Internal_Sort(v, start, end - pivot, outidx + pivot);
    Merge(v, end - pivot, end, outidx + pivot, outidx - start + end, outidx);
}

static void Inplace_Merge_Sort(std::vector<int>& v) {
    if (v.size() <= 1)
        return;

    if (v.size() == 2) {
        if (v[0] > v[1])
            std::swap(v[0], v[1]);
        return;
    }

    size_t start = 0;
    size_t end = v.size();
    size_t sorted_edge = end;
    size_t pivot = (end - start) / 2;

    Internal_Sort(v, start, start + pivot, end - pivot);

    while (pivot > 2) {
        sorted_edge = sorted_edge - pivot;
        pivot = pivot / 2;
        Internal_Sort(v, sorted_edge - pivot, sorted_edge, start);
        Merge(v, start, start + pivot, sorted_edge, end, sorted_edge - pivot);
    }

    //: Insertion Sort
    while (sorted_edge-- > 0) {
        int tmp = v[sorted_edge];
        size_t i = sorted_edge + 1;
        for (; i < end && v[i] < tmp;++i)
            v[i - 1] = v[i];
        v[i] = tmp;
    }
}

int main() {
    return TestSortingAlgo(Inplace_Merge_Sort);
}
