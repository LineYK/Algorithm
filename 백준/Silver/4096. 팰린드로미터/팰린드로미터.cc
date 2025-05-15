/*
팰린드로미터
 
시간 제한   메모리 제한
1 초   128 MB   

문제
승환이는 팰린드롬을 좋아한다. 지금 승환이의 자동차의 주행 거리계에 100000이 적혀있다. 승환이는 1km만 더 주행을 하면 100001이 된다! 승환이는 엄청나게 흥분했다.

주행 거리계에 적혀져 있는 수가 주어졌을 때, 몇 km를 더 주행하면 팰린드롬이 되는지 구하는 프로그램을 작성하시오. 승환이는 모든 자리가 팰린드롬이 되어야 한다. 따라서, 주행 거리계에 00121인 경우에는 팰린드롬이 아니다.

입력
입력은 여러 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 현재 승환이의 주행 거리계에 적혀있는 수가 주어진다.이 숫자는 2자리와 9자리 사이(포함)이다. 예를 들어, 주행 거리계에 적히는 숫자의 갯수는, 입력으로 주어진 수의 숫자의 갯수와 같다. 그래서, 입력이 00456이라면, 5자리 숫자이다. 마지막 줄에는 0이 적혀있다.

출력
각 테스트 케이스에 대해서 주행 거리계의 수가 팰린드롬이 되기 위해 주행해야 하는 최소 거리를 출력한다. 만약 이미 팰린드롬이라면 0을 출력한다.

예제 입력 1 
100000
100001
000121
00456
0
예제 출력 1 
1
0
979
44
*/

#include <bits/stdc++.h>
using namespace std;

bool isPal(const string &s){
    int n = s.size();
    for(int i = 0; i < n/2; i++)
        if(s[i] != s[n-1-i]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        if (s == "0") break;
        if (isPal(s)) {
            cout << 0 << "\n";
            continue;
        }

        int n = s.size();
        string p = s;
        for (int i = 0; i < n/2; i++)
            p[n-1-i] = p[i];

        if (p < s) {
            int carry = 1;
            int left_mid = (n - 1) / 2;
            for (int i = left_mid; i >= 0 && carry; i--) {
                int d = (p[i] - '0') + carry;
                if (d == 10) {
                    p[i] = '0';
                    carry = 1;
                } else {
                    p[i] = char('0' + d);
                    carry = 0;
                }
            }
            for (int i = 0; i < n/2; i++)
                p[n-1-i] = p[i];
        }

        int orig = stoi(s);
        int nxt  = stoi(p);
        cout << (nxt - orig) << "\n";
    }
    return 0;
}
