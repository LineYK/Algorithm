#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D;
    if(!(cin >> D)) return 0;
    long long y;
    while(cin >> y){
        if(y < D){
            D += y;
        } else {
            break;
        }
    }
    cout << D << "\n";
    return 0;
}