/*
건공문자열
 
시간 제한	메모리 제한
1 초	1024 MB

문제
양의 정수 $N$, $K$와 영어 알파벳 소문자로 구성된 길이가 $N$인 문자열 $S$가 주어진다.

reverse(i)를 $S$의 $i, i+1, ... , i+k-1$번째 문자로 이루어진 부분 문자열을 뒤집는 연산이라고 정의하자.
$i = 1, 2, \cdots , N-K+1$ 의 순서대로 reverse(i)을 수행하였을 때 나오는 최종 결과를 건공문자열이라고 할 때, 
건공문자열을 출력하여라.

입력
첫 번째 줄에 정수 $N$과 $K$가 공백으로 구분되어 주어진다. ($1 \le K \le N \le 500\ 000$)

두 번째 줄에 영어 알파벳 소문자로만 구성되고 길이가 $N$인 문자열 $S$가 주어진다.

출력
건공문자열을 출력한다.

예제 입력 1 
5 3
cpuos
예제 출력 1 
uospc
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    string S;
    cin >> N >> K >> S;
    
    string answer;
    
    if (K == 1) {
        answer = S;
    }
    else if ((N-K) % 2 == 1) {
        answer = S.substr(K-1) + S.substr(0, K-1);
    }
    else {
        string front = S.substr(K-1);  
        string back = S.substr(0, K-1); 
        reverse(back.begin(), back.end());
        answer = front + back;
    }
    
    cout << answer << "\n";
    return 0;
}