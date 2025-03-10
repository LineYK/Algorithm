/*
동작 N1
 
시간 제한 메모리 제한
1초 128MB	

문제
당신은 중앙대학교 셔틀버스를 운영하는 회사의 사장입니다. 
학생들은 이 버스를 이용해 강의실을 쉽게 이동할 수 있었습니다. 
어느 날, 학교는 당신의 등록금으로 흑석동의 모든 건물을 매입하여 캠퍼스를 확장했습니다. 
이로 인해 셔틀버스 운영 회사의 사장인 당신은 새로 확장된 캠퍼스 내에서 운행할 버스 노선을 새로 만들어야 했습니다.

공교롭게도 깔끔한 것을 좋아하는 총장님 때문에 새로 생긴 캠퍼스 내 도로는 두 줄의 직선 도로뿐입니다. 
다른 도로는 없습니다. 캠퍼스 도로에는 정류장이 n 개 있습니다.

버스 노선 개발을 위해 n개의 정류장 각각에 A1, A2, A3, ..., An-1, An의 정수로 번호를 매겼습니다.

한 정류장에서 다른 정류장으로 이동하려면 반드시 버스를 타야 합니다. 
적은 비용으로 버스 경로를 설계하고 싶습니다. 
그러나 합리적인 수의 정류장을 남겨두지 않으면 학생들은 설계에 불만을 가질 것입니다. 
이 경우 그들은 당신을 비난할 것이고 당신은 해고될 것입니다 :). 
그래서 당신은 n개의 정류장 중 가장 가까운 정류장을 찾아 하나로 합치기로 결정했습니다.

여러분은 컴퓨터 공학을 전공했고 버스 정류장의 번호를 매기는 데 정수를 사용하기로 결정했습니다. 
가장 가까운 두 정류장 사이의 거리를 구하고 이 거리로 두 정류장의 쌍 수를 계산하는 프로그램을 만들어 
이 문제를 해결하기로 결정했습니다.

입력
첫 번째 줄에는 정류장 수(2 ≤ n ≤ 5000)가 주어집니다.

두 번째 줄에는 각 정류장의 좌표 A1, ..., An(0 ≤ Ai ≤ 32,800,000)이 주어집니다. 각 숫자는 중복되지 않습니다.

출력
두 개의 정수가 출력되는데, 첫 번째 정수는 최소 거리이고 두 번째 정수는 이 거리를 가진 두 정류장의 쌍의 수입니다.

예제 입력 1 
4
6 3 0 4
예제 출력 1 
1 1
예제 입력 2 
4
6 4 0 2
예제 출력 2 
2 3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int min_dist = 1e9;

    for (int i = 0; i < N - 1; i++) {
        min_dist = min(min_dist, v[i + 1] - v[i]);
    }

    int cnt = 0;

    for (int i = 0; i < N - 1; i++) {
        if (v[i + 1] - v[i] == min_dist) {
            cnt++;
        }
    }

    cout << min_dist << ' ' << cnt << '\n';

    return 0;
}