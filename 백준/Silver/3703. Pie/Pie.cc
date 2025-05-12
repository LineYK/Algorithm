/*
Pie 
 
시간 제한 메모리 제한
1 초 128 MB

문제
제 생일이 다가오는데 전통적으로 파이를 대접하고 있습니다. 한 개의 파이가 아니라 다양한 맛과 크기의 파이를 N 개나 준비했습니다. 제 친구 중 F명이 파티에 오는데 각자 파이 한 조각씩을 받습니다. 파이를 여러 조각으로 나누면 지저분해 보이므로 파이 한 조각이어야 합니다. 하지만 이 조각은 하나의 파이가 될 수 있습니다.

제 친구들은 매우 짜증을 잘 내기 때문에 한 명이 다른 친구들보다 더 큰 조각을 받으면 불평하기 시작합니다. 따라서 일부 파이가 상하더라도(파티를 망치는 것보다는 낫지만) 모든 파이가 같은 크기(반드시 같은 모양일 필요는 없음)의 조각을 가져가야 합니다. 물론 저도 파이 한 조각을 먹고 싶고, 그 조각도 같은 크기여야 합니다.

우리 모두가 먹을 수 있는 가장 큰 조각 크기는 얼마일까요? 모든 파이의 모양은 원통형이고 모두 높이가 1로 같지만, 파이의 반지름은 다를 수 있습니다.

양의 정수로 한 줄, 즉 테스트 케이스의 수를 입력합니다. 그런 다음 각 테스트 케이스에 대해

1 ≤ N, F ≤ 10 000의 두 정수가 포함된 한 줄: 파이의 수와 친구의 수입니다.
1 ≤ ri ≤ 10,000의 정수 ri가 있는 한 줄: 파이의 반지름.
출력
각 테스트 케이스에 대해, 나와 친구들이 모두 크기 V의 파이 조각을 얻을 수 있도록 가능한 최대 부피 V를 가진 한 줄을 출력하세요. 답은 절대 오차가 최대 10-3인 부동 소수점 숫자로 주어져야 합니다.

예제 입력 1 
3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2
예제 출력 1 
25.1327
3.1416
50.2655
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double PI = acos(-1.0);
    int T;
    cin >> T;

    while (T--) {
        int N, F;
        cin >> N >> F;
        vector<double> r(N);
        for (int i = 0; i < N; i++) {
            cin >> r[i];
        }
        vector<double> vols(N);
        for (int i = 0; i < N; i++) {
            vols[i] = PI * r[i] * r[i];
        }
        double lo = 0.0, hi = *max_element(vols.begin(), vols.end());
        for (int it = 0; it < 60; it++) {
            double mid = (lo + hi) / 2.0;
            long long pieces = 0;
            for (double v : vols) {
                pieces += (long long)(v / mid);
            }
            if (pieces >= F + 1) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << fixed << setprecision(4) << lo << "\n";
    }

    return 0;
}