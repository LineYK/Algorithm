/*
소 체조 
 
시간 제한 메모리 제한
1초 512MB

문제
체력을 향상시키기 위해 소들이 체조를 시작했습니다! 
농부 존은 자신이 가장 좋아하는 소 베시를 코치로 지정하여 
다른 N마리의 소들을 지도하고 다양한 체조 기술을 배우면서 그들의 진도를 평가합니다.
베시는 K번의 연습 세션(1 <= K <= 10)에서 각 소의 성적(1 <= N <= 20)에 따라 N마리 소의 순위를 매깁니다. 
그 후, 그녀는 이러한 순위의 일관성에 대해 궁금해합니다. 
두 마리의 소 중 한 마리가 모든 연습 세션에서 다른 소보다 더 잘했다면 한 쌍의 소는 일관성이 있습니다.

베시가 일관된 한 쌍의 총 수를 계산하도록 도와주세요.

입력
입력 파일의 첫 번째 줄에는 두 개의 양의 정수 K와 N이 들어 있습니다. 
다음 K 줄에는 각각 소의 순위를 나타내는 정수 1 ... N이 일정한 순서로 들어 있습니다(소는 숫자 1 ... N으로 식별됨). 
이 줄 중 하나에서 A가 B보다 앞에 나타나면 젖소 A가 젖소 B보다 더 잘했다는 뜻입니다.

출력
일관된 쌍의 수를 한 줄에 출력합니다.

예제 입력 1 
3 4
4 1 2 3
4 1 3 2
4 2 1 3
예제 출력 1 
4
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<vector<int>> cows(K, vector<int>(N));

    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            cin >> cows[i][j];
        }
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            bool consistent = true;
            for(int k = 0; k < K; k++){
                int idx_i = -1, idx_j = -1;
                for(int l = 0; l < N; l++){
                    if(cows[k][l] == i) idx_i = l;
                    if(cows[k][l] == j) idx_j = l;
                }
                if(idx_i == -1 || idx_j == -1 || idx_i >= idx_j){
                    consistent = false;
                    break;
                }
            }
            if(consistent) cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}