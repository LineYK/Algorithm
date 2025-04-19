/*
반짝반짝 빛나는 별가루
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	512 MB	927	228	196	27.684%
문제
스타는 별가루를 만드는 마법 연습을 하는 중이다. 본인의 실력을 시험하기 위해 하루에 한 번씩, 총 
$N$일 동안 마법을 사용하여 별가루를 얼마나 만들 수 있는지 확인하고자 했고 
$N$일 동안의 계획을 세웠다.

스타는 별가루를 만들 수 있는 
$K$가지의 마법을 사용할 수 있다. 각각의 마법을 
$1$번 마법, 
$2$번 마법, ... , 
$K$번 마법이라고 부르기로 하자.

 
$i$번 마법을 사용해서 만들 수 있는 별가루의 개수는 다음과 같다.

 
 
 
$\Delta Stardust = \lfloor base_i(1+\frac{combo \cdot C}{100})(1+\frac{skill_i \cdot s_i}{100}) \rfloor$ 

식에 대한 설명은 다음과 같다.

 
$\Delta Stardust$: 만들어진 별가루의 개수이다.
 
$base_i$: 
$i$번 마법을 사용해서 기본적으로 만들 수 있는 별가루의 개수이다.
 
$combo$: 연속으로 마법을 사용한 횟수이다. 예를 들어, 오늘 마법을 사용하기 전에 마법을 
$5$일 연속으로 사용했다면 
$combo = 5$이다.
 
$skill_i$: 
$i$번 마법의 숙련도이다. 예를 들어, 오늘 마법을 사용하기 전에 
$i$번 마법을 사용한 경험이 
$3$번 있으면 
$skill_i = 3$이다.
 
$C$와 
$s_i$는 상수이다.
스타의 초기 피로도는 
$0$이며, 
$i$번 마법을 사용할 때마다 스타의 피로도는 
$p_i$만큼 상승한다. 피로도가 
$100$을 초과하게 되면, 마법봉이 망가지고 이후에는 어떤 마법도 쓸 수 없게 된다. 동시에, 지금까지 만들었던 별가루도 못 쓰게 된다. 피로도는 휴식을 통해 줄일 수 있다. 휴식을 취하면 피로도가 
$R$만큼 줄어들지만, 연속으로 마법을 사용한 횟수는 
$0$이 된다. 피로도는 
$0$ 미만으로 내려가지 않으며, 만약 휴식으로 감소하는 피로도가 현재 피로도보다 크다면 피로도는 
$0$이 된다.

스타의 계획을 보고 
$N$일 동안 만들 수 있는 별가루의 총 개수를 계산해 보자.

입력
첫째 줄에는 
$N,K,C,R$ 이 공백을 사이에 두고 주어진다. 
$(1 \leq K \leq N \leq 100 \, 000;$ 
$1 \leq C \leq 100;$ 
$1 \leq R \leq 100)$ 

둘째 줄에는 
$base_1, \cdots , base_K$가 공백을 사이에 두고 주어진다. 
$(1 \leq base_i \leq 100 \, 000)$ 

셋째 줄에는 
$s_1, \cdots , s_K$가 공백을 사이에 두고 주어진다. 
$(1 \leq s_i \leq 100)$ 

넷째 줄에는 
$p_1, \cdots ,p_K$가 공백을 사이에 두고 주어진다. 
$(1 \leq p_i \leq 100)$ 

다섯째 줄부터 
$N$개의 줄에 걸쳐 스타가 
$i$번째 날에 사용하려고 계획한 마법의 번호 
$l_i \ (0 \leq l_i \leq K)$가 한 줄에 하나씩 주어진다. 
$l_i$가 
$0$이면 그날 하루는 휴식을 취한다는 뜻이다.

입력으로 주어지는 모든 수는 정수이다.

출력
 
$N$일 동안 만들 수 있는 별가루의 총 개수를 출력한다. 계획 중간에 마법봉이 망가진다면 -1을 출력한다.

예제 입력 1 
6 5 26 62
72 81 47 29 97
2 75 25 82 84
17 6 7 2 3
2
2
2
1
0
4
예제 출력 1 
723
예제 입력 2 
7 7 98 25
12 64 97 23 20 97 80
17 38 76 83 65 40 41
15 3 16 6 23 11 34
2
7
0
7
7
6
6
예제 출력 2 
-1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, C, R;
    cin >> N >> K >> C >> R;

    vector<long long> base(K+1), s(K+1);
    vector<int> p(K+1);
    for(int i=1;i<=K;i++) cin >> base[i];
    for(int i=1;i<=K;i++) cin >> s[i];
    for(int i=1;i<=K;i++) cin >> p[i];

    long long total = 0;
    int fatigue = 0;
    int combo = 0;
    vector<int> skill(K+1, 0);

    for(int day=0; day<N; day++){
        int l;
        cin >> l;

        if(l == 0){
            fatigue = max(0, fatigue - R);
            combo = 0;
        } else {
            __int128 num = base[l];
            num *= (100 + combo * C);
            num *= (100 + skill[l] * s[l]);
            long long delta = (long long)(num / 10000); 
            total += delta;

            fatigue += p[l];
            if(fatigue > 100){
                cout << -1 << "\n";
                return 0;
            }

            combo += 1;
            skill[l] += 1;
        }
    }

    cout << total << "\n";
    return 0;
}
