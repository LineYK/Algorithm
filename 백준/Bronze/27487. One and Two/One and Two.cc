/*
하나 및 둘

시간 제한 메모리 제한
1초 (추가 시간 없음) 1024MB (추가 메모리 없음)

문제
수열 a_1, a_2, \ldots, a_n이 주어집니다. a의 각 원소는 1 또는 2입니다.

다음 조건을 만족하는 정수 k가 존재하는지 구합니다.

- 1 \leq k \leq n-1, 그리고
- a_1 \cdot a_2 \cdot \ldots \cdot a_k = a_{k+1} \cdot a_{k+2} 점 \cdot \ldots \cdot a_n.
주어진 조건을 만족하는 k가 여러 개 존재하면 가장 작은 값을 출력합니다.

입력
각 테스트는 여러 개의 테스트 케이스를 포함합니다. 첫 번째 줄에는 테스트 케이스의 개수 t(1 \le t \le 100)가 들어 있습니다. 테스트 케이스에 대한 설명은 다음과 같습니다.

각 테스트 케이스의 첫 번째 줄에는 하나의 정수 n(2 \leq n \leq 1000)이 포함됩니다.

각 테스트 케이스의 두 번째 줄에는 정수 a_1, a_2, \ldots, a_n(1 \leq a_i \leq 2)이 포함됩니다.

출력
각 테스트 케이스에 대해 해당 k가 없으면 -1을 출력합니다.

그렇지 않으면 가능한 가장 작은 k를 출력합니다.

예제 입력 1
3
6
2 2 1 2 1 2
3
1 2 1
4
1 1 1 1
예제 출력 1
2
-1
1

첫 번째 테스트 케이스의 경우, k=2는 a_1 \cdot a_2 = a_3 \cdot a_4 \cdot a_5 \cdot a_6 = 4이므로 조건을 만족합니다. k=3도 주어진 조건을 만족하지만 가장 작은 값을 출력해야 합니다.
두 번째 테스트 케이스의 경우, a_1 \cdot a_2 \cdot \ldots \cdot a_k = a_{k+1}을 만족하는 k는 없습니다. \cdot a_{k+2} 점 \cdot \ldots \cdot a_n

세 번째 테스트 케이스의 경우 k=1, 2, 3이 주어진 조건을 만족하므로 답은 1입니다.

Translated with DeepL.com (free version)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // 전체 2의 개수를 센다.
        int totalTwos = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 2)
                totalTwos++;

        int leftTwos = 0;
        int answer = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == 2)
                leftTwos++;
            // 오른쪽 구간의 2의 개수는 전체에서 왼쪽 구간의 개수를 뺀 값
            int rightTwos = totalTwos - leftTwos;
            if (leftTwos == rightTwos)
            {
                answer = i + 1; // 인덱스 0부터 시작하므로 k = i+1
                break;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}