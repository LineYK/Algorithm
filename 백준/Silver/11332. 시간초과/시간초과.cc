/*
시간초과
 
시간 제한	메모리 제한
2 초	256 MB	

문제
유빈이는 코딩을 하다가 시간 초과가 났다. 그래서 시간 복잡도를 계산하기로 했다.

채점 시스템은 1초에 100000000(108)가지 동작을 할 수 있다.

여러분들은 유빈이를 도와 시간초과가 나는지 확인하는 프로그램을 작성하라.

입력
입력의 첫 번째 줄에는 테스트 케이스들의 수 C가 주어진다.

그 다음 C개의 줄에는 시간 복잡도를 나타내는 문자열 S, 각 테스트 케이스마다 입력의 최대 범위 N, 테스트 케이스의 수를 나타내는 T랑 제한시간(초 단위) 를 나타내는 L이 주어진다. (1 <= C <= 100, 1 <= N <= 1000000, 1 <= T, L <= 10, N, T, L은 정수)

시간 복잡도는 다음과 같은 5개 중 하나로 주어진다.

O (N)
O (N^2)
O (N^3)
O (2^N)
O (N!)
출력
각 테스트 케이스들에 대하여 시간 초과가 나면 "TLE!", 시간 초과가 나지 않으면 "May Pass." 를 출력한다.

예제 입력 1 
5
O(N) 1000 10 10
O(2^N) 1000 10 10
O(N!) 2 10 10
O(N^3) 1000 1 10
O(N^3) 1001 1 10
예제 출력 1 
May Pass.
TLE!
May Pass.
May Pass.
TLE!
*/

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C;
    if(!(cin >> C)) return 0;
    while(C--){
        string S;
        long long N, T, L;
        cin >> S >> N >> T >> L;

        i128 allowed = (i128)100000000 * L;
        i128 allowedPer = allowed / T;

        bool tle = false;
        
        if (S.find("N!") != string::npos) {
            i128 val = 1;
            for(long long i = 1; i <= N; i++){
                val *= i;
                if(val > allowedPer) {
                    tle = true;
                    break;
                }
            }
        }
        else if (S.find("2^N") != string::npos) {
            i128 val = 1;
            for(long long i = 0; i < N; i++){
                val *= 2;
                if(val > allowedPer) {
                    tle = true;
                    break;
                }
            }
        }
        else {
            int power = 1;
            if (S.find("N^2") != string::npos) {
                power = 2;
            } else if (S.find("N^3") != string::npos) {
                power = 3;
            }
            
            i128 val = 1;
            for(int p = 0; p < power; p++){
                val *= N;
                if(val > allowedPer){
                    tle = true;
                    break;
                }
            }
        }

        cout << (tle ? "TLE!" : "May Pass.");
        if(C) cout << '\n';
    }
    return 0;
}