/*
해바라기
 
시간 제한 메모리 제한
2 초 512 MB

문제
바바라는 가장 작은 것부터 가장 큰 것 순으로 각기 다른 높이를 가진 해바라기를 N개씩 심고, 연속되는 N일 동안 그 높이를 기록합니다. 매일 그녀의 모든 꽃은 전날보다 더 커집니다.

그녀는 각 식물에 대해 한 행씩, 첫 번째 행은 가장 짧은 해바라기의 성장을, 마지막 행은 가장 큰 해바라기의 성장을 기록하는 표에 이러한 각 측정값을 기록합니다. 가장 왼쪽 열은 각 해바라기의 첫 번째 측정값이고 가장 오른쪽 열은 각 해바라기의 마지막 측정값입니다.

처음 심었을 때 해바라기가 다른 해바라기보다 작았다면 모든 측정에서 더 작게 유지됩니다.

안타깝게도 바바라의 자녀들이 테이블을 90도의 배수만큼 회전시켜 측정값을 변경했을 수 있습니다.

여러분의 임무는 바바라가 원래 데이터를 확인하도록 돕는 것입니다.

입력
입력의 첫 번째 줄에는 숫자 N(2 ≤ N ≤ 100)이 들어 있습니다. 다음 N 줄은 각각 최대 10^9인 양의 정수 N 개를 포함합니다. 입력 그리드는 바바라의 그리드의 회전된 버전을 나타냅니다.

출력
바바라의 원래 데이터를 출력하며, 각 줄이 양의 정수 N개를 포함하는 N개의 줄로 구성됩니다.

예제 입력 1 
2
1 3
2 9
예제 출력 1 
1 3
2 9
데이터가 360도의 배수만큼 회전되었으므로 입력 배열이 원래 배열입니다.

예제 입력 2 
3
4 3 1
6 5 2
9 7 3
예제 출력 2 
1 2 3
3 5 7
4 6 9
원본 데이터를 오른쪽/시계 방향으로 90도 회전했습니다.

예제 입력 3 
3
3 7 9
2 5 6
1 3 4
예제 출력 3 
1 2 3
3 5 7
4 6 9
원본 데이터를 왼쪽/시계 반대 방향으로 90도 회전했습니다.
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    if (arr[0][0] < arr[0][1] && arr[0][0] < arr[1][0]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else if (arr[0][0] < arr[0][1] && arr[0][0] > arr[1][0]) {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
    } else if (arr[0][0] > arr[0][1] && arr[0][0] > arr[1][0]) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}