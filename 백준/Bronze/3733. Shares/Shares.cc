#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, S;
    
    while ( (cin >> N >> S) ) {
        
        cout << (S / (N + 1)) << "\n";
    }

    return 0;
}