/*
고유 지수
 
시간 제한 메모리 제한
1 초 1024 MB

문제
문자 A..J는 각각 집합 [0..9]에서 다른 한 자리 숫자를 나타냅니다. 두 5자리 숫자의 몫에 대한 모든 해를 구합니다:

ABCDE/FGHIJ = 9
참고: 선행 0은 허용되며, 즉 F는 0일 수 있습니다.

입력
인쇄할 집합의 해를 지정하는 단일 정수 N을 입력합니다.

출력
ABCDE와 FGHIJ를 나타내는 두 정수를 공백을 사이에 두고 한 줄에 인쇄합니다. 수적으로 가장 작은 ABCDE 순서로 정렬된 해집합에서 N번째 해만 먼저 인쇄합니다.

예제 입력 1 
1
예제 출력 1 
57429 06381
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> sols;  

    for (int div = 0; div <= 99999; ++div) {
        int num = div * 9;         
        if (num > 99999) continue; 

        string s1 = to_string(num);
        string s2 = to_string(div);
        s1 = string(5 - s1.length(), '0') + s1;
        s2 = string(5 - s2.length(), '0') + s2;

        string both = s1 + s2;
        set<char> st(both.begin(), both.end());
        if (st.size() == 10) {
            sols.emplace_back(num, div);
        }
    }

    sort(sols.begin(), sols.end());

    if (N >= 1 && N <= (int)sols.size()) {
        auto [num, div] = sols[N-1];
        cout << setw(5) << setfill('0') << num
             << ' '
             << setw(5) << setfill('0') << div
             << "\n";
    }

    return 0;
}
