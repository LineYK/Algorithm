/*
Zipline 
 
시간 제한    메모리 제한
1 초 (추가 시간 없음)    1024 MB

문제
Zipline은 매우 재미있고 빠른 이동 방법입니다. 매우 강한 강철 케이블을 사용하며, 두 개의 기둥에 연결되어 있습니다. 승객(사람이나 화물일 수 있음)은 케이블 위를 이동하는 풀리에 연결됩니다. 케이블의 높은 지점에서 시작하여 중력이 승객을 케이블을 따라 끌어갑니다.

친구가 재미와 실용성을 모두 위한 지프라인을 설계하고 설치하는 회사를 시작했습니다. 그러나 한 가지 핵심 문제가 있습니다: 두 연결점 사이의 케이블 길이를 결정하는 것입니다. 케이블은 두 기둥 사이를 연결할 만큼 충분히 길어야 하지만, 승객이 지면에서 안전한 거리를 유지할 수 있을 만큼 충분히 짧아야 합니다. 친구가 이 길이의 범위를 결정하는 데 도움을 주세요.

케이블은 두 개의 수직 기둥에 연결되어 있으며, 이 기둥들은 w 미터 간격으로 떨어져 있으며 각각 g 미터와 h 미터 높이에 위치합니다. 케이블은 탄성이 없고 라이더에 비해 무게가 무시할 수 있을 정도로 가벼우므로, 케이블에 처짐이나 이완이 없습니다. 즉, 모든 시점에서 케이블은 라이더와 두 기둥을 연결하는 두 개의 직선 세그먼트로 구성되며, 이 세그먼트의 길이의 합은 케이블의 총 길이와 같습니다. 라이더의 가장 낮은 부분은 케이블 아래 r 미터에 위치합니다. 따라서 라이딩 중 케이블은 항상 지면에서 r 미터 이상 떨어져 있어야 합니다. 두 기둥 사이의 지면은 평평합니다. 자세한 내용은 그림 M.1을 참조하세요.

그림 M.1: 네 가지 변수로 설명된 지퍼라인.

입력
입력은 정수 n이 포함된 행으로 시작됩니다. 여기서 1 ≤ n ≤ 1 000입니다. 다음 n 행은 각각 네 개의 정수 w, g, h, r로 지퍼라인 구성을 설명합니다. 이 변수들은 위에서 설명된 변수와 일치합니다. 이 변수의 값 제한은 다음과 같습니다: 1 ≤ w, g, h ≤ 1 000 000, 그리고 1 ≤ r ≤ min(g, h).

출력
각 지퍼라인에 대해 두 개의 길이(미터 단위)를 출력합니다: 위 제약 조건을 준수하면서 케이블이 가질 수 있는 최소 및 최대 길이입니다. 두 길이의 절대 오차는 최대 10−6 이내여야 합니다.

예제 입력 1 
2
1000 100 100 20
100 20 30 2
예제 출력 1 
1000.00000000 1012.71911209
100.49875621 110.07270325
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << fixed << setprecision(10);

    while (n--) {
        long long w, g, h, r;
        cin >> w >> g >> h >> r;

        long double L_min = sqrtl( (long double)w * w + (long double)(g - h) * (g - h) );

        long double dh = (long double)g + (long double)h - 2.0L * (long double)r;
        if (dh < 0) dh = 0;
        long double L_max = sqrtl( (long double)w * w + dh * dh );

        cout << L_min << " " << L_max << "\n";
    }

    return 0;
}
