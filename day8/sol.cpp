#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> f(10000, vector<int>(10000, 0));
    freopen("input2.txt", "r", stdin);
    string line;
    int r, col;
    r = col = 0;
    while (getline(cin, line)) {
        col = 0;
        for (int i = 0; i < line.size(); i++) {
            string buffer;
            buffer.push_back(line[i]);
            f[r][col++] = stoi(buffer);
            buffer.clear();
        }
        r++;
    }
    int visible = 0;
    vector<int> scenic;
    for (int i = 1; i < r - 1; i++) {
        for (int j = 1; j < col - 1; j++) {
            bool bleft, bright, bup, bdown;
            bleft = bright = bup = bdown = true;
            int left, right, up, down;
            left = right = up = down = 0;
            for (int x = j - 1; x >= 0; x--) {
                left++;
                if (f[i][x] >= f[i][j]) {
                    bleft = false;
                    break;
                }
            }

            for (int x = j + 1; x < col; x++) {
                right++;
                if (f[i][x] >= f[i][j]) {
                    bright = false;
                    break;
                }
            }

            for (int x = i - 1; x >= 0; x--) {
                up++;
                if (f[x][j] >= f[i][j]) {
                    bup = false;
                    break;
                }
            }
            for (int x = i + 1; x < r; x++) {
                down++;
                if (f[x][j] >= f[i][j]) {
                    bdown = false;
                    break;
                }
            }
            if (bleft || bright || bdown || bup) {
                visible++;
            }
            scenic.push_back(up * down * left * right);
        }
    }

    std::sort(scenic.begin(), scenic.end());
    cout << "part1: " << visible + (col * 2 + ((r - 2) * 2)) << " part2: " << scenic[scenic.size() - 1];
    return 0;
}