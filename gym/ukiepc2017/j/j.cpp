#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int x;
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        cin >> x; 
        if (x == 0) result += 2.0;
        else result += 1.0 / x;
    }

    cout << fixed << setprecision(10) << result << "\n";

}
