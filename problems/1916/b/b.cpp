#include <iostream>
#include <algorithm>

long long lcm(long long a, long long b) {
    return a / std::__gcd(a, b) * b;
}

long long run() {
    long long a, b;
    std::cin >> a >> b;

    if (b % a == 0) {
        return b * b / a;
    } else {
        return lcm(a, b);
    }
}

int main() {
    int num_tests;
    std::cin >> num_tests;

    for (int i = 0; i < num_tests; i++) {
        std::cout << run() << "\n";
    }
}
