#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch = 0;      // 0이면 비리프(또는 아직 문자 없음)
    int nxt[2];       // child indices, -1이면 없음
    Node() { nxt[0] = nxt[1] = -1; ch = 0; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    if (!(cin >> k)) return 0;
    vector<Node> trie;
    trie.emplace_back();

    for (int i = 0; i < k; ++i) {
        char c; string code;
        cin >> c >> code;
        int cur = 0;
        for (char b : code) {
            int d = b - '0';
            if (trie[cur].nxt[d] == -1) {
                trie[cur].nxt[d] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].nxt[d];
        }
        trie[cur].ch = c; 
    }

    string bits;
    cin >> bits;

    string result;
    int cur = 0;
    for (char b : bits) {
        int d = b - '0';
        cur = trie[cur].nxt[d];
        if (cur == -1) { 
            cout << "ERROR\n";
            return 0;
        }
        if (trie[cur].ch != 0) {
            result.push_back(trie[cur].ch);
            cur = 0;
        }
    }

    cout << result << '\n';
    return 0;
}