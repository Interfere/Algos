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
        c[j + 1] = (a[j] & b[j]) | (a[j] & c[j]) | (b[j] & c[j]);
        c[j] = a[j] ^ b[j] ^ c[j];
    }
    // 3. Finalization: by induction c[0..j+1] == a[0..j] + b[0..j]
    return c;
}

template <size_t N>
bool Check_Addition(const std::bitset<N>& A, const std::bitset<N>& B, const std::bitset<N+1>& AplusB) {
    return AplusB.to_ulong() == (A.to_ulong() + B.to_ulong());
}

template <size_t N>
void reportError(const std::bitset<N>& A, const std::bitset<N>& B, const std::bitset<N+1>& C) {
        std::cout << "Failed " << A.to_ulong() << " + " << B.to_ulong() << " = " << A.to_ulong() + B.to_ulong() << " got (" << C.to_ulong() << ")" << std::endl;
}

int main() {
    if (!Check_Addition(std::bitset<16>(12), std::bitset<16>(24), std::bitset<17>(36))) {
        std::cout << "Failed 12 + 24 = 36" << std::endl;
        return 1;
    }

    std::bitset<3> a1(0);
    std::bitset<3> b1(0);
    auto c1 = add(a1, b1);
    if (!Check_Addition(a1, b1, c1)) {
        reportError(a1, b1, c1);
        return 1;
    }

    std::bitset<0> a2;
    std::bitset<0> b2;
    auto c2 = add(a2, b2);
    if (!Check_Addition(a2, b2, c2)) {
        reportError(a2, b2, c2);
        return 1;
    }

    std::bitset<3> a3(0);
    std::bitset<3> b3(1);
    auto c3 = add(a3, b3);
    if (!Check_Addition(a3, b3, c3)) {
        reportError(a3, b3, c3);
        return 1;
    }

    std::bitset<16> a4(5);
    std::bitset<16> b4(10);
    auto c4 = add(a4, b4);
    if (!Check_Addition(a4, b4, c4)) {
        reportError(a4, b4, c4);
        return 1;
    }

    std::bitset<2> a5(3);
    std::bitset<2> b5(1);
    auto c5 = add(a5, b5);
    if (!Check_Addition(a5, b5, c5)) {
        reportError(a5, b5, c5);
        return 1;
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
