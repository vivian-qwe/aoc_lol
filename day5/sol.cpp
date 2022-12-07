#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string s1, s2, s3;
    int n1, n2, n3;
    stack<string> st1({"F", "T", "C", "L", "R", "P", "G", "Q"});
    stack<string> st2({"N", "Q", "H", "W", "R", "F", "S", "J"});
    stack<string> st3({"F", "B", "H", "W", "P", "M", "Q"});
    stack<string> st4({"V", "S", "T", "D", "F"});
    stack<string> st5({"Q", "L", "D", "W", "V", "F", "Z"});
    stack<string> st6({"Z", "C", "L", "S"});
    stack<string> st7({"Z", "B", "M", "V", "D", "F"});
    stack<string> st8({"T", "J", "B"});
    stack<string> st9({"Q", "N", "B", "G", "L", "S", "P", "H"});
    vector<stack<string>> v{st1, st2, st3, st4, st5, st6, st7, st8, st9};

    while (cin >> s1 >> n1 >> s2 >> n2 >> s3 >> n3) {
        n2--;
        n3--;
        if (n1 == 1) {
            v[n3].push(v[n2].top());
            v[n2].pop();
        } else {
            vector<string> buffer;
            for (int i = 0; i < n1; i++) {
                buffer.insert(buffer.begin(), v[n2].top());
                v[n2].pop();
            }
            for (auto x : buffer) {
                v[n3].push(x);
            }
        }
        // for (int i = 0; i < n1; i++) {
        //     v[n3].push(v[n2].top());
        //     v[n2].pop();
        // }
    }
    for (int i = 0; i < 9; i++) {
        cout << v[i].top();
    }

    return 0;
}