/*
Pathfinding
 
시간 제한   메모리 제한
1 초   128 MB

문제
Bessie is stranded on a deserted arctic island and wants to determine all the paths she might take to return to her pasture. She has tested her boat and knows she can travel from one island to another island in 1 unit of time if a route with proper currents connects the pair.

She has experimented to create a map of the ocean with valid single-hop routes between each pair of the N (1 <= N <= 100) islands, conveniently numbered 1..N. The routes are one-way (unidirectional), owing to the way the currents push her boat in the ocean. It's possible that a pair of islands is connected by two routes that use different currents and thus provide a bidirectional connection. The map takes care to avoid specifying that a route exists between an island and itself.

Given her starting location M (1 <= M <= N) and a representation of the map, help Bessie determine which islands are one 'hop' away, two 'hops' away, and so on. If Bessie can take multiple different paths to an island, consider only the path with the shortest distance.

By way of example, below are N=4 islands with connectivity as shown (for this example, M=1):

       start--> 1-------->2
                |         |
                |         |
                V         V
                4<--------3
Bessie can visit island 1 in time 0 (since M=1), islands 2 and 4 at time 1, and island 3 at time 2.

The input for this task is a matrix C where the element at row r, column c is named C_rc (0 <= C_rc <= 1) and, if it has the value 1, means "Currents enable Bessie to travel directly from island r to island c in one time unit". Row C_r has N elements, respectively C_r1..C_rN, each one of which is 0 or 1.

입력
Line 1: Two space-separated integers: N and M
Lines 2..N+1: Line i+1 contains N space-separated integers: C_r
 

출력
Lines 1..???: Line i+1 contains the list of islands (in ascending numerical order) that Bessie can visit at time i.  Do not include any lines of output after all reachable islands have been listed.
 

예제 입력 1 
4 1
0 1 0 1
0 0 1 0
0 0 0 1
0 0 0 0
예제 출력 1 
1
2 4
3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N+1);
    
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            int x;
            cin >> x;
            if (x == 1) {
                adj[r].push_back(c);
            }
        }
    }

    const int INF = 1e9;
    vector<int> dist(N+1, INF);
    queue<int> q;
    dist[M] = 0;
    q.push(M);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int maxd = 0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] < INF) {
            maxd = max(maxd, dist[i]);
        }
    }

    for (int d = 0; d <= maxd; ++d) {
        vector<int> level;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] == d) {
                level.push_back(i);
            }
        }
        if (level.empty()) break;
        sort(level.begin(), level.end());
        for (int v : level) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}