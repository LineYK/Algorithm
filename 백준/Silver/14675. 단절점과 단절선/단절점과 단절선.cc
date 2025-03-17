/*
단절점과 단절선
 
시간 제한	메모리 제한	
1 초	512 MB	

문제
그래프 이론에서 단절점(cut vertex)과 단절선(bridge)은 다음과 같이 정의 된다.

단절점(cut vertex) : 해당 정점을 제거하였을 때, 그 정점이 포함된 그래프가 2개 이상으로 나뉘는 경우, 이 정점을 단절점이라 한다.
단절선(bridge) : 해당 간선을 제거하였을 때, 그 간선이 포함된 그래프가 2개 이상으로 나뉘는 경우, 이 간선을 단절선이라 한다.
이 단절점과 단절선을 우리는 트리(tree)에서 구하려고 한다. 그래프 이론에서 트리(tree)의 정의는 다음과 같다.

트리(tree) : 사이클이 존재하지 않으며, 모든 정점이 연결되어 있는 그래프
트리의 정보와 질의가 주어질 때, 질의에 대한 답을 하시오. 

입력
프로그램의 입력은 표준 입력으로 받는다. 입력의 첫 줄에는 트리의 정점 개수 N이 주어진다. (2 ≤ N ≤ 100,000) 트리의 정점은 1번부터 n번까지 존재한다. 다음 줄부터 N-1개의 줄에 걸쳐 간선의 정보 a, b가 주어진다. 이는 a정점과 b정점이 연결되어 있다는 뜻이며, 입력으로 주어지는 정보는 트리임이 보장된다. (1 ≤ a, b ≤ N)

다음 줄에는 질의의 개수 q가 주어진다. (1 ≤ q ≤ 100,000) 다음 q줄에는 질의 t k가 주어진다. (1 ≤ t ≤ 2) t가 1일 때는 k번 정점이 단절점인지에 대한 질의, t가 2일 때는 입력에서 주어지는 k번째 간선이 단절선인지에 대한 질의이다. t가 1일 때는 (1 ≤ k ≤ n)이며, t가 2일 때는 (1 ≤ k ≤ n - 1)이다. 

출력
프로그램의 출력은 표준 출력으로 한다. q줄에 대하여 해당 질의에 대한 답을 한다. 각각은 개행으로 구분하며, 질의가 맞다면 ‘yes’를, 질의가 틀리면 ‘no’를 출력한다. 

예제 입력 1 
5
1 2
2 3
3 4
4 5
4
1 1
1 2
2 1
2 2
예제 출력 1 
no
yes
yes
yes
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<vector<int>> tree(n + 1);
    vector<pair<int, int>> edges;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        edges.push_back({a, b});
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int t, k;
        cin >> t >> k;
        
        if (t == 1) {
            if (tree[k].size() >= 2) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        } else {
            cout << "yes\n";
        }
    }
    
    return 0;
}