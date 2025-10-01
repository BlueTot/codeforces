#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

int main() {

    std::string a, b;
    std::cin >> a >> b;

    // we make counters for each string
    std::unordered_map<char, int> c1, c2;
    for (char c : a)
        c1[c]++;
    for (char c : b)
        c2[c]++;

    std::stringstream ss;

    // we take the union of the two counters
    // taking the maximum count if a character exists in both

    for (auto pair : c1) {
        if (c2.find(pair.first) != c2.end()) {
            int times = std::max(c2[pair.first], pair.second);
            for (int i = 0; i < times; i++) {
                ss << pair.first;
            }
        } else {
            for (int i = 0; i < pair.second; i++) {
                ss << pair.first;
            }
        }
    }

    for (auto pair : c2) {
        if (c1.find(pair.first) == c1.end()) {
            for (int i = 0; i < pair.second; i++) {
                ss << pair.first;
            }
        }
    }

    std::cout << ss.str() << "\n";
    return 0;
}
