/*
라면 공식
 
시간 제한	메모리 제한	
1 초 (추가 시간 없음)	1024 MB (추가 메모리 없음)

문제
”꼬불꼬불 꼬불꼬불 맛좋은 라면 라면이 있기에 세상 살맛나 하루에 열개라도 먹을 수 있어 후루룩 짭짭 후루룩 짭짭 맛좋은 라면”

예찬이는 라면을 매우 좋아한다. 선린 최고의 라면 애호가답게, 예찬이는 한 끼에도 라면 여러 개를 흡입하고는 한다.

평소 라면을 가장 맛있게 끓일 수 있는 물의 양이 궁금했던 예찬이는 오랜 실험 끝에 마침내 아래와 같은 라면 공식을 만드는 데 성공했다.

W_i=A_i(X_i - 1)+B_i

단, W_i는 필요한 물의 양, A_i는 라면 계수, B_i는 기본 물의 양, X_i는 끓일 라면 수를 나타낸다.

예찬이가 라면을 끓이는 횟수 N과 i (1 \leq i \leq N)번째로 라면을 끓일 때의 라면 계수 A_i, 기본 물의 양 B_i, 끓일 라면 수 X_i가 주어질 때, 예찬이를 위해 라면 공식에 따라 필요한 물의 양 W_i을 계산해 보자.

입력
첫째 줄에 예찬이가 라면을 끓이는 횟수 N이 주어진다.

둘째 줄부터 N+1번째 줄까지는 i + 1 (1 \leq i \leq N)번째 줄에 A_i, B_i, X_i가 공백으로 구분되어 주어진다.

입력으로 주어지는 모든 수는 정수이다.

출력
N개의 줄을 출력하라. 이 중 i (1 \leq i \leq N)번째 줄에 i번째로 라면을 끓일 때 라면 공식에 따라 필요한 물의 양 W_i를 출력하라.

제한
1 \leq N \leq 100
100 \leq A_i, B_i \leq 1\,000 (1 \le i \le N)
1 \leq X_i \leq 100 (1 \le i \le N)
예제 입력 1 
2
500 550 4
450 500 7
예제 출력 1 
2050
3200
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int A, B, X;
        cin >> A >> B >> X;
        cout << A * (X - 1) + B << '\n';
    }
    
    return 0;
}