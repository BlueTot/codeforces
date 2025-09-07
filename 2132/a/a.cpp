#include <iostream>

void run() {

    int n, m;
    std::string a, b, c;
    std::cin >> n;
    std::cin >> a;
    std::cin >> m;
    std::cin >> b;
    std::cin >> c;

    for (int i = 0; i < m; i++) {
        if (c[i] == 'D') {
            a.push_back(b[i]);
        } else {
            a = b[i] + a; 
        }
    }

    std::cout << a << "\n";
}

int main() {
    int num_tests;
    std::cin >> num_tests; 

    for (int i = 0; i < num_tests; i++) {
        run();
    }
    return 0;
}
