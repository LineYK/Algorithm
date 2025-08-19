/*
MODSUM
 
시간 제한   메모리 제한
2 초 512 MB  
문제
이 작업에서 다음 함수 (f)와 (n)개의 매개변수가 주어집니다:
 [f(x_1, dots, x_n) = left(left(left(x_1 + x_2 + dots + x_nright)^4 + 2 times left(x_1 + x_2 + dots + x_n right)^2 right) mod {5} right) + 1] 
함수 (f)는 정수 값만을 인수로 받습니다. 귀하의 과제는 각 입력 (x_i)가 정수 값 (v_i)에서 (w_i) 사이의 값을 가질 때 (f)의 모든 값의 합을 계산하는 것입니다. 즉, 다음을 계산해야 합니다.
 [sum_{x_1 = v_1}^{w_1}sum_{x_2 = v_2}^{w_2} cdots sum_{x_n = v_n}^{w_1} f(x_1, dots, x_n)] 
예를 들어, (n = 3, v_1 = 2, w_1 = 3, v_2 = 10, w_2 = 12, v_3 = 17)이고 (w_3 = 17)이라면 결과는 19가 됩니다. 왜냐하면 (f(2, 10, 17) = 4, f(2, 11, 17) = 1, f(2, 12, 17) = 4, f(3, 10, 17) = 1, f(3, 11, 17) = 4)이고 (f(3, 12, 17) = 5)이기 때문입니다.
중요 참고 사항: 결과는 항상 1,000,000 미만일 것이라고 가정할 수 있습니다.
입력
프로그램은 표준 입력에서 데이터를 읽어야 합니다. 입력은 (n)으로 시작하며, 여기서 (1 ≤ n ≤ 1000)입니다. 이어서 (n)개의 숫자 쌍 (v_i)와 (w_i)가 주어지며, 각 숫자는 0부터 100 사이의 값을 가집니다. 각 쌍 (v_i)와 (w_i)에 대해 (v_i ≤ w_i)라고 가정할 수 있습니다.
출력
프로그램은 표준 출력에 필요한 합을 출력해야 합니다.
예제 입력 1 
3 2 3 10 12 17 17
예제 출력 1 
19
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin >> n)) return 0;
    vector<pair<int,int>> seg(n);
    for(int i=0;i<n;i++){
        int v,w; cin >> v >> w;
        seg[i] = {v,w};
    }

    vector<ll> counts(5,0);
    counts[0] = 1;

    for(int i=0;i<n;i++){
        int v = seg[i].first;
        int w = seg[i].second;
        vector<ll> c(5,0);
        for(int t=0;t<5;t++){
            int vm = ((v%5)+5)%5;
            int add = (t - vm + 5) % 5;
            int first = v + add;
            if(first > w) c[t] = 0;
            else c[t] = (w - first) / 5 + 1;
        }
        vector<ll> nc(5,0);
        for(int r=0;r<5;r++){
            ll s = 0;
            for(int t=0;t<5;t++){
                int prev = (r - t) % 5;
                if(prev < 0) prev += 5;
                s += counts[prev] * c[t];
            }
            nc[r] = s;
        }
        counts.swap(nc);
    }

    auto modpow = [](int a, int e, int mod)->int{
        long long res = 1, base = a % mod;
        while(e){
            if(e&1) res = (res * base) % mod;
            base = (base * base) % mod;
            e >>= 1;
        }
        return (int)res;
    };

    ll ans = 0;
    for(int r=0;r<5;r++){
        int r2 = (r * r) % 5;
        int r4 = (r2 * r2) % 5;
        int fv = (r4 + 2 * r2) % 5;
        fv = fv + 1;
        ans += counts[r] * fv;
    }

    cout << ans << "\n";
    return 0;
}
