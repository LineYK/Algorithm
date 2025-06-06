/*
문제 재탕
 
시간 제한	메모리 제한	
2 초	1024 MB	

문제
제5회 천하제일 코딩대회 본선 문제 출제 마감이 1주일 남았지만, 아직 문제를 절반도 만들지 못했다. 발등에 불이 떨어진 정휘는 예선 문제를 재탕하기로 했다.

구체적으로, ‘드높은 남산 위에 우뚝 선’ 문제와 ‘세워라 반석 위에’ 라는 문제를 합쳐서 새로운 문제를 만들기로 했다.

길이가 N인 수열 A_1, \cdots, A_N가 산이라는 것은, 수열이 어떤 지점 이전까지는 증가하다가, 이 지점 이후부터는 감소한다는 뜻이다.

다시 말해, 인덱스 i가 존재해, 1 < j \le i인 j에 대해 A_{j-1} < A_j이고 i < j \le N인 j에 대해 A_{j-1} > A_j라는 뜻이다.

길이가 1인 수열은 항상 산이라는 점에 주의하자.

등산을 좋아하는 정휘는 수열 A의 연속한 부분 수열들 중 가장 긴 산의 길이를 구하고 싶어한다.

연속한 부분 수열이란, 1 \le i \le j \le N을 만족하는 두 인덱스 i, j를 선택해서 A_i, A_{i+1}, A_{i+2}, \cdots , A_j 와 같이 만든 수열을 의미한다.

정휘가 마음껏 등산을 할 수 있도록 가장 긴 산의 길이를 구하는 프로그램을 작성하자.

입력
첫째 줄에 수열의 길이 N이 주어진다.

둘째 줄에 N개의 정수 A_1, A_2, \cdots , A_N이 공백으로 구분되어 주어진다.

출력
수열 A의 연속한 부분 수열 중 가장 긴 산의 길이를 출력한다.

제한
 1 \leq N \leq 5\,000 
 1 \leq A_i \leq 5\,000 
예제 입력 1 
5
1 2 3 2 1
예제 출력 1 
5
1 2 3 2 1

예제 입력 2 
6
1 2 1 3 4 1
예제 출력 2 
4
1 2 1 3 4 1

예제 입력 3 
5
1 1 1 1 1
예제 출력 3 
1
1 1 1 1 1

예제 입력 4 
5
3 2 1 2 3
예제 출력 4 
3
3 2 1 2 3 / 3 2 1 2 3

노트
대회가 1달 연기되어서 정휘는 기뻐했다고 한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<int> L(N,1), R(N,1);
    for(int i = 1; i < N; i++){
        if(A[i-1] < A[i]) 
            L[i] = L[i-1] + 1;
    }
    for(int i = N-2; i >= 0; i--){
        if(A[i] > A[i+1])
            R[i] = R[i+1] + 1;
    }

    int ans = 1;
    for(int i = 0; i < N; i++){
        ans = max(ans, L[i] + R[i] - 1);
    }

    cout << ans << "\n";
    return 0;
}
