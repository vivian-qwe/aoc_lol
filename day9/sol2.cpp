#include <bits/stdc++.h>

using namespace std;
#define NMAX 800
#define TAILSIZE 10

vector<vector<int>> arr(NMAX, vector<int>(NMAX, 0));

struct point {
    int x, y;
};

point tails[TAILSIZE];

bool is_outside(point t, point h) {
    int xdif = abs(t.x - h.x);
    int ydif = abs(t.y - h.y);
    return (xdif > 1 || ydif > 1);
}

void update_arr() {
    arr[tails[TAILSIZE - 1].x][tails[TAILSIZE - 1].y]++;
}
int count2 = 0;
void move_head(char dir, int steps) {
    while (steps-- > 0) {
        if (dir == 'U') {
            tails[0].x--;
        }
        if (dir == 'D') {
            tails[0].x++;
        }
        if (dir == 'L') {
            tails[0].y--;
        }
        if (dir == 'R') {
            tails[0].y++;
        }
        for (int i = 1; i < TAILSIZE; i++) {
            if (is_outside(tails[i], tails[i - 1])) {
                // cringe ifelse :()
                //  if same row
                if (tails[i - 1].x == tails[i].x) {
                    // if head is left
                    if (tails[i - 1].y < tails[i].y) {
                        tails[i].y--;
                    } else {
                        tails[i].y++;
                    }
                }
                // if same col
                else if (tails[i - 1].y == tails[i].y) {
                    // if head is up
                    if (tails[i - 1].x < tails[i].x) {
                        tails[i].x--;
                    } else {
                        tails[i].x++;
                    }
                } else {
                    // if diag upward left or right
                    if (tails[i - 1].x == tails[i].x - 2) {
                        // if left
                        if (tails[i - 1].y < tails[i].y) {
                            tails[i].x--;
                            tails[i].y--;
                        } else {
                            tails[i].x--;
                            tails[i].y++;
                        }
                    }
                    // diag down
                    if (tails[i - 1].x == tails[i].x + 2) {
                        if (tails[i - 1].y < tails[i].y) {
                            tails[i].x++;
                            tails[i].y--;
                        } else {
                            tails[i].x++;
                            tails[i].y++;
                        }
                    }
                    // left
                    if (tails[i - 1].y == tails[i].y - 2) {
                        if (tails[i - 1].x < tails[i].x) {
                            tails[i].x--;
                            tails[i].y--;
                        } else {
                            tails[i].x++;
                            tails[i].y--;
                        }
                        // right
                    } else if (tails[i - 1].y == tails[i].y + 2) {
                        if (tails[i - 1].x < tails[i].x) {
                            tails[i].x--;
                            tails[i].y++;
                        } else {
                            tails[i].x++;
                            tails[i].y++;
                        }
                    }
                }
            }
        }
        update_arr();
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    char s;
    int n;

    for (int i = 0; i < TAILSIZE; i++) {
        tails[i].x = NMAX / 2;
        tails[i].y = NMAX / 2;
    }
    update_arr();

    while (cin >> s >> n) {
        move_head(s, n);
    }
    // 2nd cringe
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (auto j : arr[i]) {
            if (j > 0) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}