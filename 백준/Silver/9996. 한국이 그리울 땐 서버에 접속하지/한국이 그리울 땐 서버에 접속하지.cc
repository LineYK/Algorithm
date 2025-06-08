#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string pattern;
    cin >> pattern;

    int star = pattern.find('*');
    string prefix = pattern.substr(0, star);
    string suffix = pattern.substr(star + 1);

    while (N--) {
        string s;
        cin >> s;

        bool ok = true;
        int P = prefix.size(), S = suffix.size();
        int L = s.size();

        if (L < P + S) {
            ok = false;
        } else {
            if (s.substr(0, P) != prefix) ok = false;
            if (ok && s.substr(L - S, S) != suffix) ok = false;
        }

        cout << (ok ? "DA\n" : "NE\n");
    }

    return 0;
}
