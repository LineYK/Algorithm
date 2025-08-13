#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long A, B;
    if (!(cin >> N >> A >> B)) return 0;

    long long praise = 1; // 칭찬 양파 길이
    long long blame  = 1; // 비난 양파 길이

    for (int day = 0; day < N; ++day) {
        // 1) 성장
        praise += A;
        blame  += B;

        // 2) 필요하면 역할 교체
        if (blame > praise) swap(praise, blame);

        // 3) 같으면 비난 양파의 길이 1 감소
        if (praise == blame) --blame;
    }

    cout << praise << " " << blame << '\n';
    return 0;
}