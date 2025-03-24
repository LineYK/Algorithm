/*
수열 회전과 쿼리
 
시간 제한	메모리 제한
1 초	1024 MB	

문제
길이가 N인 정수 수열 [A_1,A_2,\dots,A_N]이 주어진다. 이때 다음 쿼리를 수행하는 프로그램을 작성해보자.

1 k: 수열을 오른쪽으로 k만큼 회전시킨다. 즉, A_1의 값은 A_{N-k+1}, A_2의 값은 A_{N-k+2}, \dots, A_k의 값은 A_N, A_{k+1}의 값은 A_1, A_{k+2}의 값은 A_2, \dots, A_N의 값은 A_{N-k}로 동시에 변한다.
2 k: 수열을 왼쪽으로 k만큼 회전시킨다. 즉, A_1의 값은 A_{k+1}, A_2의 값은 A_{k+2}, \dots, A_{N-k}의 값은 A_N, A_{N-k+1}의 값은 A_1, A_{N-k+2}의 값은 A_2, \dots, A_N의 값은 A_k로 동시에 변한다.
3 a b: 수열의 a번째 수부터 b번째 수의 합을 출력한다. 즉, \sum_{i=a}^b A_i를 출력한다.

입력
첫 번째 줄에 수열의 길이 N과 쿼리의 수 Q가 공백으로 구분되어 주어진다.

두 번째 줄에 N개의 정수 A_1,A_2,\dots,A_N이 공백으로 구분되어 주어진다.

세 번째 줄부터 Q개의 줄에 걸쳐 쿼리가 한 줄에 하나씩 주어진다.

출력
3번 쿼리에 대한 결괏값을 한 줄에 하나씩 입력으로 주어진 순서대로 출력한다.

제한
2 \le N \le 200\,000
1 \le Q \le 200\,000
1 \le A_i \le 10^9
1 \le k \le N
1 \le a \le b \le N
입력으로 주어지는 모든 수는 정수이다.
3번 쿼리는 한 번 이상 주어진다.
예제 입력 1 
7 5
3 2 1 5 10 6 2
3 1 3
2 1
3 1 3
1 3
3 2 6
예제 출력 1 
6
8
13
수열 [3,2,1,5,10,6,2]에서 1번째 수부터 3번째 수의 합은 6이다.
수열 [3,2,1,5,10,6,2]를 왼쪽으로 1만큼 회전시키면 수열이 [2,1,5,10,6,2,3]으로 변한다.
수열 [2,1,5,10,6,2,3]에서 1번째 수부터 3번째 수의 합은 8이다.
수열 [2,1,5,10,6,2,3]를 오른쪽으로 3만큼 회전시키면 수열이 [6,2,3,2,1,5,10]으로 변한다
수열 [6,2,3,2,1,5,10]에서 2번째 수부터 6번째 수의 합은 13이다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int offset = 0;

    while(Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            cin >> k;
            offset = (offset - k % N + N) % N;
        } else if (type == 2) {
            int k;
            cin >> k;
            offset = (offset + k) % N;
        } else if (type == 3) {
            int a, b;
            cin >> a >> b;
            int L = (offset + a - 1) % N;
            int R = (offset + b - 1) % N;
            long long ans = 0;
            if (L <= R) {
                ans = prefix[R + 1] - prefix[L];
            } else {
                ans = (prefix[N] - prefix[L]) + prefix[R + 1];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}