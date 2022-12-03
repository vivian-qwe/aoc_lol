#include <bits/stdc++.h>

using namespace std;

int main() {
    // turn off default cout flush
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    ifstream fin;
    fin.open("input.txt");
    int sum = 0;
    string s1, s2, s3;
    while (fin >> s1 >> s2 >> s3) {
        for (int i = 0; i < s1.length(); i++) {
            size_t found1 = s2.find(s1[i]);
            size_t found2 = s3.find(s1[i]);
            if (found1 != string::npos && found2 != string::npos) {
                if (s1[i] >= 'a') {
                    sum += s1[i] - 96;
                } else {
                    sum += s1[i] - 38;
                }
                break;
            }
        }
    }
    cout << sum;
    return 0;
}
