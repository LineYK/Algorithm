/*
완전제곱수
 
시간 제한   메모리 제한
2 초   128 MB

문제
M과 N이 주어질 때 M이상 N이하의 자연수 중 완전제곱수인 것을 모두 골라 그 합을 구하고 그 중 최솟값을 찾는 프로그램을 작성하시오. 
예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 완전제곱수는 64, 81, 100 이렇게 총 3개가 있으므로 
그 합은 245가 되고 이 중 최솟값은 64가 된다.

입력
첫째 줄에 M이, 둘째 줄에 N이 주어진다. M과 N은 10000이하의 자연수이며 M은 N보다 같거나 작다.

출력
M이상 N이하의 자연수 중 완전제곱수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다. 단, M이상 N이하의 자연수 중 완전제곱수가 없을 경우는 첫째 줄에 -1을 출력한다.

예제 입력 1 
60
100
예제 출력 1 
245
64
예제 입력 2 
75
80
예제 출력 2 
-1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    int sum = 0;
    int minSquare = -1;

    for(int i = 1; i * i <= N; i++){
        int square = i * i;
        if(square >= M){
            sum += square;
            if(minSquare == -1) minSquare = square;
        }
    }

    if(sum == 0) cout << -1 << "\n";
    else cout << sum << "\n" << minSquare << "\n";

    return 0;
}
