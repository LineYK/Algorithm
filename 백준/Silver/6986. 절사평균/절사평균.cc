/*
절사평균
 
시간 제한	메모리 제한	
1 초	256 MB

문제
체조나 다이빙 등의 경기에서 일부 심판이 자기가 좋아하는 선수에게 높은 점수를, 
싫어하는 선수에게 낮은 점수를 주는 경우가 종종 있었다. 
따라서 심판들이 주는 점수의 평균점수를 선수에게 주게 되면 공정하지 않은 경우가 생길 수 있다. 
이를 방지하기 위하여 절사평균이나 보정평균을 사용한다. 
예를 들어 심사위원 일곱 명이 다음과 같이 점수를 주었다고 하자.

9.3, 9.5, 9.6, 9.8, 9.1, 5.0, 9.3

전체의 합이 61.6이 되므로 평균은 8.8이 된다. 
이 평균점수는 한 심판이 다른 심판에 비하여 아주 낮은 점수인 5.0을 주어서 나온 결과로, 
선수는 매우 불공정하다고 느낄 것이다.

위의 점수를 작은데서 큰 순서로 정렬하면 5.0, 9.1, 9.3, 9.3, 9.5, 9.6, 9.8 이 된다.

이때 절사평균(7, 2)는 정렬된 전체 점수 일곱 개 중 양쪽 끝에서 두 개씩을 제외하고 난 
9.3, 9.3, 9.5의 평균인 9.37이 된다(소수점이하 셋째 자리에서 반올림). 
또 보정평균(7, 2)는 정렬된 전체 점수 일곱 개 중 양쪽 끝에서 각각 두 개를, 
남은 점수 중 가장 가까운 것으로 교체한 9.3, 9.3, 9.3, 9.3, 9.5, 9.5, 9.5의 평균으로 9.39가 된다
(소수점이하 셋째 자리에서 반올림).

N개의 점수와 양쪽에서 제외하는 개수 K 값이 주어졌을 때 
절사평균(N, K)와 보정평균(N, K)를 계산하는 프로그램을 작성하시오.

입력
첫째 줄에 전체 점수의 개수 N과 제외되는 점수의 개수 K가 빈칸을 사이에 두고 주어진다. 
N은 3 이상 100,000 이하의 자연수이다. K는 0 이상 (N/2)-1 이하로 주어진다. 
그 다음 N줄에는 각 심판의 점수가 한 줄에 하나씩 주어진다. 
점수는 0 이상 10 이하의 실수로 소수점이하 첫째 자리까지 주어진다.

출력
첫째 줄에 절사평균(N, K)를, 
둘째 줄에 보정평균(N, K)를 각각 소수점이하 셋째 자리에서 반올림하여 둘째 자리까지 출력한다. 

예를 들어 결과값이 9.667인 경우 9.67로, 5인 경우 5.00으로, 5.5인 경우에는 5.50으로 출력한다.

예제 입력 1 
7 2
9.3
9.5
9.6
9.8
9.1
5.0
9.3
예제 출력 1 
9.37
9.39
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<double> scores(N);

    for (int i = 0; i < N; i++)
        cin >> scores[i];

    sort(scores.begin(), scores.end());

    double sum = 0;
    
    for (int i = K; i < N - K; i++)
        sum += scores[i];

    cout << fixed;
    cout.precision(2);

    cout << sum / (N- 2 * K) + 1e-13 << "\n";

    double avg = sum;

    for(int i = 0; i < K; i++)
        {
            avg += scores[K];
            avg += scores[N - K - 1];
        }

    cout << avg / N + 1e-13 << "\n";

    return 0;
}