#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    long long M;
    if(!(cin >> N >> M >> K)) return 0;
    vector<pair<long long,int>> beers; // (ci, vi)
    beers.reserve(K);
    for(int i=0;i<K;i++){
        int vi; long long ci;
        cin >> vi >> ci;
        beers.emplace_back(ci, vi);
    }

    sort(beers.begin(), beers.end()); // sort by ci asc

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap of chosen vi
    ll sum = 0;

    for(auto &p : beers){
        long long ci = p.first;
        int vi = p.second;
        pq.push(vi);
        sum += vi;
        if((int)pq.size() > N){
            sum -= pq.top();
            pq.pop();
        }
        if((int)pq.size() == N && sum >= M){
            cout << ci << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
