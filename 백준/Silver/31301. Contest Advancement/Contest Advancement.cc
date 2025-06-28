/*
대회 진행
 
시간 제한    메모리 제한
2 초    2048 MB

문제
당신은 지역 대회의 RCD입니다. 
대회가 막 끝났고, 이제 다음 단계의 대회에 진출할 팀을 결정해야 합니다. 
팀들은 고유한 순위로 정렬되어 있으며(동점이 없습니다). 
다음 단계에는 특정 학교에서 참가할 수 있는 팀 수에 제한이 있습니다. 
그러나 이 제한으로 인해 진출하는 팀 수가 부족할 경우, 
남은 자리는 제한을 초과한 학교의 팀으로 채워집니다. 
이 경우, 동일한 학교의 팀이 많이 진출하더라도 항상 순위가 높은 팀을 우선적으로 선택합니다.

순위 순으로 다음 대회에 진출하는 팀을 출력하세요.

입력
입력의 첫 번째 줄에는 세 개의 정수 n, k (1 \leq k < n \leq 10^5) 및 c (1 \leq c \leq n)가 포함됩니다. 
여기서 n은 대회에 참가하는 팀의 수, k는 진출하는 팀의 수, c는 특정 학교에서 진출할 수 있는 팀 수의 제한입니다.

다음 n개의 각 줄에는 두 정수 t와 s (1 \le t,s \le n)가 포함됩니다. 
각 줄은 팀을 설명하며, t는 팀의 고유 ID이고, s는 팀의 학교를 나타냅니다. 
모든 팀 ID는 서로 다릅니다. 팀은 순위 순으로 나열되며, 가장 높은 순위의 팀부터 시작합니다.

출력
k개의 줄을 출력합니다. 각 줄에는 팀의 ID를 나타내는 단일 정수를 출력합니다. 
진출 자격을 얻은 팀의 ID를 순위 순으로 나열합니다.

예제 입력 1 
10 7 3
3 9
1 9
4 9
5 9
9 7
2 7
6 7
7 7
8 5
10 5
예제 출력 1 
3
1
4
9
2
6
8
*/

#include <bits/stdc++.h>
using namespace std;

struct Team {
    int id;
    int school_id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, c;
    cin >> n >> k >> c;

    vector<Team> all_teams(n);
    for (int i = 0; i < n; ++i) {
        cin >> all_teams[i].id >> all_teams[i].school_id;
    }

    vector<bool> is_advancing(n, false);
    int advanced_count = 0;
    
    map<int, int> school_count;

    for (int i = 0; i < n; ++i) {
        if (advanced_count == k) break;

        if (school_count[all_teams[i].school_id] < c) {
            is_advancing[i] = true;         
            advanced_count++;               
            school_count[all_teams[i].school_id]++; 
        }
    }

    
    if (advanced_count < k) {
        for (int i = 0; i < n; ++i) {
            if (advanced_count == k) break;

            if (!is_advancing[i]) {
                is_advancing[i] = true;
                advanced_count++;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (is_advancing[i]) {
            cout << all_teams[i].id << "\n";
        }
    }

    return 0;
}