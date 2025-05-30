/*
오버사이즈 팬케이크 플리퍼 (스몰)
 
시간 제한 메모리 제한
5 초 512 MB

문제
작년에 무한 팬케이크 하우스에서 새로운 종류의 팬케이크를 선보였습니다. 한쪽("행복한 면")에는 초콜릿 칩으로 만든 행복한 얼굴이 있고, 다른 쪽("빈 면")에는 아무것도 없습니다.

여러분이 당번 주방장입니다. 팬케이크는 뜨거운 표면 위에서 한 줄로 일렬로 조리됩니다. 효율성을 극대화하기 위한 무한한 노력의 일환으로, 최근에는 팬케이크를 정확히 K번 연속으로 뒤집는 대형 팬케이크 플리퍼를 제공했습니다. 즉, 해당 범위의 K 팬케이크에서 모든 해피 사이드 팬케이크를 빈 사이드 팬케이크로 바꾸거나 그 반대로 바꾸며, 팬케이크의 왼쪽에서 오른쪽 순서는 바꾸지 않습니다.

플리퍼로 한 번에 K개 미만의 팬케이크만 뒤집을 수 있으며, 줄의 끝에서도 뒤집을 수 없습니다(조리 표면 양쪽에 테두리가 올라와 있기 때문에). 예를 들어, 첫 번째 K 팬케이크는 뒤집을 수 있지만 첫 번째 K-1 팬케이크는 뒤집지 못합니다.

아직 일을 배우고 있는 견습 요리사가 구식 팬케이크 플리퍼를 사용하여 개별 팬케이크를 뒤집은 다음 고객이 주방을 방문하는 시간 직전에 팬케이크를 들고 화장실로 달려갔습니다. 대형 팬케이크 플리퍼가 하나밖에 남지 않았기 때문에 빨리 사용하여 모든 팬케이크를 뒤집어 놓아야 손님이 만족스러운 방문을 하고 돌아갈 수 있습니다.

팬케이크의 현재 상태가 주어졌을 때, 모든 팬케이크를 뒤집어 놓는 데 필요한 대형 팬케이크 플리퍼의 최소 사용 횟수를 계산하거나, 방법이 없음을 명시합니다.

입력
입력의 첫 줄은 테스트 케이스의 개수, T. T 테스트 케이스가 이어집니다. 각 테스트 케이스는 문자열 S와 정수가 포함된 한 줄로 구성되며, S는 팬케이크의 행을 나타냅니다. 각 문자는 +(처음에 행복한면이 위로 향하는 팬케이크를 나타냄) 또는 -(처음에 빈면이 위로 향하는 팬케이크를 나타냄) 중 하나입니다.

제한

1 ≤ T ≤ 100.
S의 모든 문자는 + 또는 -입니다.
2 ≤ K ≤ S의 길이.
2 ≤ S의 길이 ≤ 10.
출력
각 테스트 케이스에 대해 케이스 #x: y가 포함된 한 줄을 출력합니다. 여기서 x는 테스트 케이스 번호(1부터 시작)이고 y는 팬케이크를 모두 뒤집어 놓을 방법이 없는 경우 불가능하거나 대형 팬케이크 플리퍼를 사용해야 하는 최소 횟수를 나타내는 정수를 출력합니다.

예제 입력 1 
3
---+-++- 3
+++++ 4
-+-+- 4
예제 출력 1 
Case #1: 3
Case #2: 0
Case #3: IMPOSSIBLE

힌트
사례 #1에서는 먼저 가장 왼쪽의 팬케이크 3개를 뒤집어 ++++-++-에 도달한 다음, 가장 오른쪽의 팬케이크 3개를 뒤집어 ++++---+에 도달하고 마지막으로 빈 면이 위로 향하도록 하여 모든 팬케이크의 행복한 쪽을 위로 올릴 수 있습니다. 3번 이상 뒤집는 다른 방법도 있지만 3번 이하로 뒤집는 방법은 없습니다.
케이스 2에서는 모든 팬케이크가 이미 앞면이 위로 향하게 되어 있으므로 뒤집을 필요가 없습니다.
케이스 #3의 경우, 왼쪽에서 두 번째와 세 번째 팬케이크는 뒤집으면 둘 다 뒤집히기 때문에 같은 면이 위로 향하게 만들 방법이 없습니다. 따라서 모든 팬케이크의 앞면이 위로 향하게 만들 수 있는 방법은 없습니다.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        string S;
        int K;
        cin >> S >> K;
        int N = S.size();
        int ans = 0;

        for(int i = 0; i + K <= N; i++){
            if(S[i] == '-'){
                ans++;
                for(int j = 0; j < K; j++){
                    S[i+j] = (S[i+j] == '-' ? '+' : '-');
                }
            }
        }

        bool ok = true;
        for(int i = N-K+1; i < N; i++){
            if(S[i] == '-'){
                ok = false;
                break;
            }
        }

        cout << "Case #" << tc << ": ";
        if( ok ) cout << ans << "\n";
        else   cout << "IMPOSSIBLE\n";
    }

    return 0;
}

