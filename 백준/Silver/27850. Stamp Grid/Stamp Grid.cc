/*
스탬프 그리드

시간 제한: 2 초  
메모리 제한: 1024 MB

문제  
스탬프 그림은 N × N 캔버스에 그려진 흑백 그림으로, 
특정 셀은 잉크가 칠해져 있고 다른 셀은 비어 있습니다. 
이 그림은 N × N 크기의 문자 배열로 표현할 수 있습니다 (1 ≤ N ≤ 20). 
배열의 j번째 열의 i번째 항목은 해당 사각형에 잉크가 칠해져 있으면 *이고, 그렇지 않으면 .입니다.

Bessie는 자신이 만들고 싶은 스탬프 그림이 있어서, 
Farmer John은 그녀에게 K × K 크기의 스탬프(1 ≤ K ≤ N)와 빈 N × N 캔버스를 빌려주었습니다. 
Bessie는 스탬프를 시계 방향으로 90도 회전시킬 수 있으며, 
스탬프가 그리드 내부에 완전히 들어가는 한 그리드 어디에나 스탬프를 찍을 수 있습니다. 
정확히 말하자면, Bessie는 i ∈ [1, N-K+1]이고 j ∈ [1, N-K+1]인 정수 i, j를 선택합니다. 
그리고 1 ≤ i', j' ≤ K인 모든 (i', j')에 대해, 
캔버스 셀 (i+i'-1, j+j'-1)은 스탬프가 (i', j')에 잉크가 칠해져 있으면 검은색으로 칠해집니다. 
Bessie는 스탬프를 찍는 사이에 언제든지 스탬프를 회전할 수 있습니다. 
캔버스 셀이 한 번 검은색으로 칠해지면, 그 상태로 유지됩니다.

Farmer John은 Bessie가 자신의 스탬프로 원하는 스탬프 그림을 만들 수 있는지 궁금해합니다. 
각각의 T(1 ≤ T ≤ 100) 테스트 케이스에 대해, Farmer John의 질문에 답해주세요.

입력  
첫 번째 줄에는 테스트 케이스의 수 T가 입력됩니다.

각 테스트 케이스는 정수 N으로 시작하며, 
그 다음 N줄에 걸쳐 *와 .로 이루어진 문자열이 입력됩니다. 
이 문자열은 Bessie가 원하는 스탬프 그림을 나타냅니다. 그 다음 줄에는 K가 입력되고, 
그 다음 K줄에 걸쳐 *와 .로 이루어진 문자열이 입력됩니다. 
이 문자열은 Farmer John의 스탬프를 나타냅니다. 연속된 테스트 케이스는 빈 줄로 구분됩니다.

출력  
각 테스트 케이스에 대해 "YES" 또는 "NO"를 출력합니다.

예제 입력 1  
4

2
**
*.
1
*

3
.**
.**
***
2
.*
**

3
...
.*.
...
3
.*.
...
...

3
**.
.**
..*
2
.*
*.

예제 출력 1  
YES
YES
NO
YES


첫 번째 테스트 케이스에서, Bessie는 다음과 같은 순서로 스탬프를 찍을 수 있습니다:

1. (1,1)에 스탬프 찍기  
2. (1,2)에 스탬프 찍기  
3. (2,1)에 스탬프 찍기  

두 번째 테스트 케이스에서, Bessie는 다음과 같은 순서로 스탬프를 찍을 수 있습니다:

1. (2,2)에 스탬프 찍기  
2. (2,1)에 스탬프 찍기  
3. 90도 회전  
4. 90도 회전  
5. (1,2)에 스탬프 찍기  

세 번째 테스트 케이스에서는 중앙 셀을 칠할 수 없습니다.

네 번째 테스트 케이스에서, Bessie는 다음과 같은 순서로 스탬프를 찍을 수 있습니다:

1. 90도 회전  
2. (1,1)에 스탬프 찍기  
3. (1,2)에 스탬프 찍기  
4. (2,2)에 스탬프 찍기  
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> generate_rotations(vector<string> stamp) {
    vector<vector<string>> rotations;
    rotations.push_back(stamp);
    int K = stamp.size();
    for (int r = 1; r < 4; r++) {
        vector<string> rotated(K, string(K, '.'));
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                rotated[j][K - 1 - i] = stamp[i][j];
            }
        }
        rotations.push_back(rotated);
        stamp = rotated;
    }
    return rotations;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> desired(N);
        for (int i = 0; i < N; i++) {
            cin >> desired[i];
        }
        int K;
        cin >> K;
        vector<string> stamp(K);
        for (int i = 0; i < K; i++) {
            cin >> stamp[i];
        }
        
        auto rotations = generate_rotations(stamp);
        set<pair<int, int>> covered;
        set<pair<int, int>> desired_stars;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (desired[i][j] == '*') {
                    desired_stars.insert({i, j});
                }
            }
        }
        
        for (const auto& rot : rotations) {
            int K_rot = rot.size();
            for (int x = 0; x <= N - K_rot; x++) {
                for (int y = 0; y <= N - K_rot; y++) {
                    bool valid = true;
                    for (int i = 0; i < K_rot && valid; i++) {
                        for (int j = 0; j < K_rot; j++) {
                            if (rot[i][j] == '*') {
                                int nx = x + i;
                                int ny = y + j;
                                if (nx >= N || ny >= N || desired[nx][ny] != '*') {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                    }
                    if (valid) {
                        for (int i = 0; i < K_rot; i++) {
                            for (int j = 0; j < K_rot; j++) {
                                if (rot[i][j] == '*') {
                                    covered.insert({x + i, y + j});
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if (covered == desired_stars) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}