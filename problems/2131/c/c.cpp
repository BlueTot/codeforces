#include <bits/stdc++.h>


void run() {
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<int> absS(n);
    std::vector<int> absT(n);

    long long x;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        int r = x % k;
        int mod = std::min(r, (int) (k - r));
        absS[i] = mod;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        int r = x % k;
        int mod = std::min (r, (int) (k - r));
        absT[i] = mod;
    }

    sort(absS.begin(), absS.end());
    sort(absT.begin(), absT.end());

    if (absS == absT)
        std:: cout << "YES\n";
    else
        std::cout << "NO\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_tests;
    std::cin >> num_tests;
    for (int i = 0; i < num_tests; i++) {
        run();
    }
    return 0;
}
