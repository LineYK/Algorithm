/*
Excellence
 
시간 제한	메모리 제한
2 초	256 MB

문제 설명
세계 코딩 연맹(The World Coding Federation)은 프로그래머 두 명으로 구성된 
팀들이 참가하는 대규모 온라인 프로그래밍 대회를 준비 중입니다. 
이 대회에서 Southeastern 대표단의 팀 구성을 담당하는 것은 심사위원 David입니다. 
각 학생은 반드시 두 명으로 구성된 팀에 속해야 하며, 모든 학생은 반드시 대회에 참가해야 합니다. 
다행히 참가를 희망하는 학생 수가 짝수라서 모든 학생이 팀에 들어갈 수 있습니다.

David는 다른 심사위원들 사이에서 완벽한 명성을 유지하고 싶기 때문에 
대회에 출전할 모든 팀의 총 점수(두 학생의 점수 합) 가 일정 수준 이상이 되도록 하고 싶습니다.
팀의 총 점수는 해당 팀을 구성하는 두 명의 학생 점수를 더한 값입니다.

David가 구성할 수 있는 팀들의 최소 총 점수 X의 최댓값을 구하는 프로그램을 작성하세요. 
즉, 모든 팀의 점수가 X 이상이 되도록 할 때, X의 최대값을 출력해야 합니다.

입력
첫 번째 줄에 대회에 참가할 학생 수를 나타내는 짝수 정수 n이 주어집니다.
(1 ≤ n ≤ 10^5, n은 짝수)

그다음 줄부터 n개의 줄에 각 학생의 개인 점수 si가 한 줄에 하나씩 주어집니다.
(1 ≤ si ≤ 10^6)

출력
모든 팀의 총 점수가 X 이상이 되도록 할 때, X의 최대값을 한 줄에 출력하세요.

예제 입력 1 
4
1
2
3
5
예제 출력 1 
5
예제 입력 2 
2
18
16
예제 출력 2 
34
예제 입력 3 
4
13
12
19
14
예제 출력 3 
27
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> data;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        data.push_back(num);
    }

    sort(data.begin(), data.end());

    int min_value = 1000001;
    for (int i = 0; i < n / 2; i++) {
        int value = data[i] + data[n - i - 1];
        min_value = min(min_value, value);
    }

    cout << min_value << endl;

    return 0;
}
