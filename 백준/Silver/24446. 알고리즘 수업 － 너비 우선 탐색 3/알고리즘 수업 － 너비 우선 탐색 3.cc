/*
알고리즘 수업 - 너비 우선 탐색 3
 
시간 제한	메모리 제한
1 초	512 MB

문제
오늘도 서준이는 너비 우선 탐색(BFS) 수업 조교를 하고 있다. 
아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.

N개의 정점과 M개의 간선으로 구성된 무방향 그래프(undirected graph)가 주어진다. 
정점 번호는 1번부터 N번이고 모든 간선의 가중치는 1이다. 
정점 R에서 시작하여 너비 우선 탐색으로 만들어 지는 트리를 너비 우선 탐색 트리라고 하자. 
너비 우선 탐색 트리에 있는 모든 노드의 깊이(depth)를 출력하자. 
시작 정점 R의 깊이는 0이고 방문 되지 않는 노드의 깊이는 -1로 출력하자.

너비 우선 탐색 의사 코드는 다음과 같다. 

bfs(V, E, R) {  # V : 정점 집합, E : 간선 집합, R : 시작 정점
    for each v ∈ V - {R}
        visited[v] <- NO;
    visited[R] <- YES;  # 시작 정점 R을 방문 했다고 표시한다.
    enqueue(Q, R);  # 큐 맨 뒤에 시작 정점 R을 추가한다.
    while (Q ≠ ∅) {
        u <- dequeue(Q);  # 큐 맨 앞쪽의 요소를 삭제한다.
        for each v ∈ E(u)  # E(u) : 정점 u의 인접 정점 집합
            if (visited[v] = NO) then {
                visited[v] <- YES;  # 정점 v를 방문 했다고 표시한다.
                enqueue(Q, v);  # 큐 맨 뒤에 정점 v를 추가한다.
            }
    }
}
입력
첫째 줄에 정점의 수 N (5 ≤ N ≤ 100,000), 간선의 수 M (1 ≤ M ≤ 200,000), 시작 정점 R (1 ≤ R ≤ N)이 주어진다.

다음 M개 줄에 간선 정보 u v가 주어지며 정점 u와 정점 v의 가중치 1인 양방향 간선을 나타낸다. 
(1 ≤ u < v ≤ N, u ≠ v) 모든 간선의 (u, v) 쌍의 값은 서로 다르다.

출력
첫째 줄부터 N개의 줄에 정수를 한 개씩 출력한다. i번째 줄에는 정점 i의 깊이를 출력한다. 
시작 정점 R의 깊이는 0이고 방문 되지 않는 노드의 깊이는 -1로 출력하자.

예제 입력 1 
5 5 1
1 4
1 2
2 3
2 4
3 4
예제 출력 1 
0
1
2
1
-1
너비 우선 탐색 트리는 1, 2, 3, 4번 노드로 구성된다. 
1번 노드가 루트이다. 
1번 노드의 자식은 2, 4번 노드이다. 
3번 노드는 2번 또는 4번 노드의 자식이다. 
5번 노드는 1번 노드에서 방문 될 수 없다.
*/

#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &graph, vector<int> &depth, int R)
{
    queue<int> q;
    q.push(R);
    depth[R] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (depth[v] == -1)
            {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> graph(N + 1);
    vector<int> depth(N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(graph, depth, R);

    for (int i = 1; i <= N; i++)
    {
        cout << depth[i] << "\n";
    }

    return 0;
}
