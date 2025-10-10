#include <bits/stdc++.h>
using namespace std;


int main() {

    const double pi = 3.14159265359;

    auto toRad = [&](int deg) {
        return (double) deg * pi / 180;
    };

    const int r = 1000;

    int n, p;
    cin >> n >> p;
    vector<int> posts(n);
    for (int i = 0; i < n; i++) {
        cin >> posts[i];
    }

    
    double max_area = 0;
    vector<int> result;
    for (int k = 0; k < n; k++) {

        int i = k;

        vector<int> result;
        result.push_back(posts[i]);

        while (i < n && result.size() < p) {
            int left = i+1;
            int right = n-1;
            while (left < right) {
                int mid = (left + right) / 2;
                int diff = posts[mid] - posts[i];
                if (diff >= 360 / p) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (abs(posts[left-1] - posts[i]) < abs(posts[left] - posts[i]) && left-1 != i) {
                result.push_back(posts[left-1]);
                i = left-1;
            } else {
                result.push_back(posts[left]);
                i = left;
            }
            cout << i << "\n";
        }

        double area = 0;
        for (int j = 0; j < result.size(); j++) {
            area += 0.5 * r * r * sin(toRad(result[(j+1) % result.size()] - result[j]));
        }

        max_area = max(area, max_area);

        for (int j = 0; j < result.size(); j++) {
            cout << result[j] << ", ";
        }
        cout << "\n";
    }

    return max_area;

}
