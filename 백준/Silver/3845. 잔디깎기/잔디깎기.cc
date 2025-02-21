/*
잔디깎기 
 
시간 제한	메모리 제한
1 초	128 MB	

문제
국제대학축구대회(ICSC)은 손질이 잘 된 직사각형 경기장으로 유명하다. 
ICSC 경기장의 잔디밭은 언제나 100미터 길이에 폭이 75미터이다. 
잔디깎기는 매주 특별한 잔디깎er에 의해 이뤄지는데, 항상 같은 전략을 사용한다:

필드의 가로와 세로에 평행하게 여러 개의 길를 만들어 길를 따라 이동하며 잔디를 깎는다.

ICSC는 새로운 잔디깎er, 수진이를 고용하였다. 
수진이는 매우 혼돈을 좋아하여, 필드를 순서대로 덮어나가는 것보다 랜덤으로 길을 정해 시작하는 것을 좋아한다. 
그러나 그녀는 제대로 일을 하지 않아 ICSC로부터 해고되는 것이 두려워져 당신에게 도움을 요청하였다.

당신은 그녀를 도와 필드의 잔디가 완벽히 깎였는지를 확인하는 프로그램을 만들어라. 
잔디가 완벽히 깎인 상태란 모든 부분의 필드가 가로로도 세로로도 최소 한 번 이상 깎인 상태를 의미한다.

입력
각각의 테스트 케이스는 3 라인을 포함하고 있다.

첫째 줄에 두 정수 nx (0 < nx < 1 000) 와 ny (0 < ny < 1 000), 그리고 잔디 깎는 기계의 폭 w (0 < w ≤ 50)가 주어진다.

둘째 줄에는 가로에 평행하게 깎는 길들의 실수 좌표 xi (0 ≤ xi ≤ 75)가 nx개 주어진다.

셋째 줄에는 세로에 평행하게 깎는 길들의 실수 좌표 yi (0 ≤ yi ≤ 100)가 ny개 주어진다.

테스트 케이스의 마지막에는 0 0 0.0이 주어진다.

실수 w, xi, yi는 10진법 소숫점 7째 자리까지 주어지며, 잔디를 깎을 때, 깎이는 범위에 가장자리도 포함된다.

출력
수진이가 잔디를 완벽히 깎았다면 YES, 아니라면 NO를 출력한다.

예제 입력 1 
8 11 10.0
0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0
0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0 80.0 90.0 100.0
8 10 10.0
0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0
0.0 10.0 30.0 40.0 50.0 60.0 70.0 80.0 90.0 100.0
4 5 20.0
70.0 10.0 30.0 50.0
30.0 10.0 90.0 50.0 70.0
4 5 20.0
60.0 10.0 30.0 50.0
30.0 10.0 90.0 50.0 70.0
0 0 0.0
예제 출력 1 
YES
NO
YES
NO
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nx, ny;
    double w;

    while (true)
    {
        cin >> nx >> ny >> w;
        if (nx == 0 && ny == 0 && w == 0.0)
        {
            break;
        }

        vector<double> x(nx), y(ny);
        for (int i = 0; i < nx; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < ny; i++)
        {
            cin >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        bool isPerfect = true;
        for (int i = 0; i < nx; i++)
        {
            if (i == 0)
            {
                if (x[i] - w / 2 > 0)
                {
                    isPerfect = false;
                    break;
                }
            }
            else
            {
                if (x[i] - x[i - 1] > w)
                {
                    isPerfect = false;
                    break;
                }
            }
        }

        if (isPerfect)
        {
            if (75 - x[nx - 1] - w / 2 > 0)
            {
                isPerfect = false;
            }
        }

        for (int i = 0; i < ny; i++)
        {
            if (i == 0)
            {
                if (y[i] - w / 2 > 0)
                {
                    isPerfect = false;
                    break;
                }
            }
            else
            {
                if (y[i] - y[i - 1] > w)
                {
                    isPerfect = false;
                    break;
                }
            }
        }

        if (isPerfect)
        {
            if (100 - y[ny - 1] - w / 2 > 0)
            {
                isPerfect = false;
            }
        }

        cout << (isPerfect ? "YES" : "NO") << "\n";
        
    }
    
    return 0;
}