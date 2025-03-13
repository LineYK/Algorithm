/*
장난감 쇼핑 
 
시간 제한 메모리 제한	
1초 128MB	

문제
베시는 장난감을 사고 싶어요. 베시는 몇 년 동안 용돈을 모아서 엄청나게 많은 돈을 모았습니다. 하지만 베시는 매우 검소하고 현금으로 최대한의 가치를 얻고 싶어 합니다. 실제로 그녀는 소 장난감 궁전에서 제공하는 N(3 <= N <= 25,000)의 장난감을 정확히 세 가지만 사기로 결정했습니다.

장난감 i는 베시에게 기쁨의 마이크로 번들 J_i(0 <= J_i <= 1,000,000)를 가져다주며 가격은 P_i(0 <= P_i <= 100,000,000)입니다. 베시는 자신이 선택한 장난감 세 개를 모두 살 수 있는 충분한 돈을 가지고 있습니다.

베시는 자신이 선택한 장난감 세 개에 대한 행복 지수(기쁨을 가격으로 나눈 값인 J_i/P_i로 계산)의 합을 최대화하고자 합니다. 베시가 어떤 장난감을 사야 할지 결정하도록 도와주세요. 답은 반드시 고유합니다.

Bovine Plaything Palace에서 베시에게 6가지 장난감을 제공한다고 가정합니다:

        i    Joy       Price       Happy-Frugal Metric
        -    ---       -----       -------------------
        1      0        521               0.00000
        2    442        210               2.10476...
        3    119        100               1.19000
        4    120        108               1.11111...
        5    619        744               0.83198...
        6     48         10               4.80000

베시는 장난감 6(HFM = 4.80), 장난감 2(HFM = 2.10), 장난감 3(HFM = 1.19)을 선택합니다.

입력
라인 1: 단일 정수입니다: N
2줄..N+1: i+1 줄에는 공백으로 구분된 두 개의 정수가 포함됩니다: J_i와 P_i
 

출력
1줄: 베시가 지불해야 할 총 가격입니다.
줄 2...4: 베시가 사야 하는 장난감의 1 기반 지수를 행복-검소한 지표에 따라 내림차순으로 한 줄에 하나씩 정렬합니다.

예제 입력 1 
6
0 521
442 210
119 100
120 108
619 744
48 10
예제 출력 1 
320
6
2
3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<tuple<double, int, int, int>> toys;
    
    for (int i = 1; i <= n; i++) {
        int joy, price;
        cin >> joy >> price;
        
        double happiness_metric = 0.0;
        if (price > 0) {
            happiness_metric = (double)joy / price;
        }
        
        toys.push_back({happiness_metric, i, joy, price});
    }
    
    sort(toys.rbegin(), toys.rend());
    
    long long total_price = 0;
    vector<int> selected_toys;
    
    for (int i = 0; i < 3; i++) {
        auto [_, idx, __, price] = toys[i];
        total_price += price;
        selected_toys.push_back(idx);
    }
    
    cout << total_price << "\n";
    for (int idx : selected_toys) {
        cout << idx << "\n";
    }
    
    return 0;
}