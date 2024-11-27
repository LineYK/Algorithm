/*
사랑은 고려대입니다
 
시간 제한	메모리 제한
1 초	1024 MB

문제
사랑은 고려대입니다.

입력
첫 번째 줄에 정수 $N(1\leq N\leq 10)$이 주어진다.

출력
첫 번째 줄에 LoveisKoreaUniversity를 공백으로 구분하여 $N$번 출력한다.

예제 입력 1 
1
예제 출력 1 
LoveisKoreaUniversity
예제 입력 2 
2
예제 출력 2 
LoveisKoreaUniversity LoveisKoreaUniversity
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cout << "LoveisKoreaUniversity";
        if (i != N - 1) {
            cout << " ";
        }
    }
    
	return 0;
}