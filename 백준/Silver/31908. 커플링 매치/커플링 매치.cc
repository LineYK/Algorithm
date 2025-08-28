#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    unordered_map<string, vector<string>> mp;
    mp.reserve(N*2);
    vector<string> order; // 특징의 최초 등장 순서 저장
    for (int i = 0; i < N; ++i) {
        string name, feat;
        cin >> name >> feat;
        if (feat == "-") continue;
        auto it = mp.find(feat);
        if (it == mp.end()) {
            mp[feat] = vector<string>{name};
            order.push_back(feat);
        } else {
            it->second.push_back(name);
        }
    }

    vector<pair<string,string>> ans;
    for (auto &feat : order) {
        auto &v = mp[feat];
        if ((int)v.size() == 2) {
            ans.emplace_back(v[0], v[1]);
        }
    }

    cout << ans.size() << '\n';
    for (auto &p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}