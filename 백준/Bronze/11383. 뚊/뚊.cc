#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<string> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    for (int i = 0; i < N; ++i) {
        string doubled;
        for (char c : A[i]) {
            doubled.push_back(c);
            doubled.push_back(c);
        }
        if (doubled != B[i]) {
            cout << "Not Eyfa\n";
            return 0;
        }
    }
    cout << "Eyfa\n";
    return 0;
}