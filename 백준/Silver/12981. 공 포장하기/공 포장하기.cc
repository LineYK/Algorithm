#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R, G, B;
    if(!(cin >> R >> G >> B)) return 0;

    int total = R + G + B;
    int limit = min({R, G, B});
    int best = INT_MAX;

    for(int t = 0; t <= limit; ++t){
        int r_rem = R - t;
        int g_rem = G - t;
        int b_rem = B - t;
        int triples = t + (r_rem / 3) + (g_rem / 3) + (b_rem / 3);
        int used = triples * 3;
        int rem = total - used;
        int boxes = triples + (rem + 1) / 2; // ceil(rem/2)
        best = min(best, boxes);
    }

    cout << best << '\n';
    return 0;
}
