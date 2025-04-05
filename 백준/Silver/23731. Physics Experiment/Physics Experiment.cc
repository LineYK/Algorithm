/*
물리학 실험 
 
시간 제한 메모리 제한 
1 초 (추가 시간 없음) 1024 MB (추가 메모리 없음)
문제
유니는 물리학 실험실 수업을 듣고 있습니다. 어느 날 실험을 마치고 유니는 실험 결과의 일부 수치가 예상보다 낮게 나온 것을 발견했습니다. 그래서 유니는 값을 여러 번 반올림하여 결과를 조작하기로 결정했습니다.
숫자를 소수점 이하로 반올림할 때 소수점 이하에서 한 자리 오른쪽의 숫자가 5보다 작으면 반내림합니다. 그렇지 않으면 반올림됩니다. 예를 들어 454를 가장 가까운 소수점 이하로 반올림하면 450이 됩니다. 반면에 454를 가장 가까운 100으로 반올림하면 500이 됩니다.
454를 가장 가까운 백 단위로 반올림한 다음 천 단위로 반올림하면 454 \rightarrow 500 \rightarrow 1000이 됩니다. 이것이 454를 0 이상으로 반올림하여 얻을 수 있는 최대 값입니다.
유니가 실험 결과의 값을 0 이상으로 반올림하여 최대화할 수 있도록 도와주세요.
입력
첫 번째 줄에는 실험 결과의 값을 나타내는 정수 N이 포함됩니다(1\le N \le 10^{15}). N은 32비트 정수 제한을 초과할 수 있습니다.
출력
N을 0 이상으로 반올림하여 최대값을 출력합니다. 출력에는 선행 0이 없어야 합니다.


예제 입력 1 
454
예제 출력 1 
1000
예제 입력 2 
4445
예제 출력 2 
10000
예제 입력 3 
1234321
예제 출력 3 
1234321
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;
    
    long long place = 10;
    for (int i = 0; i < 18; i++) {
        long long d = (N / (place / 10)) % 10;  
        if(d >= 5) {
            N = (N / place + 1) * place;
        }
        place *= 10;
    }
    
    cout << N;
    return 0;
}