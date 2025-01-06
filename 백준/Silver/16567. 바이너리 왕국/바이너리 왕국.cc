/*
바이너리 왕국

시간 제한	메모리 제한
2 초	512 MB

문제
바이너리 왕국의 불쌍한 하인들은 매일 바이너리 길을 청소한다.
바이너리 길은 N개의 0 또는 1로 이루어진 수열이다.

0은 깨끗한 칸, 1은 더러운 칸을 의미한다.

그들은 "flip"이라는 기술만을 사용해서 청소를 한다. 이것은 연속된 더러운 칸을 깨끗하게 만드는 기술이다.
즉, 연속된 1을 모두 0으로 만든다.

바이너리 왕국의 악덕한 왕은 매일 하인들에게 M개의 시련을 내리는 것이 취미이다.
시련에는 2가지 종류가 있는데 다음과 같다.

- "0": 현재 길의 모든 칸을 깨끗하게 만들기 위한 "flip"의 최소 횟수를 하인들에게 크게 외치게 한다.
- "1 i": 바이너리 길의 i번째 칸을 더럽힌다. 단, 이미 더럽혀져 있다면 아무 일도 일어나지 않는다.

바이너리 왕국의 불쌍한 하인들의 슬픈 외침들을 출력하라.

입력
첫째 줄에 바이너리 길의 칸의 개수 N, 시련의 개수 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에 N개의 현재 바이너리 길의 상태가 주어진다.

그다음 M개의 줄에 걸쳐서 시련이 주어진다. 이때 0번 시련은 "0", 1번 시련은 "1 i"와 같이 주어진다. (1 ≤ i ≤ N)

출력
0번 시련이 주어졌을 때, 하인들의 외침을 개행으로 구분하여 출력하라.

예제 입력 1
5 9
0 0 0 0 0
0
1 4
0
1 4
0
1 2
0
1 3
0
예제 출력 1
0
1
1
2
1
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int cnt = 0;
    bool dirty = false;
    vector<int> binary(N);

    for (int i = 0; i < N; i++)
    {
        cin >> binary[i];
        if (binary[i] == 1 && !dirty)
        {
            cnt++;
            dirty = true;
        }
        else if (binary[i] == 0)
        {
            dirty = false;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a;
        if (a == 0)
        {
            cout << cnt << "\n";
            continue;
        }

        cin >> b;
        if (binary[b - 1] == 0)
        {
            if (b - 2 >= 0 && binary[b - 2] == 1)
                cnt--;
            if (b < N && binary[b] == 1)
                cnt--;
            binary[b - 1] = 1;
            cnt++;
        }
    }

    return 0;
}
