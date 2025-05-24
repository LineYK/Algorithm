/*
SHOP 
 
시간 제한 메모리 제한
2 초 512 MB

문제
아마드는 시장에서 일하는 상점 주인입니다. 손님이 쇼핑 비용을 지불하면 거스름돈을 돌려줘야 합니다. 아마드는 항상 (가능하면) 가장 높은 지폐로 지불하기를 원합니다. 아마드를 돕는 프로그램을 작성하시오.

입력
첫 번째 줄에는 테스트 케이스의 수인 T가 들어 있습니다(0 < T < 100). 각 테스트 케이스에는 두 줄이 있습니다. 첫 번째 줄은 아마드가 고객에게 지불해야 하는 금액 M(1 ≤ M ≤ 1000000)입니다. 두 번째 줄에는 m1:a1,...,mi:ai,mn:an(1 ≤ m ≤ 1000000)이 있으며, mi는 지폐이고 ai는 각 mi에 대해 그가 가진 지폐의 수입니다.

출력
아마드가 고객에게 갚아야 하는 지폐(내림차순으로 정렬)를 인쇄합니다.

예제 입력 1 
3
235
5:10,10:6,20:4,50:3
370
10:4,5:20,40:4,70:3,100:2,50:5
172
10:4,5:20,40:4,70:3,100:2,50:5
예제 출력 1 
Customer1:
50 3
20 4
5 1
Customer2:
100 2
70 2
10 3
Customer3:
Impossible
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        long long M;
        cin >> M;
        string line;
        cin >> line;

        vector<pair<long long,long long>> bills;
        {
            stringstream ss(line);
            string token;
            while (getline(ss, token, ',')) {
                auto pos = token.find(':');
                long long m = stoll(token.substr(0, pos));
                long long a = stoll(token.substr(pos+1));
                bills.emplace_back(m, a);
            }
        }

        sort(bills.begin(), bills.end(), [](auto &A, auto &B){
            return A.first > B.first;
        });

        long long remain = M;
        vector<pair<long long,long long>> give; 
        for(auto &b : bills){
            long long value = b.first, cnt = b.second;
            if (remain <= 0) break;
            long long use = min(cnt, remain / value);
            if (use > 0) {
                give.emplace_back(value, use);
                remain -= use * value;
            }
        }

        cout << "Customer" << tc << ":\n";
        if (remain == 0) {
            for(auto &p : give){
                cout << p.first << " " << p.second << "\n";
            }
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
