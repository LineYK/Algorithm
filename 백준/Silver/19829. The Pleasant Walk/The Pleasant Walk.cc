/*
즐거운 산책
 
시간 제한 메모리 제한
1초 512MB	

문제
안야가 살고 있는 길에는 n개의 집이 있으며, 각 집은 가능한 k개의 색 중 하나로 칠해져 있습니다.
안야는 이 길을 따라 걷는 것을 좋아하지만, 길에 인접한 두 집의 색이 같은 것이 마음에 들지 않습니다. 
그녀는 인접한 두 집의 색이 같지 않도록 도로의 긴 구간을 선택하고 싶습니다.

안야가 이 속성을 사용하여 가장 긴 구간을 찾도록 도와주세요.

입력
첫 번째 줄에는 집의 수와 색의 수인 두 개의 정수 n과 k가 들어 있습니다(1 \le n \le 100\,000, 1 \le k \le 100\,000).

다음 줄에는 정수 a_1, a_2, \ldots, a_n --- 도로를 따라 있는 집의 색이 포함됩니다(1 \le a_i \le k).

출력
단일 정수 --- 도로 구간에서 같은 색의 인접한 집이 두 개 없는 최대 집 수를 출력합니다.

예제 입력 1 
8 3
1 2 3 3 2 1 2 2
예제 출력 1 
4
힌트
예제에서 같은 색의 이웃 집이 없는 가장 긴 구간은 4번 집부터 7번 집까지입니다. 집의 색은 [3, 2, 1, 2]이고 길이는 4집입니다.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    int prev, current, ans;
    cin >> prev;
    current = ans = 1;
    
    for (int i = 1; i < n; i++){
        int color;
        cin >> color;
        if(color == prev){
            current = 1;
        } else {
            current++;
        }
        ans = max(ans, current);
        prev = color;
    }
    
    cout << ans;
    return 0;
}