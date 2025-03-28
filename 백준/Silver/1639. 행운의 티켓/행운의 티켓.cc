/*
행운의 티켓
 
시간 제한	메모리 제한
2 초	128 MB

문제
프로야구단 다숌 자이언츠에서는 야구장에 오는 손님에게 티켓을 나누어준다. 그리고 나서 그 티켓 중에 다음과 같은 규칙을 가진 티켓을 행운의 티켓이라고 하며, 그 티켓을 가진 사람들에게 상품을 나누어준다.

행운의 티켓은 정확하게 2N자리로 이루어진 티켓이다. 왼쪽 N자리의 합과 오른쪽 N자리의 합이 일치하면 그 티켓은 행운의 티켓이라고 한다.

숌은 티켓 번호를 조작하려고 한다. 어떤 문자열이 주어지면, 그 문자열의 연속된 부분 문자열중 행운의 티켓 규칙을 만족하는 최대 부분 문자열의 길이를 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 문자열 S가 주어진다. 문자열 S는 1보다 크거나 같고, 9보다 작거나 같은 수로만 이루어져 있고, 길이는 50보다 작거나 같은 자연수이다.

출력
첫째 줄에 주어진 입력의 연속된 부분 문자열 중 행운의 티켓 규칙을 만족하는 부분 문자열의 최대 길이를 출력하시오. 찾을 수 없다면 0을 출력한다.

예제 입력 1 
74233285
예제 출력 1 
4
예제 입력 2 
123231
예제 출력 2 
6
예제 입력 3 
986561517416921217551395112859219257312
예제 출력 3 
36
예제 입력 4 
1
예제 출력 4 
0
예제 입력 5 
112
예제 출력 5 
2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();
    int answer = 0;
    
    for (int len = n - (n % 2); len >= 2; len -= 2) {
        bool found = false;
        for (int i = 0; i <= n - len; i++) {
            int mid = i + len / 2;
            int sum1 = 0, sum2 = 0;
            for (int j = i; j < mid; j++) {
                sum1 += s[j] - '0';
            }
            for (int j = mid; j < i + len; j++) {
                sum2 += s[j] - '0';
            }
            if (sum1 == sum2) {
                answer = len;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    
    cout << answer;
    return 0;
}