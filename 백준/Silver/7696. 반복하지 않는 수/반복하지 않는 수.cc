#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 1'000'000;
    vector<int> ans;
    ans.reserve(MAXN);

    auto is_unique = [&](int x){
        int seen = 0;
        while(x){
            int d = x % 10;
            if (seen & (1<<d)) return false;
            seen |= (1<<d);
            x /= 10;
        }
        return true;
    };

    for(int x = 1; (int)ans.size() < MAXN; x++){
        if(is_unique(x)) ans.push_back(x);
    }

    while(true){
        int n;
        cin >> n;
        if(!cin || n == 0) break;
        cout << ans[n-1] << "\n";
    }

    return 0;
}
