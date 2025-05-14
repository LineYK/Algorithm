/*
유치원생 파댕이 돌보기
 
시간 제한	메모리 제한
1 초	1024 MB	

문제
유치원생 파댕이는 아직 어리기 때문에 단것을 매우 좋아한다.

또한, 파댕이는 사탕을 주지 않으면 시도 때도 없이 울곤 한다.

파댕이를 사랑하는 여러분은 일정 시간 동안 파댕이를 돌봐주기로 했다. 여러분은 파댕이를 돌보는 동안 파댕이가 우는 것을 보고 싶지 않기에, 파댕이가 울지 않도록 사탕을 챙겨왔다. 하지만 파댕이를 빨리 보고 싶은 마음에 급하게 사탕을 챙기느라, 돌보는 동안 파댕이가 울지 않게 만들 수 있는 충분한 사탕의 개수인지 확인하지 못했다. 여러분이 가지고 있는 사탕으로 파댕이를 돌보는 동안 파댕이를 울지 않게 만들 수 있는지 알아보자!

여러분은 T분 동안 파댕이를 돌봐야 하며, N개의 사탕을 가지고 있다. 파댕이는 사탕의 맛에 따라 울음을 그치는 시간이 다르며, 사탕의 맛이 F일 때 F분 동안 울음을 멈춘다.

입력
첫 번째 줄에 파댕이를 돌봐야 하는 시간을 나타내는 정수 T (1 \leq T \leq 1 \, 000)가 주어진다. 두 번째 줄에 가지고 있는 사탕의 총 개수를 나타내는 정수 N (1 \leq N \leq 100)이 주어진다. 세 번째 줄에 각 사탕의 맛을 나타내는 정수 F (1 \leq F \leq 10)가 공백으로 구분되어 총 N개가 주어진다.

출력
파댕이를 T 분 동안 울지 않게 만들 수 있다면 Padaeng_i Happy를 출력한다. 이외의 경우에는 Padaeng_i Cry를 출력한다.

예제 입력 1 
5
2
2 3
예제 출력 1 
Padaeng_i Happy
예제 입력 2 
6
2
2 3
예제 출력 2 
Padaeng_i Cry
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    cin >> T >> N;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }

    int total_happy_time = 0;
    for (int i = 0; i < N; ++i) {
        total_happy_time += F[i];
    }

    if (total_happy_time >= T) {
        cout << "Padaeng_i Happy\n";
    } else {
        cout << "Padaeng_i Cry\n";
    }
    return 0;
}
