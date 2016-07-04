/**
 * Insertion Sort as it was described in [1]
 */

#include "Common.hpp"

// Invariant: subarray v'[0..j] is sorted and has only elements from subarray v[0..j]
void Insertion_Sort(std::vector<int>& v) {
    // 1. Initialization: subarray v'[0..0] hs only one element, so it is sorted and has only elements from v[0..0]
    // Trivial case
    if (v.size() < 2)
        return;

    // 2. Induction: subarray v'[0..j-1] is sorted and has only elements from v[0..j-1]
    // then 1: v'[0..j] has elements from v[0..j-1] + v[j] => it has elements only from v[0..j]
    // then 2: v'[0..j] produced from ordered array v'[0..j-1] with insertion of new element at appropriate position
    // to keep elements ordered. => v'[0..j] is sorted
    for (int j = 1; j < v.size(); ++j) {
        int val = v[j];
        int i;
        for (i = j; i > 0 && v[i-1] > val; --i) {
            v[i] = v[i-1];
        }
        v[i] = val;
    }

    // 3. Finalization: array v' is sorted and hs only elements from v. Got by induction v[0..size(v)] => v'[0..size(v')]
}

int main() {
    return TestSortingAlgo(Insertion_Sort);
}
