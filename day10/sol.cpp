#include <bits/stdc++.h>

using namespace std;
vector<string> split(const string& s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

int main() {
    freopen("input2.txt", "r", stdin);
    string line;
    int n;
    int cycles = 0;
    int flag = 20;
    int X = 1;
    vector<int> signals;
    while (getline(cin, line)) {
        // start cycle
        vector<string> linev = split(line, ' ');
        if (linev.size() == 2) {
            int steps = 2;
            while (steps--) {
                cycles++;
                if (cycles == flag) {
                    signals.push_back(flag * X);
                    flag += 40;
                }
            }
            X += stoi(linev[1]);
        } else {
            cycles++;
            if (cycles == flag) {
                signals.push_back(flag * X);
                flag += 40;
            }
        }
    }
    int sum = accumulate(signals.begin(), signals.end(), 0);
    cout << sum;

    return 0;
}