#include <iostream>
#include <algorithm>
#include <cmath>

/* extended euclidean algorithm */
int eea(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = eea(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

bool run(int a, int b, int c) {

    int xg, yg, x, y;
    double k1, k2;
    int g = eea(a, b, xg, yg);

    if (c % g != 0) return false; // gcd must divide c.

    x = xg * c / g; // -4
    y = yg * c / g; // 3

    k1 = -x * ((double) g / b); // k > k1.
    k2 = y * ((double) g / a); // k < k2.

    return std::ceil(k1) <= std::floor(k2); // the range is valid.
}

int main() {

    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << (run(a, b, c) ? "Yes" : "No") << "\n";

    return 0;
}
