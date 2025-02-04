/*
나의 FIFA 팀 가치는?

시간 제한	메모리 제한
1 초	1024 MB

문제
넥슨의 FIFA ONLINE 4는 축구 경기 시뮬레이션을 생동감 있게 플레이할 수 있는 게임이다.
각 선수별로 포지션이 있으며, 선수별로 능력치와 선수 가치가 존재하여 경기에 영향을 미치게 된다.
또한 선발 선수와 후보 선수를 구분하여 선발 선수의 컨디션이 안 좋은 경우 후보 선수와 교체할 수도 있다.

FIFA ONLINE 4를 즐겨하는 주원이는 다음 과정대로 팀을 구성하면
K년 12월에 되었을 때 팀의 선발 선수 가치의 합은 얼마가 되어 있을지 궁금해 하였다.

팀은 총 11명으로, 포지션 번호는 1 이상 11 이하인 정수이다.
3월에 같은 포지션 중 선수 가치가 가장 높은 선수가 선발 선수가 된다.
선수 가치가 가장 높은 선수가 여러 명 있을 경우, 그 중 아무나 선발 선수로 선택한다.
포지션에 해당하는 선수가 없을 시, 해당 포지션을 공석으로 팀을 구성한다.
8월에 현재 팀에 있는 선발 선수의 선수 가치는 모두 1이 떨어진다. 선수 가치는 0보다 작아지지 않는다.
11월에 2의 조건대로 선발 선수를 재구성한다.
선수 N명의 포지션 번호와 선수 가치가 주어졌을 때,
1, 2, ..., K년이 될 때마다 매년 위 과정대로 새로운 팀을 구성한다.
K년 12월에 되었을 때 만든 팀의 선발 선수 가치의 합을 구하여라.

입력
첫 번째 줄에 선수의 수 N과 K가 공백으로 구분되어 주어진다. (0\leq N\leq 1\,000\,000; 1\leq K\leq 50\,000)

두 번째 줄부터 N개의 줄에 걸쳐 각 줄에 i번째 선수의 포지션 P_{i}, 선수 가치 W_{i}가 공백으로 구분되어 주어진다.
(1 \leq i \leq N; 1\leq P_{i}\leq 11; 1\leq W_{i}\leq 100\,000)

입력으로 주어지는 수는 모두 정수이다.

출력
K년 12월에 되었을 때 만든 팀의 선발 선수 가치의 합을 출력한다.

예제 입력 1
11 1
1 5
2 4
3 2
4 3
5 10
6 9
7 6
8 8
9 11
10 5
11 6
예제 출력 1
58
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> positions(12);

    for (int i = 0; i < N; ++i)
    {
        int P, W;
        cin >> P >> W;
        positions[P].push_back(W);
    }

    long long total = 0;

    for (int p = 1; p <= 11; ++p)
    {
        auto &players = positions[p];
        if (players.empty())
            continue;

        vector<int> W_list = players;
        vector<int> x_list(players.size(), 0);

        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < W_list.size(); ++i)
        {
            heap.emplace(W_list[i], i);
        }

        for (int year = 0; year < K; ++year)
        {
            bool selected = false;
            while (!heap.empty())
            {
                auto current = heap.top();
                heap.pop();

                int current_eff = current.first;
                int idx = current.second;

                if (current_eff != W_list[idx] - x_list[idx])
                {
                    continue;
                }

                x_list[idx]++;
                selected = true;

                int new_eff = W_list[idx] - x_list[idx];
                if (new_eff > 0)
                {
                    heap.emplace(new_eff, idx);
                }

                break;
            }
            if (!selected)
                break;
        }

        int max_eff = 0;
        for (int i = 0; i < W_list.size(); ++i)
        {
            int eff = W_list[i] - x_list[i];
            if (eff > max_eff)
            {
                max_eff = eff;
            }
        }
        total += max_eff;
    }

    cout << total << '\n';

    return 0;
}