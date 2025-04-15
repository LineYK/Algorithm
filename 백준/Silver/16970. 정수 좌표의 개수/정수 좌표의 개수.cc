/*
정수 좌표의 개수
 
시간 제한	메모리 제한
2 초	512 MB	

문제
2차원 좌표 평면 위에서 두 점을 골라 선분을 그었을 때, 지나가는 점의 개수가 K개인 선분의 수를 구해보자.

가능한 점의 좌표 (x, y)는 0 ≤ x ≤ N, 0 ≤ y ≤ M 이고, x와 y는 정수이다. 선분의 양 끝점도 선분이 지나가는 점이다.

입력
첫째 줄에 N, M, K가 주어진다.

출력
첫째 줄에 지나가는 점의 개수가 K개인 선분의 수를 출력한다.

제한
1 ≤ N, M ≤ 50
2 ≤ K ≤ 50
예제 입력 1 
1 1 2
예제 출력 1 
6
예제 입력 2 
2 2 3
예제 출력 2 
8
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<pair<int, int>> points;
    for(int x = 0; x <= N; x++){
        for(int y = 0; y <= M; y++){
            points.push_back({x, y});
        }
    }
    
    long long ans = 0;
    int sz = points.size();
    for(int i = 0; i < sz; i++){
        for(int j = i+1; j < sz; j++){
            int dx = abs(points[i].first - points[j].first);
            int dy = abs(points[i].second - points[j].second);
            if(gcd(dx, dy) == (K - 1) )
                ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
