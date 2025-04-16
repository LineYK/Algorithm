/*
알고리즘 수업 - 선택 정렬 1
 
시간 제한   메모리 제한
1 초   512 MB
문제
오늘도 서준이는 선택 정렬 수업 조교를 하고 있다. 아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.

N개의 서로 다른 양의 정수가 저장된 배열 A가 있다. 선택 정렬로 배열 A를 오름차순 정렬할 경우 K 번째 교환되는 수를 구해서 우리 서준이를 도와주자.

크기가 N인 배열에 대한 선택 정렬 의사 코드는 다음과 같다.

selection_sort(A[1..N]) { # A[1..N]을 오름차순 정렬한다.
    for last <- N downto 2 {
        A[1..last]중 가장 큰 수 A[i]를 찾는다
        if (last != i) then A[last] <-> A[i]  # last와 i가 서로 다르면 A[last]와 A[i]를 교환
    }
}
입력
첫째 줄에 배열 A의 크기 N(5 ≤ N ≤ 10,000), 교환 횟수 K(1 ≤ K ≤ N)가 주어진다.

다음 줄에 서로 다른 배열 A의 원소 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

출력
K 번째 교환되는 두 개의 수를 작은 수부터 한 줄에 출력한다. 교환 횟수가 K 보다 작으면 -1을 출력한다.

예제 입력 1 
5 2
3 1 2 5 4
예제 출력 1 
2 3
3 1 2 5 4 (4와 5가 교환됨) -> 3 1 2 4 5 (A[1..4]에서 4가 가장 크므로 교환이 발생하지 않음) -> 3 1 2 4 5 (2와 3이 교환됨) -> 2 1 3 4 5 (1과 2가 교환됨) -> 1 2 3 4 5. 총 3회 교환이 발생하고 두 번째 교환은 2와 3이다.

예제 입력 2 
5 4
3 1 2 5 4
예제 출력 2 
-1
교환 횟수 3이 K 보다 작으므로 -1을 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int swapCount = 0;
    for (int last = N - 1; last > 0; --last) {
        int maxIndex = last;
        for (int i = 0; i < last; ++i) {
            if (A[i] > A[maxIndex]) {
                maxIndex = i;
            }
        }

        if (maxIndex != last) {
            swap(A[maxIndex], A[last]);
            swapCount++;
            if (swapCount == K) {
                cout << min(A[maxIndex], A[last]) << " " << max(A[maxIndex], A[last]) << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";

    return 0;
}