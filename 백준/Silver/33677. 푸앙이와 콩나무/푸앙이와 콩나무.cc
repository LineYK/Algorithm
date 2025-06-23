/*
푸앙이와 콩나무
 
시간 제한   메모리 제한
1 초   1024 MB   

문제
잭과 콩나무를 감명 깊게 읽은 푸앙이는 동화책에 나오는 신비한 힘을 지닌 콩을 구해 하늘나라에 있는 거인의 성에 올라가려고 한다. 하지만 신비한 힘을 지닌 콩을 구하지 못한 푸앙이는 대신 평범한 콩나무에 하루에 한 번씩 물을 주어 하늘나라에 올라가려 한다. 콩나무는 다음 규칙을 따라 자란다.

물을 1만큼 주면 다음 날 콩나무의 길이가 1 증가한다.
물을 3만큼 주면 다음 날 콩나무의 길이는 3배가 된다.
물을 5만큼 주면 다음 날 콩나무의 길이는 제곱이 된다.
다른 양의 물을 준 경우에는 콩나무의 길이가 변하지 않는다.
0번째 날의 초기 콩나무 길이는 0이다. 푸앙이가 거인의 성에 도착하려면 콩나무의 길이가 정확히 N이 되어야 하며, 콩나무의 길이가 N이 된 날에 푸앙이는 거인의 성에 도착할 수 있게 된다. 푸앙이가 거인의 성에 도착하려면 적어도 며칠이 필요할지와 적어도 얼마나 물이 필요할 지 구해보자.

입력
첫 번째 줄에 거인의 성에 도착하기 위해 필요한 콩나무의 길이 N이 주어진다.

출력
첫 번째 줄에 푸앙이가 거인의 성에 도착하기 위해 필요한 최소 일수와 최소 일수만에 거인의 성에 도착하기 위해 필요한 물의 양의 최솟값을 공백으로 구분하여 출력한다.

제한
 0 \le N \le 1\,000\,000 
예제 입력 1 
4
예제 출력 1 
3 5
예제 입력 2 
48
예제 출력 2 
5 13
*/
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

struct Cost {
    int days, water;
    bool operator<(Cost const &o) const {
        if(days != o.days) return days > o.days;
        return water > o.water;
    }
    bool betterThan(const Cost &o) const {
        if(days != o.days) return days < o.days;
        return water < o.water;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const int INF = 1e9;
    vector<Cost> dist(N+1, {INF, INF});
    priority_queue<Cost, vector<Cost>> pq;
    vector<bool> vis(N+1, false);

    dist[0] = {0, 0};
    pq.push(dist[0]);

    while(!pq.empty()){
        Cost c = pq.top(); pq.pop();
        break;
    }

    fill(dist.begin(), dist.end(), Cost{INF,INF});
    fill(vis.begin(), vis.end(), false);
    priority_queue< pair<Cost,int> > pq2;
    dist[0] = {0,0};
    pq2.push({dist[0], 0});

    while(!pq2.empty()){
        auto [cst, x] = pq2.top(); pq2.pop();
        if(vis[x]) continue;
        vis[x] = true;
        if(x == N) break; 

        if(x+1 <= N){
            Cost nc = {cst.days+1, cst.water+1};
            if(nc.betterThan(dist[x+1])){
                dist[x+1] = nc;
                pq2.push({nc, x+1});
            }
        }
        if(3LL*x <= N){
            int y = 3*x;
            Cost nc = {cst.days+1, cst.water+3};
            if(nc.betterThan(dist[y])){
                dist[y] = nc;
                pq2.push({nc, y});
            }
        }
        if(1LL*x*x <= N){
            int y = x*x;
            Cost nc = {cst.days+1, cst.water+5};
            if(nc.betterThan(dist[y])){
                dist[y] = nc;
                pq2.push({nc, y});
            }
        }
    }

    cout << dist[N].days << " " << dist[N].water << "\n";
    return 0;
}
