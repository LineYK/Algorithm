/*
제리와 톰 2
 
시간 제한	메모리 제한
1 초	256 MB
문제
톰은 마트에서 치즈 1kg 을 사서 집으로 돌아왔습니다.

그런데 톰이 한눈을 판 사이 제리가 와서 

$ \cfrac{1}{a_1 + \cfrac{1}{a_2 + \cfrac{1}{\ddots + \cfrac{1}{a_N}}}} $ kg 만큼 훔쳐갔습니다.

제리가 치즈를 훔쳐 간 후 톰이 가지고 있는 치즈의 무게는 얼마인가요?

입력
첫 번째 줄에 정수 N (2 ≤ N ≤ 15) 가 주어집니다.

두 번째 줄에는 정수 a1, a2, ..., aN (1 ≤ ai ≤ 9) 이 주어집니다.

출력
정답을 기약분수로 표현했을 때 P/Q kg 이라면 첫 번째 줄에 P와 Q를 공백을 사이에 두고 출력합니다.

예제 입력 1 
4
2 7 1 8
예제 출력 1 
80 151

$$ 1 - \cfrac{1}{2 + \cfrac{1}{7 + \cfrac{1}{1 + \cfrac{1}{8}}}} =  1 - \cfrac{1}{2 + \cfrac{1}{7 + \cfrac{8}{9}}} = 1 - \cfrac{1}{2 + \cfrac{9}{71}} = 1 - \cfrac{71}{151} = \cfrac{80}{151} $$ 

예제 입력 2 
15
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
예제 출력 2 
217226082829553 244011802169763

힌트
정답이 32bit 정수형의 범위를 초과할 수 있음에 주의하세요. 

C/C++의 경우 long long 타입, Java의 경우 long 타입을 사용하는 것을 권장합니다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    a.push_back(1);

    while (a.size() > 2) {
        long long x = a.back();
        a.pop_back();
        long long y = a.back();
        a.pop_back();
        long long z = a.back();
        a.pop_back();
        a.push_back(y * z + x);
        a.push_back(y);
    }

    cout << a[0] - a[1] << ' ' << a[0] << endl;

    return 0;
}