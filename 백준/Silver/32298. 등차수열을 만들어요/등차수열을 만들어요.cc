/*
등차수열을 만들어요

시간 제한	메모리 제한
1 초	1024 MB

문제
구구단을 외우던 호반우는 2,000,000 이하의 소수가 아닌 양의 정수 N개를 골라
공차가 M인 등차수열을 만들 수 있을지 궁금해졌다.

아쉽게도 멀티태스킹에 약한 호반우를 위해 등차수열을 찾아주자.

입력
첫째 줄에 양의 정수 N과 M이 공백을 두고 주어진다.
(2 \leq N, M \leq 1\,000) 

출력
만약 조건을 만족하는 등차수열을 만들 수 없다면 첫째 줄에 -1을 출력한다.
그렇지 않다면 첫째 줄에 길이가 N이고 공차가 M인 등차수열을 순서대로 공백을 두고 출력한다.
가능한 방법이 여러 가지라면 그중 아무거나 출력한다.

예제 입력 1
2 3
예제 출력 1
1 4
예제 입력 2
4 7
예제 출력 2
1 8 15 22
*/

#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for (int init = 1; init <= 2000000; init++)
    {
        int cur = init;
        while (v.size() < N)
        {
            if (cur > 2000000 || isPrime(cur))
            {
                v.clear();
                break;
            }
            v.push_back(cur);
            cur += M;
        }
        if (v.size() == N)
        {
            break;
        }
    }

    if (v.size() != N)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
