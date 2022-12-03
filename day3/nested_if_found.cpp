#include <bits/stdc++.h>

using namespace std;

int main() {
    // turn off default cout flush
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    int sum = 0;
    string s1, s2, s3;
    size_t found1, found2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        getline(cin, s3);

        for (int i = 0; i < s1.length(); i++) {
            if ((found1 = s2.find(s1[i])) != string::npos) {
                if ((found2 = s3.find(s1[i])) != string::npos) {
                    if (s1[i] >= 'a') {
                        sum += s1[i] - 96;
                    } else {
                        sum += s1[i] - 38;
                    }
                    break;
                }
            }
        }
    }
    cout << sum;
    return 0;
}
