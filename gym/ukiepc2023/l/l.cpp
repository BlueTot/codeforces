#include <bits/stdc++.h>
using namespace std;


int main() {

    int h1, d1, t1, h2, d2, t2;
    cin >> h1 >> d1 >> t1;
    cin >> h2 >> d2 >> t2;

    int time1 = (ceil((double) h2 / d1) - 1) * t1;
    int time2 = (ceil((double) h1 / d2) - 1) * t2;

    if (time1 > time2) {
        cout << "player two";
    } else if (time1 < time2) {
        cout << "player one";
    } else {
        cout << "draw";
    }

    return 0;
}
