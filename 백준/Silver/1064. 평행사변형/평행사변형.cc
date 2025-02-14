/*
평행사변형
 
시간 제한	메모리 제한
2 초	128 MB	

문제
평행사변형은 평행한 두 변을 가진 사각형이다. 
세 개의 서로 다른 점이 주어진다. A(xA,yA), B(xB,yB), C(xC,yC)

이때, 적절히 점 D를 찾아서 네 점으로 평행사변형을 만들면 된다. 
이때, D가 여러 개 나올 수도 있다.

만들어진 모든 사각형 중 가장 큰 둘레 길이와 가장 작은 둘레 길이의 차이를 출력하는 프로그램을 작성하시오. 
만약 만들 수 있는 평행사변형이 없다면 -1을 출력한다.

입력
첫째 줄에 xA yA xB yB xC yC가 주어진다. 
모두 절댓값이 5000보다 작거나 같은 정수이다.

출력
첫째 줄에 문제의 정답을 출력한다. 
절대/상대 오차는 10-9까지 허용한다.

예제 입력 1 
0 0 0 1 1 0
예제 출력 1 
0.8284271247461898
예제 입력 2 
0 0 4 0 0 3
예제 출력 2 
4.0
예제 입력 3 
0 0 1 0 47 0
예제 출력 3 
-1.0
예제 입력 4 
1 2 3 4 8 7
예제 출력 4 
11.547796284592874
예제 입력 5 
2 -1 -7 2 -1 0
예제 출력 5 
-1.0
*/

#include <bits/stdc++.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;

    int area_twice = (xB - xA) * (yC - yA) - (yB - yA) * (xC - xA);
    if (area_twice == 0) {
        cout << "-1.0\n";
        return 0;
    }

    double AB = distance(xA, yA, xB, yB);
    double BC = distance(xB, yB, xC, yC);
    double AC = distance(xA, yA, xC, yC);

    double sum1 = AB + AC;
    double sum2 = AB + BC;
    double sum3 = BC + AC;

    double max_sum = max({sum1, sum2, sum3});
    double min_sum = min({sum1, sum2, sum3});

    double diff = (max_sum - min_sum) * 2;

    cout << fixed << setprecision(15) << diff << '\n';

    return 0;
}