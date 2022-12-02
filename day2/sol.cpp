#include <bits/stdc++.h>
// part 2 sol

using namespace std;

int my_mod(int n, int m) {
    return ((n % m) + m) % m;
}

int compute_score(int op, int xyz) {
    int you = my_mod(op + xyz, 3);                // your move is op's rotated by xyz
    int res = my_mod(you - op, 3);                // 0 draw, 1 win, 2 lose
    vector<int> a = {you + 3, you + 6, you + 0};  // draw, win, lose
    return a[res] + 1;                            // +1 bcz in problem descript RPS = 1,2,3 and here we use 0,1,2
}

int main() {
    // turn off default cout flush
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    freopen("input.txt", "r", stdin);
    int score = 0;
    int op;
    vector<int> xyz{2, 0, 1};  // lose, draw, win
    int index;
    string line;
    while (getline(cin, line)) {
        op = line[0] - 65;     // 0 R, 1 P, 2 S
        index = line[2] - 88;  // x = index 0, y = index 1, z = index 2
        score += compute_score(op, xyz[index]);
    }
    cout << score;

    return 0;
}
