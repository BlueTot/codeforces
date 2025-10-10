#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<vector<double>> dp(k, vector<double>(n+1, 0));

    /* key insight: we must roll exactly k, so if we get all heads, we must roll again
     * and we could get tails. */

    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            // initial case: 0 and 1 heads are equally likely
            if (i == 0) {
                if (j == 0 || j == 1)
                    dp[i][j] = 0.5; 
                // 0 heads - we must get 0 heads before and a tail now.
                // if n is 1, we could have force rolled and got a tail
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j] * 0.5;
                if (n == 1)
                    dp[i][j] += 0.5 * dp[i-1][j+1];
                // normal case - we either get a tail now and keep the count
                // or have count-1 and get a head now
            } else if (j != n-1) {
                dp[i][j] = 0.5 * dp[i-1][j] + 0.5 * dp[i-1][j-1];
                // j = n-1 case: 
                // we could have force rolled and got a tail
            } else {
                dp[i][j] = 0.5 * dp[i-1][j] + 0.5 * dp[i-1][j-1] + 0.5 * dp[i-1][j+1];
            }
        }
    }

    double result = 0;
    for (int j = 0; j <= n; j++) {
        result += j * dp[k-1][j];
    }

    cout << fixed << setprecision(10) << result << "\n";

    return 0;
}

