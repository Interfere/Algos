/*
 * Addition of two binary numbers of N bits
 * result is N+1-bits binary numbers
 */

#include <bitset>
#include <iostream>

// Invariant: For each j from [0..N] result c[0..j+1] = a[0..j] + b[0..j]
template <size_t N>
std::bitset<N+1> add(const std::bitset<N>& a, const std::bitset<N>& b) {
    std::bitset<N+1> c(0);
    // 1. Initialization: j = 0 => c == 0
    // Trivial case
    if (N == 0)
        return c;

    // 2. Induction: c[0..j] == a[0..j-1] + b[0..j-1]
    // then: c[0..j+1] = a[0..j-1] + b[0..j-1] + (a[j] + b[j] + c[j])<<j == a[0..j] + b[0..j]
    for (int j = 0; j < N; ++j) {
        c[N - j - 1] = a[N - j - 1] ^ b[N - j - 1] ^ c[N - j - 1];
        c[N - j - 2] = a[N - j - 1] & b[N - j - 1];
    }
    // 3. Finalization: by induction c[0..j+1] == a[0..j] + b[0..j]
    return c;
}

template <size_t N>
bool Check_Addition(const std::bitset<N>& A, const std::bitset<N>& B, const std::bitset<N+1>& AplusB) {
    return AplusB.to_ulong() == A.to_ulong() + B.to_ulong();
}

template <size_t N>
void reportError(const std::bitset<N>& A, const std::bitset<N>& B) {
        std::cout << "Failed " << A.to_ulong() << " + " << B.to_ulong() << " = " << A.to_ulong() + B.to_ulong() << std::endl;
}

int main() {
    if (!Check_Addition(std::bitset<16>(12), std::bitset<16>(24), std::bitset<17>(36))) {
        std::cout << "Failed 12 + 24 = 36" << std::endl;
        return 1;
    }

    std::bitset<3> a1(0);
    std::bitset<3> b1(0);
    if (!Check_Addition(a1, b1, add(a1, b1))) {
        reportError(a1, b1);
        return 1;
    }

    std::bitset<0> a2;
    std::bitset<0> b2;
    if (!Check_Addition(a2, b2, add(a2, b2))) {
        reportError(a2, b2);
        return 1;
    }

    std::bitset<3> a3(0);
    std::bitset<3> b3(1);
    if (!Check_Addition(a3, b3, add(a3, b3))) {
        reportError(a3, b3);
        return 1;
    }

    std::bitset<16> a4(5);
    std::bitset<16> b4(10);
    if (!Check_Addition(a4, b4, add(a4, b4))) {
        reportError(a4, b4);
        return 1;
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
