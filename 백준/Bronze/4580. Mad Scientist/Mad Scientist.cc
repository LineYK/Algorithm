/*
미친 과학자
 
시간 제한 메모리 제한
1초 128MB

문제
한 미친 과학자가 각각 n 단계로 이루어진 일련의 실험을 수행했습니다. 
각 단계 동안 측정이 이루어졌고, 그 결과 최대 k의 양의 정수가 나왔습니다. 
과학자는 개별 실험이 단조롭게 증가하도록, 
즉 각 측정이 적어도 그 이전의 모든 측정만큼 커지도록 설계되었다는 것을 알고 있었습니다. 

예를 들어, 다음은 n=13, k=6인 한 실험의 측정 시퀀스입니다:
1, 1, 2, 2, 2, 2, 2, 4, 5, 5, 5, 5, 6
n이 k보다 커야 하는 경우도 있었기 때문에 일반적으로 측정 시퀀스에는 반복되는 값이 많았습니다. 
화가 난 이 과학자는 데이터를 기록하는 다소 특이한 방법을 선택했습니다. 
과학자는 n개의 측정값을 각각 기록하는 대신 다음과 같이 정의된 k값의 시퀀스 P를 기록했습니다. 
1 ≤ j ≤ k에서 P(j)는 측정값이 j 이하인 위상의 수를 나타냅니다. 

예를 들어, 위 실험의 원래 측정값은 P 시퀀스로 기록되었습니다:
2, 7, 7, 8, 12, 13
1보다 작거나 같은 측정값이 두 개, 2보다 작거나 같은 측정값이 일곱 개, 
3보다 작거나 같은 측정값이 일곱 개 있었기 때문입니다.

안타깝게도 이 과학자는 결국 미쳐버렸고, 일련의 실험을 위해 이 P-수열을 기록한 노트를 남기고 떠났습니다. 
여러분의 임무는 실험의 원래 측정값을 복구하는 프로그램을 작성하는 것입니다.

입력
입력에는 한 줄에 하나씩 일련의 P-수열이 들어 있습니다. 
각 줄은 P-수열의 길이인 정수 k로 시작합니다. 그 다음에는 P-수열의 k 값이 이어집니다. 
입력의 끝은 숫자 0이 포함된 줄로 지정됩니다. 모든 원래 실험은 1 ≤ k < n ≤ 26으로 설계되었습니다.

출력
각 P-수열에 대해 원래 실험 측정값이 포함된 한 줄을 공백으로 구분하여 출력해야 합니다.

예제 입력 1 
6 2 7 7 8 12 13
1 4
3 4 4 5
3 0 4 5
5 2 2 4 7 7
0
예제 출력 1 
1 1 2 2 2 2 2 4 5 5 5 5 6
1 1 1 1
1 1 1 1 3
2 2 2 2 3
1 1 3 3 4 4 4
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    while (cin >> k)
    {
        if (k == 0)
            break;

        vector<int> p(k);
        for (int i = 0; i < k; i++)
            cin >> p[i];

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < p[i]; j++)
                    result.push_back(i + 1);
            }
            else
            {
                for (int j = p[i - 1]; j < p[i]; j++)
                    result.push_back(i + 1);
            }
        }

        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << "\n";
    }

    return 0;
}