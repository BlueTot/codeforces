#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

int main() {

    int n;
    std::cin >> n;
    std::vector<int> exercises(n);
    std::string s;

    for (int i = 0; i < n; i++) {
        std::cin >> s;
        if (s.find("rest") != std::string::npos) {
            exercises[i] = 0; // rest day
        } else if (s.find("leg") != std::string::npos) {
            exercises[i] = 1; // rest day
        } else {
            exercises[i] = 2; // arm day
        }
    }

    for (int i = 1; i <= 31; i++) {
        if (i % 7 == 1)
            std::cout << (i / 7 + 1) << " ";
        if (exercises[(i-1) % n] == 0) {
            std::cout << "\U0001F634";
        } else if (exercises[(i-1) % n] == 1) {
            std::cout << "\U0001F9B5";
        } else {
            std::cout << "\U0001F4AA";
        }
        if (i % 7 == 0)
            std::cout << "\n";
    }

    return 0;
}
