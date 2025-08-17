#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    if (!(cin >> K)) return 0;

    const int LEN = 100;
    string base(LEN, '2'); 
    string machine(LEN, '?');

    for (int i = 0; i < LEN; ++i) {
        string q = base;
        q[i] = '0';
        cout << "? " << q << "\n" << flush;

        int resp;
        if (!(cin >> resp)) return 0; 

        int delta = resp - K;
        if (delta == 1) machine[i] = '2';
        else if (delta == 0) machine[i] = '0';
        else if (delta == -1) machine[i] = '5';
        else {
            return 0;
        }
    }

    cout << "! " << machine << "\n" << flush;
    return 0;
}
