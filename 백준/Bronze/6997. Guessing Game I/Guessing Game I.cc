#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int a, b;
        cin >> a >> b;
        
        auto to4 = [&](int x){
            string s = to_string(x);
            return string(4 - s.size(), '0') + s;
        };
        string s = to4(a), g = to4(b);

        
        int circles = 0;
        vector<int> cnts(10,0), cntg(10,0);
        for(int i = 0; i < 4; i++){
            if(s[i] == g[i]){
                circles++;
            } else {
                
                cnts[s[i]-'0']++;
                cntg[g[i]-'0']++;
            }
        }

        
        int squares = 0;
        for(int d = 0; d < 10; d++){
            squares += min(cnts[d], cntg[d]);
        }

        
        cout << "For secret = " << s
             << " and guess = " << g
             << ", " << circles << " circles and "
             << squares << " squares will light up.\n";
    }
    return 0;
}