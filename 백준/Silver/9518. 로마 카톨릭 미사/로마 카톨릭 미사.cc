/*
로마 카톨릭 미사 다국어

시간 제한	메모리 제한
1 초	128 MB

문제
로마 카톨릭 미사에서 가장 멋진 부분은 사람들이 서로 악수를 하면서 "평화가 함께하기를" 이라고 말하는 평화 의식이다.

성당에는 R개의 벤치가 한 행에 하나씩 있고, 각 벤치에는 총 S명이 앉을 수 있다.
성당의 좌석 배치는 크기가 R × S인 행렬로 나타낼 수 있고, 행렬의 각 원소는 사람이 있는지 없는지로 나타낼 수 있다.
모든 사람은 자신의 이웃과 악수를 한다고 가정한다.
이웃은 사람이 있는 칸과 인접한 칸 여덟개이다. (칸이 존재하지 않을 수도 있다)

상근이는 오늘도 늦잠을 자 미사에 늦었고, 가장 좋아하는 평화 의식 시간을 참여하기 위해 성당 입구까지 달려왔다.
상근이는 최대한 많은 사람과 악수를 할 수 있는 자리에 앉으려고 한다.
만약, 남은 자리가 없는 경우에는 상근이는 저녁 미사에 다시 참가하려고 한다.
또, 상근이보다 지각하는 사람은 없다.

상근이가 들어가기 바로 전 성당에 앉아있는 사람의 배치가 주어진다.
평화 의식이 진행되는 동안 총 몇 번의 악수가 행해지는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 R과 S가 주어진다. (1 ≤ R, S ≤ 50)

다음 R개 줄에는 S개의 문자가 주어진다. 이 R × S 개의 문자는 성당에 자리 배치를 나타낸다.
'.'은 빈 자리, 'o'는 사람이 앉아있는 자리이다.

출력
평화 의식에서 총 몇 번의 악수가 행해지는지 출력한다.

예제 입력 1
2 3
..o
o..
예제 출력 1
2
예제 입력 2
2 2
oo
oo
예제 출력 2
6
*/

#include <bits/stdc++.h>
using namespace std;

int R, S;
vector<vector<char>> church;

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int countHandshakes();
int findBestSeat();
bool isInside(int x, int y);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> S;
    church.resize(R, vector<char>(S));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cin >> church[i][j];
        }
    }

    int cnt = countHandshakes();
    int cnt2 = findBestSeat();

    cout << cnt + cnt2 << "\n";

    return 0;
}

bool isInside(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < S;
}

int countHandshakes()
{
    int total = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < S; j++)
        {
            if (church[i][j] != 'o')
                continue;
            for (int k = 0; k < 8; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (isInside(nx, ny) && church[nx][ny] == 'o')
                {
                    total++;
                }
            }
        }
    }
    return total / 2;
}

int findBestSeat()
{
    int maxHandshakes = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < S; j++)
        {
            if (church[i][j] == 'o')
                continue;

            int handshakes = 0;
            for (int k = 0; k < 8; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (isInside(nx, ny) && church[nx][ny] == 'o')
                {
                    handshakes++;
                }
            }
            maxHandshakes = max(maxHandshakes, handshakes);
        }
    }
    return maxHandshakes;
}
