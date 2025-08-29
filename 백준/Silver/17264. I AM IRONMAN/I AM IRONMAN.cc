#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    if (!(cin >> N >> P)) return 0;
    int W, L, G;
    cin >> W >> L >> G;

    unordered_map<string, char> mp;
    mp.reserve(P * 2);
    for (int i = 0; i < P; ++i) {
        string name;
        char res;
        cin >> name >> res; 
        mp[name] = res;
    }

    long long score = 0;
    for (int i = 0; i < N; ++i) {
        string mate;
        cin >> mate;
        auto it = mp.find(mate);
        if (it != mp.end()) {
            if (it->second == 'W') {
                score += W;
            } else { // 'L'
                score -= L;
                if (score < 0) score = 0;
            }
        } else {
            // unknown -> lose
            score -= L;
            if (score < 0) score = 0;
        }

        if (score >= G) {
            cout << "I AM NOT IRONMAN!!\n";
            return 0;
        }
    }

    cout << "I AM IRONMAN!!\n";
    return 0;
}