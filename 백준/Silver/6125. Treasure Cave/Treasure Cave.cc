#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int P, NS, T;
    if (!(cin >> P >> NS >> T)) return 0;
    vector<vector<int>> children(P+1);
    for (int i = 0; i < NS; ++i) {
        int N, B1, B2;
        cin >> N >> B1 >> B2;
        children[N].push_back(B1);
        children[N].push_back(B2);
    }

    vector<int> parent(P+1, -1);
    queue<int> q;
    parent[1] = 0; 
    q.push(1);

    while(!q.empty() && parent[T] == -1) {
        int u = q.front(); q.pop();
        for(int v : children[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    if (parent[T] == -1) {
    } else {
        int cur = T;
        while(cur != 0) { 
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
    }

    cout << path.size() << '\n';
    for (int x : path) cout << x << '\n';
    return 0;
}
