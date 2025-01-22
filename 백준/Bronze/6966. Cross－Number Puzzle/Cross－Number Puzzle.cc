/*
교차 숫자 퍼즐
 
시간 제한 메모리 제한
1초 128MB

문제
인쇄할 프로그램을 작성하세요:
1. 1,000에서 9,999 사이의 완전수.완전수는 양의 정수로, 적절한 제수의 합과 같습니다. 
고유 제수는 숫자 자체보다 작은 모든 제수를 말합니다. 예를 들어, 6은 1 + 2 + 3 = 6이므로 완전수입니다.

2. 100에서 999 사이의 모든 정수는 자릿수의 세제곱의 합과 같습니다.

입력
입력이 없습니다.

출력
첫째 줄엔 1000이상 9999이하인 모든 완전수를 출력하세요.
둘째 줄엔 100이상 999이하인 자연수 중 각 자리 수의 세제곱의 합이 그 수와 같은 수들을 출력하세요.
둘 다 오름차순으로 공백으로 구분해서 출력하세요.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1000; i <= 9999; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            cout << i << " ";
        }
    }

    cout << "\n";

    for (int i = 100; i <= 999; i++)
    {
        int sum = 0;
        int temp = i;
        while (temp)
        {
            sum += pow(temp % 10, 3);
            temp /= 10;
        }
        if (sum == i)
        {
            cout << i << " ";
        }
    }


    return 0;
}