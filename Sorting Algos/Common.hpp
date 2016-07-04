#include <vector>
#include <iostream>

static bool Check_Sorted(const std::vector<int>& v) {
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

static int TestSortingAlgo(std::function<void(std::vector<int>&)>&& Sort) {
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
    Sort(v4);
    if (!Check_Sorted(v4)) {
        std::cout << "Failed " STRFY(v4) << std::endl;
        return 1;
    }

    auto v5 = v2;
    Sort(v5);
    if (!Check_Sorted(v5)) {
        std::cout << "Failed " STRFY(v5) << std::endl;
        return 1;
    }

    auto v6 = v3;
    Sort(v6);
    if (!Check_Sorted(v6)) {
        std::cout << "Failed " STRFY(v6) << std::endl;
        return 1;
    }

    std::vector<int> v7{ 2, 1, 3 };
    Sort(v7);
    if (!Check_Sorted(v7)) {
        std::cout << "Failed " STRFY(v7) << std::endl;
        return 1;
    }

    std::vector<int> v8{ 5, 4, 3, 2, 1 };
    Sort(v8);
    if (!Check_Sorted(v8)) {
        std::cout << "Failed " STRFY(v8) << std::endl;
        return 1;
    }

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
