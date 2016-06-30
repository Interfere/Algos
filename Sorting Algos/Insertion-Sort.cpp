/**
 * Insertion Sort as it was described in [1]
 */

#include <cassert>
#include <vector>
#include <iostream>

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

bool Check_Sorted(const std::vector<int>& v) {
    if (v.size() < 2) {
        return true;
    }

    for(int i = 1; i < v.size(); ++i) {
        if (v[i] < v[i-1])
            return false;
    }
    return true;
}

#define STRFY(a) #a

int main() {
    std::vector<int> v1;
    if (!Check_Sorted(v1)) {
        std::cout << "Failed " STRFY(v1) << std::endl;
        return 1;
    }

    std::vector<int> v2;
    v2.push_back(12);
    if (!Check_Sorted(v2)) {
        std::cout << "Failed " STRFY(v2) << std::endl;
        return 1;
    }

    std::vector<int> v3{ 1, 2, 3, 4, 5 };
    if (!Check_Sorted(v3)) {
        std::cout << "Failed " STRFY(v3) << std::endl;
        return 1;
    }
    std::vector<int> v3_1{ 3, 2, 1 };
    if (Check_Sorted(v3_1)) {
        std::cout << "Failed " STRFY(v3_1) << std::endl;
        return 1;
    }

    auto v4 = v1;
    Insertion_Sort(v4);
    if (!Check_Sorted(v4)) {
        std::cout << "Failed " STRFY(v4) << std::endl;
        return 1;
    }

    auto v5 = v2;
    Insertion_Sort(v5);
    if (!Check_Sorted(v5)) {
        std::cout << "Failed " STRFY(v5) << std::endl;
        return 1;
    }

    auto v6 = v3;
    Insertion_Sort(v6);
    if (!Check_Sorted(v6)) {
        std::cout << "Failed " STRFY(v6) << std::endl;
        return 1;
    }

    std::vector<int> v7{ 2, 1, 3 };
    Insertion_Sort(v7);
    if (!Check_Sorted(v7)) {
        std::cout << "Failed " STRFY(v7) << std::endl;
        return 1;
    }

    std::vector<int> v8{ 5, 4, 3, 2, 1 };
    Insertion_Sort(v8);
    if (!Check_Sorted(v8)) {
        std::cout << "Failed " STRFY(v8) << std::endl;
        return 1;
    }

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
