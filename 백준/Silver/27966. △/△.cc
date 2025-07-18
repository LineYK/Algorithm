#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    cout << (N-1)*(N-1) << "\n";

    for(long long v = 2; v <= N; v++){
        cout << 1 << " " << v << "\n";
    }
    return 0;
}