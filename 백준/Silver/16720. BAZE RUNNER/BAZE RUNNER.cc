/*
BAZE RUNNER

시간 제한	메모리 제한
1 초	256 MB

문제
제2차 BAZE RUNNER(Bit MAZE RUNNER) 대회에 참가하게 된 세영이는 이번에야말로 우승하겠다고 다짐한다.
BAZE RUNNER는 N×4짜리 미로에서 진행하고, 제일 왼쪽 위부터 시작해서 제일 오른쪽 아래로 도착하면 승리하는 게임이다.
미로의 제일 위 줄과 제일 아래 줄은 아무런 벽이 존재하지 않지만
그 사이에 있는 모든 줄들은 한 명이 지나갈만큼의 공간을 제외하고는 전부 벽으로 막혀 있다.
이제 참가자들은 단위 시간동안 다음의 두 가지 행동 중 하나를 할 수 있다.

1. 벽이 아닌 인접한 길로 이동
    - 미로의 제일 왼쪽, 오른쪽 부분은 벽으로 막혀 있다.
2. 내 아래 또는 위 줄의 벽들을 좌우로 한 칸 씩 회전
    - 만약 가장 왼쪽, 오른쪽 칸의 벽이 밀렸을 경우 반대편 끝에서 나온다.
이제 세영이가 우승하기 위해 도착까지 최소 몇 번의 행동을 해야 하는지 알려주는 프로그램을 작성하시오.

입력
첫 번째 줄에 미로의 크기 N(3 ≤ N ≤ 1000)이 주어진다.

다음 줄부터 N-2개의 줄에는 미로의 제일 위 줄과 제일 아래 줄을 제외한 각 줄의 정보가 주어진다.

줄은 총 0(길), 1(벽)로 이루어진 4개의 비트로 구성되어 있으며, 각 줄마다 오직 한 개의 길이 존재한다.

출력
첫 번째 줄에 세영이가 우승하기 위한 행동의 최솟값을 출력한다.

예제 입력 1
3
1011
예제 출력 1
5
예제 입력 2
6
1101
0111
1011
1101
예제 출력 2
11
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> freeCols;
    for (int i = 0; i < N - 2; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < 4; j++)
        {
            if (row[j] == '0')
            {
                freeCols.push_back(j);
                break;
            }
        }
    }

    int vertical = N - 1;
    int horizontal = 3;
    int ans = 1e9;

    for (int c = 0; c < 4; c++)
    {
        int rotationCost = 0;
        for (int a : freeCols)
        {
            int diff = abs(a - c);
            rotationCost += min(diff, 4 - diff);
        }
        int totalCost = vertical + horizontal + rotationCost;
        ans = min(ans, totalCost);
    }

    cout << ans << "\n";
    return 0;
}
