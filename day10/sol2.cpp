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

vector<vector<char>> CRT(6, vector<char>(40, '.'));

// not vry good missing some pixels
int main() {
    freopen("input.txt", "r", stdin);
    string line;
    int cycles = 0;
    int flag = 40;
    int X = 1;
    int row = 0;
    while (getline(cin, line)) {
        int middle_sprite_pos = (X == 1) ? 2 : X;
        // start cycle
        vector<string> linev = split(line, ' ');
        if (linev.size() == 2) {
            int steps = 2;
            while (steps--) {
                cycles++;
                if (cycles > flag) {
                    row++;
                    flag += 40;
                }
                int pos = (cycles % 40 == 0) ? 39 : (cycles % 40) - 1;
                if (pos == middle_sprite_pos - 1 || pos == middle_sprite_pos + 1 || pos == middle_sprite_pos) {
                    CRT[row][pos] = '#';
                }
            }
            X += stoi(linev[1]);
        } else {
            cycles++;
            if (cycles > flag) {
                row++;
                flag += 40;
            }
            int pos = (cycles % 40 == 0) ? 39 : (cycles % 40) - 1;

            if (pos == middle_sprite_pos - 1 || pos == middle_sprite_pos + 1 || pos == middle_sprite_pos) {
                CRT[row][pos] = '#';
            }
        }
    }

    for (auto row : CRT) {
        for (auto i : row) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}