/*
성적표
 
시간 제한	메모리 제한
1 초	256 MB

문제
동하는 이번 학기에도 F 학점을 받아 학사경고를 받았다. 더 이상 학사경고를 받지 않기 위해 동하는 공부를 하기로 결심했다.

동하는 공부를 얼만큼 하면 얼만큼 성적이 나오는지 궁금했다. 그래서 동하는 N명의 학생들에 대해 공부시간과 그에 따른 시험점수를 조사했다.

동하는 i번째 학생은 xi시간의 공부를 했고, yi점의 점수를 받았다는 사실을 알았다.

이 데이터로부터 공부를 x시간 했으면 시험 성적은 f(x) = ax + b일 것이라고 추정하려 한다. 동하를 위해 a와 b를 구해주자.

공부시간에 따른 시험성적을 예측하는 함수 f(x)는, 데이터 (xi, yi)에 대해, f(xi)와 yi의 차가 작아야 할 것이다. (I = 1, 2, 3, …, N)

이 개념을 수학적으로 형식화한 것이 RSS(Residual Sum of Squares)이다. RSS가 작으면 예측모형이 데이터에 잘 맞는 것이라고 할 수 있다.

 
\[\text{RSS} = \sum_{i=1}^{n}{(y_i - f(x_i))^2}\] 

100이하의 모든 양의 정수 a와 b중, RSS를 최소화하는 a와 b를 구하여라. 오버플로우에 주의하여라.

입력
첫 번째 줄에는 데이터의 수 N이 주어진다. (2 ≤ N ≤ 100)

두 번째 줄부터 N+1 번째 줄까지, 각 줄에는 i번 학생의 공부시간 xi와 시험점수 yi가 순서대로 주어진다. (1 ≤ xi, yi ≤ 1000, xi와 yi는 정수)

출력
RSS가 최소인 a와 b를 한 줄에 공백으로 구분하여 출력하여라.

RSS가 최소인 쌍 (a, b)가 여러 개인 경우는 입력으로 주어지지 않는다.

예제 입력 1 
4
1 2
2 3
3 4
4 5
예제 출력 1 
1 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    long long a = 0, b = 0;
    long long min_rss = LLONG_MAX;

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            long long rss = 0;
            for (int k = 0; k < n; k++)
            {
                rss += pow(v[k].second - (i * v[k].first + j), 2);
            }

            if (rss < min_rss)
            {
                min_rss = rss;
                a = i;
                b = j;
            }
        }
    }

    cout << a << " " << b;

    return 0;
}