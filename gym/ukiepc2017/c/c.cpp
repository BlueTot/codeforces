#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int red_count = 0;
    vector<int> non_reds;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s; 
        if (s == "red") {
            red_count++;
        } else if (s == "yellow") {
            non_reds.push_back(2);
        } else if (s == "green") {
            non_reds.push_back(3);
        } else if (s == "brown") {
            non_reds.push_back(4);
        } else if (s == "blue") {
            non_reds.push_back(5);
        } else if (s == "pink") {
            non_reds.push_back(6);
        } else if (s == "black") {
            non_reds.push_back(7);
        }
    }

    int result = 0;
    if (non_reds.size() == 0) {
        result = 1;
    } else {
        result += (*max_element(non_reds.begin(), non_reds.end()) + 1) * red_count;
        for (int score : non_reds)
            result += score;
    }
    cout << result << "\n";


}
