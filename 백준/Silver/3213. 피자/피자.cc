#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "1/4")      cnt1++;
        else if (s == "1/2") cnt2++;
        else if (s == "3/4") cnt3++;
    }

    int pizzas = 0;

    pizzas += cnt3;
    cnt1 = max(0, cnt1 - cnt3);

    pizzas += cnt2 / 2;
    if (cnt2 % 2 == 1) {
        
        pizzas += 1;
        cnt1 = max(0, cnt1 - 2);
    }

    pizzas += (cnt1 + 3) / 4;

    cout << pizzas << "\n";
    return 0;
}