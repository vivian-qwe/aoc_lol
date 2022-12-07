#include <bits/stdc++.h>

using namespace std;
#define TOTAL 70000000
#define NEEDED 30000000
struct Node {
    string key;
    Node *parent;
    int size;
    vector<Node *> child;
};
Node *newNode(string key, int size, Node *parent) {
    Node *temp = new Node;
    temp->key = key;
    temp->size = size;
    temp->parent = parent;
    return temp;
}
vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}
vector<int> dirs;
int sum;
void LevelOrderTraversal(Node *root) {
    queue<Node *> q;
    q.push(root);
    int avail = TOTAL - root->size;
    while (!q.empty()) {
        int n = q.size();

        while (n > 0) {
            Node *p = q.front();
            q.pop();
            if (p->size <= 100000) {
                sum += p->size;
            }
            if ((p->size + avail) >= NEEDED) {
                dirs.push_back(p->size);
            }

            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
    }
}

void updatesize(Node *temp) {
    if (temp == NULL)
        return;
    for (int i = 0; i < temp->child.size(); i++) {
        updatesize(temp->child[i]);
    }
    if (temp->parent) {
        temp->parent->size += temp->size;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    Node *root;
    Node *cd;

    while (getline(cin, line)) {
        vector<string> s_s = split(line, ' ');
        if (s_s[1] == "cd" && s_s[2] != "..") {
            if (s_s[2] == "/") {
                root = newNode("/", 0, NULL);
                cd = root;
            } else {
                for (int i = 0; i < cd->child.size(); i++) {
                    if (cd->child[i]->key == s_s[2]) {
                        cd = cd->child[i];
                        break;
                    }
                }
            }
        }
        if (s_s[1] == "cd" && s_s[2] == "..") {
            cd = cd->parent;
        }
        if (isdigit(s_s[0][0])) {
            cd->size += stoi(s_s[0]);
        }
        if (s_s[0] == "dir") {
            (cd->child).push_back(newNode(s_s[1], 0, cd));
        }
    }
    updatesize(root);
    LevelOrderTraversal(root);
    sort(dirs.begin(), dirs.end());
    cout << "part1: " << sum << " part2: " << dirs[0];

    return 0;
}