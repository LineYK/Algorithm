/*
비밀번호

시간 제한	메모리 제한
1 초	64 MB

문제
웅찬이는 근성이 대단한 도둑이다. 그래서 금고를 털 때, 모든 조합을 눌러본다. 예를 들어 비밀번호가 3글자 라는 사실을 알 때, 000, 001, 002, 003, … 998, 999의 모든 조합을 눌러본다. 그러나 웅찬이는 선견지명이 있어서 비밀번호에 어떤 숫자가 들어가는지 일부 알 수 있다. 예를 들어 3글자 비밀번호에 0이 들어감을 안다면 999 와 같이 0이 들어가지 않는 수는 가능성이 없다. 그러나 000, 012, 030과 같은 수는 가능하다. 비밀번호의 길이와 선견지명으로 알게된 비밀번호의 일부 숫자가 주어질 때, 모든 가능한 비밀번호의 개수를 출력하는 프로그램을 작성하시오.

입력
첫줄에 비밀번호의 길이 n (1 ≤ n ≤ 7), 선견지명으로 알게된 비밀번호에 들어가는 수 m(0 ≤ m ≤ n) 이 주어지고, 둘째 줄에 m개의 서로 다른 숫자(0~9)가 주어진다. m이 0인 경우 둘째 줄은 주어지지 않는다.

출력
가능한 모든 비밀번호의 개수를 출력한다.

예제 입력 1
2 1
7
예제 출력 1
19
예제 입력 2
2 2
3 4
예제 출력 2
2
힌트
첫 번째 예제의 경우 가능한 비밀번호의 조합은 07, 17, 27, 37, 47, 57, 67, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 87, 97이다. 두 번째 예제의 경우 가능한 비밀번호의 조합은 34, 43이다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (m == 0) {
        cout << pow(10, n) << '\n';
        return 0;
    }

    vector<int> required;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        required.push_back(num);
    }

    vector<vector<int>> dp(n + 1, vector<int>(1 << m, 0));
    
    dp[0][0] = 1;
    
    for (int pos = 0; pos < n; pos++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            for (int digit = 0; digit <= 9; digit++) {
                int newMask = mask;
                
                for (int i = 0; i < m; i++) {
                    if (digit == required[i]) {
                        newMask |= (1 << i); 
                    }
                }
                
                dp[pos + 1][newMask] += dp[pos][mask];
            }
        }
    }
    
    int fullMask = (1 << m) - 1;
    cout << dp[n][fullMask] << '\n';
    
    return 0;
}
