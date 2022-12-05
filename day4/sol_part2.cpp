#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int sum = 0;
    char c;
    string line;
    int n, n1, n2, n3;

    while (scanf("%d-%d,%d-%d", &n, &n1, &n2, &n3) != EOF) {
        if (((v[0] >= v[2]) && (v[1] <= v[3])) || ((v[2] >= v[0]) && (v[3] <= v[1]))) {
            sum++;
        }
        if (!((n1 < n2) || (n3 < n))) {
            sum++;
        }
    }

    // some parsing version
    //  while (getline(cin, line)) {
    //      vector<int> v;
    //      string buffer;
    //      for (auto x : line) {
    //          if (!isdigit(x)) {
    //              if (!buffer.empty()) {
    //                  v.push_back(stoi(buffer));
    //              }
    //              buffer.clear();
    //          } else {
    //              buffer.push_back(x);
    //          }
    //          // cout << x;
    //      }
    //      if (!buffer.empty()) {
    //          v.push_back(stoi(buffer));
    //      }
    //      if (!((v[1] < v[2]) || (v[3] < v[0]))) {
    //          sum++;
    //      }
    //  }

    cout << sum;

    return 0;
}