/*
열심히 일하는 중
 
시간 제한	메모리 제한
1 초	512 MB	

문제
송이는 이번 학기에 할 일이 매우 많다. N개의 일 중 어떤 일부터 해야 할지 고민하던 중 송이에게 좋은 아이디어가 떠올랐다! 바로 해야 할 일 각각의 중요도를 산정하고, 중요도가 높은 일부터 하는 것이다. 송이는 하루에 하나의 일만 처리할 수 있으며, 일을 처리한 후 그 일의 중요도는 M만큼 감소한다. 일의 중요도가 K 이하가 되면 그 일은 완료한 것으로 간주한다. 중요도를 일별로 산정하던 중 송이는 문득 일하면서 본인이 매일 느낄 만족감이 궁금해졌다. 오늘의 만족감은 전날의 만족감을 Y, 오늘 할 일의 중요도를 P라 할 때 \lfloor Y/2 \rfloor+P와 같다.

예를 들면 다음과 같다. 전날 송이의 만족도가 21이고, 송이가 오늘 할 일의 중요도가 10, M의 값이 4라고 가정했을 때 송이가 오늘 느낄 만족감은 
 \lfloor \frac{21}{2} \rfloor+10 = 20이 된다. 이후 송이가 오늘 한 일의 중요도는 4만큼 감소해서 6이 된다.

송이가 해야 할 일의 개수 N, 일을 처리했을 때 감소하는 중요도 M, 완료한 것으로 간주하는 중요도의 최댓값 K가 주어진 후, i번 일이 가지는 중요도 D_i가 입력으로 N개 주어진다. 송이가 모든 일을 끝낼 때까지 며칠이 걸리는지, 그리고 모든 일을 끝낼 때까지 송이가 일별로 느낀 만족감을 한 줄마다 출력하자. 단, 첫날의 경우 전날의 만족감을 0으로 간주한다.

입력
첫째 줄에 정수 N, M, K가 공백으로 구분되어 주어진다. (2 \leq N \leq 2 \, 000; 1\leq M \leq 5; 1 \leq K \leq 3) 

둘째 줄부터 N개의 줄에 걸쳐 해야 하는 일의 중요도 정수 D_i가 주어진다. (M< D_i, K < D_i, D_i \leq 1 \, 000) 

출력
첫째 줄에 송이가 일을 다 하기 위해 걸리는 날의 수를 출력한다.

둘째 줄부터 일을 끝내는 날까지 일별로 느낀 만족감을 한 줄씩 구분해 출력한다.

예제 입력 1 
2 5 3
10
18
예제 출력 1 
5
18
22
21
18
14
노트
 \lfloor \ \rfloor는 바닥함수로, \lfloor x \rfloor 는 x 이하의 정수 중 가장 큰 정수를 뜻한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int D;
        cin >> D;
        pq.push(D);
    }

    long long prevSat = 0;

    vector<long long> satList;
    satList.reserve(2000000); 

    while (!pq.empty()) {
        int P = pq.top();
        pq.pop();

        long long todaySat = (prevSat / 2) + P;
        satList.push_back(todaySat);
        prevSat = todaySat; // 다음 날을 위해 업데이트

        int nextP = P - M;
        if (nextP > K) {
            pq.push(nextP);
        }
    }

    cout << satList.size() << "\n";
    for (long long s : satList) {
        cout << s << "\n";
    }

    return 0;
}
