#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> citations(N);
    for (int i = 0; i < N; i++) {
        cin >> citations[i];
    }

    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;
    for (int i = 0; i < N; i++) {
        if (citations[i] >= i + 1) {
            h = i + 1; 
        } else {
            break;     
        }
    }

    cout << h << "\n";
    return 0;
}
