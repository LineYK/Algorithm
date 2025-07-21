/*
찢겨진 조각들
 
시간 제한    메모리 제한
2 초    256 MB   

문제
빅 시티에 도착했지만 당신의 여정은 아직 끝나지 않았습니다. 지하철을 이용해 최종 목적지로 가야 합니다. 지하철 역의 정보 부스는 무인 상태이며 지하철 시스템 지도가 모두 소진되었습니다. 바닥에 지도의 조각들이 있습니다. 지도의 조각을 모아 최종 목적지로 가는 방법을 알아낼 수 있을까요?

지도의 각 조각은 단일 지하철 역을 완벽히 포함하며, 연결된 모든 다른 역을 식별합니다. 역 간의 연결은 양방향으로 이루어져 있어 양방향으로 이동이 가능합니다. 사용 가능한 모든 조각을 활용해 최종 목적지에 도달하기 위해 통과해야 할 역의 순서를 결정하거나, 여정을 완료할 만큼 충분한 정보가 없다면 경로가 존재하지 않는다고 명시해야 합니다.

입력
입력의 첫 번째 줄에는 2 ≤ N ≤ 32인 정수가 있으며, 이는 발견된 지도 조각의 수를 나타냅니다.

다음 N 줄은 각 조각에 표시된 역을 설명합니다. 각 줄은 해당 역의 이름으로 시작되며, 그 역과 직접 연결된 모든 역의 이름이 공백으로 구분된 목록으로 이어집니다(최대 N − 1개까지 있을 수 있습니다).

마지막 줄은 출발 역과 목적지 역을 식별합니다. 목적지 역은 출발 역과 반드시 다릅니다.

각 역 이름은 a–z와 A–Z만 사용한 최대 20자의 문자열입니다. 출발 역에서 목적지 역까지 역을 다시 방문하지 않는 단순한 경로가 최대 한 개 존재한다는 것이 보장됩니다.

출력
출발 역에서 목적지 역으로 이어지는 역의 순서를 출력합니다. 역 이름은 공백으로 구분합니다. 지도 조각이 충분하지 않아 출발 역에서 목적지 역으로 가는 경로를 찾을 수 없다면 “no route found”를 출력합니다.

예제 입력 1 
3
Uptown Midtown
Midtown Uptown Downtown
Downtown Midtown
Uptown Downtown
예제 출력 1 
Uptown Midtown Downtown
예제 입력 2 
6
A B
B A D
C D
E D F G
F E
G E
F A
예제 출력 2 
F E D B A
예제 입력 3 
4
FirstStop SecondStop
SecondStop FirstStop ThirdStop
FifthStop FourthStop SixthStop
SixthStop FifthStop
FirstStop FifthStop
예제 출력 3 
no route found
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<string, vector<string>> graph;
    graph.reserve(N);

    string line;
    getline(cin, line);
    for(int i = 0; i < N; i++){
        getline(cin, line);
        istringstream iss(line);
        string u;
        iss >> u;
        string v;
        while(iss >> v){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    string start, dest;
    cin >> start >> dest;

    queue<string> q;
    unordered_map<string, string> parent;
    unordered_set<string> visited;
    q.push(start);
    visited.insert(start);
    parent[start] = "";

    bool found = false;
    while(!q.empty() && !found){
        string u = q.front(); q.pop();
        for(const auto &w : graph[u]){
            if(!visited.count(w)){
                visited.insert(w);
                parent[w] = u;
                if(w == dest){
                    found = true;
                    break;
                }
                q.push(w);
            }
        }
    }

    if(!found){
        cout << "no route found\n";
    } else {
        vector<string> path;
        string cur = dest;
        while(cur != ""){
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        for(int i = 0; i < (int)path.size(); i++){
            if(i) cout << ' ';
            cout << path[i];
        }
        cout << '\n';
    }

    return 0;
}