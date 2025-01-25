/*
프레임
 
시간 제한 메모리 제한
5초 256MB

문제
가운데 (X - 2)×(Y - 2) 직사각형이 잘린 X×Y 직사각형을 생각해 봅시다. 
이 그림을 X×Y 크기의 프레임이라고 부르겠습니다. 그림 1은 5×6 프레임을 보여줍니다.

크기가 A×1인 타일이 무제한으로 있다고 가정해 봅시다. 
이 타일을 사용하여 X×Y 크기의 프레임을 완전히 포장할 수 있는지(타일을 90도 회전할 수 있는지) 
다음과 같은 문제를 고려합니다. 
예를 들어 그림 1의 프레임 5×6은 3×1 크기의 타일로 완전히 포장할 수 있지만(한 가지 방법은 그림 2에 나와 있음), 
4×1 크기의 타일로는 포장할 수 없습니다.

입력
첫 번째 입력 줄에는 2개의 정수인 X와 Y(3 ≤ X ≤ 10^6, 3 ≤ Y ≤ 10^6)가 들어 있습니다. 
두 번째 줄에는 분석할 타일 유형 수인 정수 N이 포함됩니다(1 ≤ N ≤ 1000). 
다음 N 줄에는 각각 10^6을 초과하지 않는 정수가 하나씩 포함됩니다. 
입력 파일의 (k+2)번째 줄에 있는 정수를 AK로 지정합니다.

출력
목표는 N개의 줄을 출력하는 것이며, 
여기서 K번째 줄에는 타일 AK × 1로 X × Y 크기의 프레임을 타일링할 수 있는 경우 “YES”라는 단어가, 
그렇지 않은 경우 “NO”라는 단어가 포함되어야 합니다.

예제 입력 1 
5 6
2
3
4
예제 출력 1 
YES
NO
*/

#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y, int a)
{
    if (a == 2) return true;
    if (x % a == 0 && (y-2) % a == 0) return true;
    if((x-2) % a == 0 && y % a == 0) return true;
    if (x % a == 1 && y % a == 1) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (check(x, y, a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}