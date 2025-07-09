#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, string> room = {
        {"Algorithm", "204"},
        {"DataAnalysis", "207"},
        {"ArtificialIntelligence", "302"},
        {"CyberSecurity", "B101"},
        {"Network", "303"},
        {"Startup", "501"},
        {"TestStrategy", "105"}
    };

    int N;
    cin >> N;
    vector<string> seminars(N);
    for (int i = 0; i < N; i++) {
        cin >> seminars[i];
    }

    for (int i = 0; i < N; i++) {
        cout << room[seminars[i]] << "\n";
    }

    return 0;
}