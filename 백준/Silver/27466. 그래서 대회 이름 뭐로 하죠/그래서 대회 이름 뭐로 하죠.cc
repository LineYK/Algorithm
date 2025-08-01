#include <bits/stdc++.h>
using namespace std;

bool isConsonant(char c){
    return !(c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    vector<int> nextA(N+1, N), nextC(N+1, N);
    for(int i = N-1; i >= 0; --i){
        nextA[i] = (S[i]=='A' ? i : nextA[i+1]);
        nextC[i] = (isConsonant(S[i]) ? i : nextC[i+1]);
    }

    int i = nextA[M-3];
    if(i >= N) {
        cout << "NO\n";
        return 0;
    }
    int j = nextA[i+1];
    if(j >= N) {
        cout << "NO\n";
        return 0;
    }
    int k = nextC[j+1];
    if(k >= N) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for(int t = 0; t < M-3; ++t)
        cout << S[t];
    cout << 'A'  // = S[i]
         << 'A'  // = S[j]
         << S[k]
         << "\n";
    return 0;
}