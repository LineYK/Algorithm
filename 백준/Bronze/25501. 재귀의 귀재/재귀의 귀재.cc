#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int half = n / 2; 
        bool isPal = true;
        int calls = 0;
        for (int i = 0; i < half; ++i) {
            ++calls; 
            if (s[i] != s[n-1-i]) {
                isPal = false;
                break;
            }
        }
        if (isPal) {
            cout << 1 << " " << (half + 1) << "\n";
        } else {
            cout << 0 << " " << calls << "\n";
        }
    }
    return 0;
}