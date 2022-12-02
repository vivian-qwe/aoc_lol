#include <bits/stdc++.h>

using namespace std;
// R 1 P 2 S 3
// W 6 D 3 L 0
const int score_table[3][3] = {
    3, 1, 2,
    4, 5, 6,
    8, 9, 7

};
int main() {
    freopen("input.txt", "r", stdin);
    string line;
    int score = 0;
    int self;
    int op;
    while (getline(cin, line)) {
        self = line[2] - 'X';
        op = line[0] - 'A';
        score += score_table[self][op];
    }
    cout << score;

    return 0;
}