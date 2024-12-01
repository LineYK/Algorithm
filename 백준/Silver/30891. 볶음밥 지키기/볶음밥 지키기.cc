/*
볶음밥 지키기 스페셜 저지
 
시간 제한	메모리 제한
1 초	1024 MB
문제
매일 배달 음식만 시켜 먹다 질려버린 영재는 직접 볶음밥을 해 먹기로 결심했습니다. 
오랜만에 느껴지는 맛있는 냄새에 신이 난 영재는 난데없이 힘찬 웍질을 시도했고, 
지금 $N$개의 밥알이 흩날리고 있습니다. 
밥알이 떨어지는 방향은 모두 $-z$축 방향입니다.

흥이 다 깨져버리면 안 되기 때문에, 영재는 반지름 
$R$의 웍을 적절한 위치에 두어 최대한 많은 밥알을 지켜내야만 합니다. 
웍의 중심 $(X, Y)$와 밥알의 좌표 
$(x_i, y_i) \, (1≤i≤N)$에 대해, 
$\sqrt{ (X-x_i)^2+(Y-y_i)^2 } \le R$인 밥알들은 모두 지켜낸 것으로 가정합니다. 또한, 웍의 중심 좌표 
$X$와 
$Y$는 정수여야 합니다.

일촉즉발의 상황... 여러분이 영재의 기분을 지켜주세요!

입력
첫째 줄에 흩날리는 밥알의 개수 
$N$과 웍의 반지름 
$R$이 주어집니다. 
$(1≤N, R≤100)$ 

다음 
$N$개의 줄에 걸쳐서 
$i$번째 밥알의 좌표 
$x_i, y_i$가 주어집니다. 
$(-100≤x_i, y_i≤100)$ 

모든 밥알의 위치는 서로 다르며, 주어지는 수는 모두 정수입니다.

출력
 
$X, Y$가 모두 정수인 좌표 중 가장 많은 밥알을 지킬 수 있는 웍의 중심 좌표를 출력합니다. 가능한 답이 여러 가지인 경우, 그 중 아무거나 하나만 출력해 주세요.

예제 입력 1 
7 2
1 1
-1 1
3 1
1 3
1 -1
5 1
5 3
예제 출력 1 
1 1

위 그림과 같이 웍의 중심을 (1,1)에 두면, 5개의 밥알을 지켜낼 수 있습니다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R;
    cin >> N >> R;

    int max_x = -1, min_x = 101;
    
    vector<vector<int>> v(N, vector<int>(2));

    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
        max_x = max(max_x, v[i][0]);
        min_x = min(min_x, v[i][0]);
    }

    int cnt = -100;
    int resultX = 0;
    int resultY = 0;

    for (int i = min_x; i <= max_x; i++) {
        for (int j = min_x; j <= max_x; j++) {
            int tempCnt = 0;
            
            
            for (int k = 0; k < N; k++) {
                double r = sqrt(pow(i - v[k][0], 2) + pow(j - v[k][1], 2));
                
                if (r <= R) {
                    tempCnt++;
                }
            }
            
            
            if (tempCnt > cnt) {
                cnt = tempCnt;
                resultX = i;
                resultY = j;
            }
        }
    }

    cout << resultX << " " << resultY << "\n";

	return 0;
}