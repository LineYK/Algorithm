#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    if (!(cin >> r >> c)) return 0;
    vector<string> words(r);
    for (int i = 0; i < r; ++i) cin >> words[i];

    bool leftShouldBeSmaller = true; // for the 1st,3rd,5th ... odd-b rows
    for (int i = 0; i < r; ++i) {
        string &w = words[i];
        int m = (int)w.size();
        int b = c - m;
        int l = 0, rr = 0;
        if (b % 2 == 0) {
            l = b / 2;
            rr = b / 2;
        } else {
            int half = b / 2; // floor
            if (leftShouldBeSmaller) {
                l = half;
                rr = b - l; // half+1
            } else {
                l = b - half; // half+1
                rr = half;
            }
            leftShouldBeSmaller = !leftShouldBeSmaller;
        }
        cout << string(l, '.') << w << string(rr, '.') << '\n';
    }
    return 0;
}