#include <bits/stdc++.h>
using namespace std;

const double PI = 3.141592653589793;
const long double negInfinity = -numeric_limits<long double>::infinity();

int main() {

    /* reading the input */
    int n, p;
    cin >> n >> p;
    vector<double> degrees(n);

    for (int i = 0; i < n; i++)
        cin >> degrees[i];

    /* calculating deltas */
    vector<double> deltas(2*n);
    for (int i = 0; i < 2 * n; i++)
        deltas[i] = fmod(degrees[(i+1)%n] - degrees[i%n] + 360.0, 360);

    /* sine function */
    auto sine = [](long double degrees) {
        return sin((long double) degrees * PI / 180);
    };

    /* delta prefix sum */
    vector<long double> prefix(2*n+1);
    prefix[0] = 0;
    for (int i = 0; i < 2*n; i++)
        prefix[i+1] = prefix[i] + deltas[i];

    auto sum = [&](int l, int r) {
        return prefix[r+1] - prefix[l];
    };

    long double result = negInfinity;

    /* we can only start from the first block */
    for (int s = 0; s < n; s++) {

        /* dp[i][k] = maximum sum of merged intervals of sines 
        ending at index i using k points given we start at s */
        vector<vector<double>> dp(n, vector<double>(p, negInfinity));

        int L = s, R = s + n - 1;

        /* make room for p-1 blocks, first block can't take all space*/
        for (int i = L; i <= R - (p-1); i++) {
            dp[i-L][0] = sine(sum(L, i));
        }

        for (int j = 1; j < p-1; j++) {
            /* we leave room for j blocks before and p-1-j blocks after */ 
            for (int i = L + j; i <= R - (p - 1 - j); i++) {
                long double largest = negInfinity;
                /* */
                for (int k = L + (j-1); k < i; k++) {
                    largest = max(largest, sine(sum(k+1, i)) + dp[k-L][j-1]);
                }
                dp[i-L][j] = largest;
            }
        }

        long double best = negInfinity;
        /* leave room for at least p-2 blocks */
        for (int k = L + (p-2); k < R; k++) {
            best = max(best, sine(sum(k+1, R)) + dp[k-L][p-2]);
        }

        result = max(best, result);

    }

    long double answer = 0.5 * 1000 * 1000 * result;
    cout << fixed << setprecision(10) << answer << "\n";

    return 0;
}
