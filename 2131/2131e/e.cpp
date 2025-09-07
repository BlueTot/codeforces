#include <iostream>
#include <vector>

bool run() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        } else if (i == n-1) {
            return false;
        } else {
            long long replace = a[i] ^ a[i+1];
            long long replace2 = a[i] ^ b[i+1];
            if (replace == b[i]) {
                a[i] = replace;
            } else if (replace2 == b[i]) {
                a[i] = replace2;
            } else {
                return false;
            }
        }
    }
    return true;

}

int main() {
    int num_tests;
    std::cin >> num_tests;

    for (int i = 0; i < num_tests; i++) {
        if (run())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
