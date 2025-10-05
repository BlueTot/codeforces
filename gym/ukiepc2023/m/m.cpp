#include <bits/stdc++.h>
using namespace std;

int main() {

    int a, b, c;
    cin >> a >> b >> c;

    int result = 2 * a;
    if (c >= 2) {
        result += 2 * b + 3 + ((c - 2) >> 1) * 3;
    }
    cout << result << "\n";

}
