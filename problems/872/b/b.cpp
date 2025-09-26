#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

long long run(int n, int k, std::vector<long long> &a) {

    if (k == 1)
        return *std::min_element(a.begin(), a.end());
    if (k >= 3)
        return *std::max_element(a.begin(), a.end());

    const int K = 25;
    std::vector<std::vector<long long>> st(K+1, std::vector<long long>(n));
    std::copy(a.begin(), a.end(), st[0].begin()); 

    auto log2_floor = [&](unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    };

    auto min_range = [&](int l, int r) {
        int i = log2_floor(r - l + 1);
        return std::min(st[i][l], st[i][r - (1 << i) + 1]);
    };

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = std::min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
        }
    }

    long long largest = LLONG_MIN;
    long long val;
    for (int i = 0; i < n - 1; i++) {
        val = std::max(
            min_range(0, i),
            min_range(i+1, n-1)
        );
        largest = std::max(val, largest);
    }

    return largest;
}


int main() {

    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << run(n, k, a);
    return 0;
}
