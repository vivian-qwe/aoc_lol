#include <bits/stdc++.h>

using namespace std;

int main() {
    // turn off default cout flush
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    string line;
    int mid = 0;
    int sum = 0;
    while (getline(cin, line)) {
        mid = line.length() / 2;
        for (int i = 0; i < mid; i++) {
            size_t found = line.find(line[i], mid);
            if (found != string::npos) {
                // cout << line[found];
                if (line[found] >= 'a') {
                    sum += line[found] - 96;
                } else {
                    sum += line[found] - 38;
                }
                break;
            }
        }
    }
    cout << sum;

    return 0;
}
