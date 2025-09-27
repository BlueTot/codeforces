#include <iostream>

const int M = 1000000007;

struct FibMat {
    long long a, b, c, d;
};

inline FibMat newFibMat() {
    return {1, 1, 1, 0};
}

inline FibMat matmul(const FibMat &x, const FibMat &y) {
    return {
        (x.a * y.a + x.b * y.c) % M,
        (x.a * y.b + x.b * y.d) % M,
        (x.c * y.a + x.d * y.c) % M,
        (x.c * y.b + x.d * y.d) % M
    };
}

inline FibMat expM(FibMat a, long long n) {
    FibMat res = {1, 0, 0, 1};
    while (n > 0) {
        if (n & 1)
            res = matmul(res, a);
        a = matmul(a, a);
        n >>= 1;
    }  
    return res;
}

int main() {

    long long n;
    std::cin >> n;

    FibMat m = expM(newFibMat(), n);
    std::cout << m.b;
    
    return 0;
}
