#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int toMin(int hhmm){
    int h = hhmm / 100;
    int m = hhmm % 100;
    return h*60 + m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int,int>> segs;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        int s = toMin(a) - 10;
        int e = toMin(b) + 10;
        segs.emplace_back(s, e);
    }

    sort(segs.begin(), segs.end());
    vector<pair<int,int>> merged;
    for(auto &p : segs){
        if(merged.empty() || p.first > merged.back().second){
            merged.push_back(p);
        } else {
            // 겹치거나 인접
            merged.back().second = max(merged.back().second, p.second);
        }
    }

    const int WORK_S = 10*60;   // 600
    const int WORK_E = 22*60;   // 1320
    int best = 0;

  
    if(merged.empty()){
        best = WORK_E - WORK_S;
    } else {
        best = max(best, max(0, merged[0].first - WORK_S));
        for(int i = 1; i < (int)merged.size(); i++){
            int gap = merged[i].first - merged[i-1].second;
            if(gap > best) best = gap;
        }
        best = max(best, max(0, WORK_E - merged.back().second));
    }

    cout << best << "\n";
    return 0;
}