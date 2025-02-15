/*
심각한 소 태그
 
시간 제한 메모리 제한
1초 128MB	

문제
농부 존의 N(1 <= N <= 1000)마리의 소(편의상 1..N으로 번호가 매겨져 있음)가 진지한 소 꼬리표 게임을 하려고 합니다. 진지한 소 꼬리표에서 각 소는 목초지의 격자 점(-7500 <= X <= 7500, -7500 <= Y <= 7500)을 선택하여 모든 소 쌍 사이의 거리가 고유하도록 합니다.

소는 1번 소부터 시작하여 2번 소, 3번 소 순으로 차례대로 플레이합니다(소가 게임에 남아 있는 한). 소가 플레이할 차례가 되면 가장 가까운 곳에서 플레이 중인 소를 찾아 그 소에게 다가가 태그를 붙인 다음 원래 위치로 돌아갑니다. 소에게 태그가 붙으면 그 소는 게임에서 제외됩니다.

소가 한 마리만 남으면 게임이 종료되고 그 소가 승자로 선언됩니다.

농부 존은 이웃 농부들과 어떤 소가 이길지 내기를 하고 있으므로 승자를 미리 알고 싶습니다. 소들의 위치에 대한 설명을 읽고 승자를 결정하는 프로그램을 작성하시오.

입력
줄 1: 소의 수인 단일 정수 N이 입력됩니다.
2줄...N+1: 줄 i+1에는 소 i의 위치를 설명하는 두 개의 공백으로 구분된 정수가 들어 있습니다.
 

출력
1줄: 1줄: 이긴 소의 개수입니다.
예제 입력 1 
3
0 0
0 3
4 3
예제 출력 1 
3
힌트
소 1이 먼저 가서 가장 가까운 소인 소 2를 태그합니다. 소 2는 탈락하여 차례를 얻지 못합니다. 그런 다음 소 3이 유일하게 남은 소인 소 1을 태그합니다. 소 1이 마지막 남은 소이므로 이깁니다.
*/

#include <bits/stdc++.h>

using namespace std;

class Point {
    public : int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Point> cows(N + 1); 
    for (int i = 1; i <= N; ++i) {
        cin >> cows[i].x >> cows[i].y;
    }

    vector<vector<int>> sorted_list(N + 1);
    for (int i = 1; i <= N; ++i) {
        vector<pair<long long, int>> distances;
        for (int j = 1; j <= N; ++j) {
            if (j == i) continue;
            long long dx = cows[i].x - cows[j].x;
            long long dy = cows[i].y - cows[j].y;
            long long dist_sq = dx * dx + dy * dy;
            distances.emplace_back(dist_sq, j);
        }
        sort(distances.begin(), distances.end());
        for (auto& p : distances) {
            sorted_list[i].push_back(p.second);
        }
    }

    vector<bool> alive(N + 1, true);
    int remaining = N;
    int index = 0;

    while (remaining > 1) {
        int current_cow = index + 1; 
        if (alive[current_cow]) {
            for (int j : sorted_list[current_cow]) {
                if (alive[j]) {
                    alive[j] = false;
                    remaining--;
                    break;
                }
            }
        }
        index = (index + 1) % N;
    }

    for (int i = 1; i <= N; ++i) {
        if (alive[i]) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}