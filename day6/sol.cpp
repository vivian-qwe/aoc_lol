#include <bits/stdc++.h>

using namespace std;

bool distinct(string buf) {
    for (int i = 0; i < buf.size() - 1; i++) {
        for (int j = i + 1; j < buf.size(); j++) {
            if (buf[i] == buf[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    char c;
    string buffer;
    int index = 0;
    while (cin >> c) {
        // size 4 for part1
        if ((buffer.size() == 14) && distinct(buffer)) {
            break;
        }
        if (buffer.size() == 14) {
            buffer.erase(buffer.begin());
            buffer.push_back(c);
        } else {
            buffer.push_back(c);
        }
        index++;
    }
    cout << index;

    return 0;
}