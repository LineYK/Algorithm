/*
유클리드
 
시간 제한	메모리 제한
1 초	128 MB	

문제
유클리드는 자신의 공책에 다음과 같은 문제를 풀기 위한 복잡한 과정을 적어놓았다. 하지만, 컴퓨터를 이용하면 쉽게 구할 수 있다.

이차원 평면 위에 선분 AB와 점 C, 삼각형 DEF가 있다. 점 C는 선분 AB위에 있지 않다. 이때, 다음과 같은 점 G와 H를 찾아야 한다.

1. H는 점A에서 C로 뻗어가는 반직선 위에 있다. 

2. ABGH는 평행사변형이다.

3. 평행사변형 ABGH의 넓이는 삼각형 DEF의 넓이와 같다.



입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 12개의 실수로 이루어져 있다. 이 실수는 모두 소수점 3자리를 넘지 않는다.

AX AY BX BY CX CY DX DY EX EY FX FY

A의 좌표는 (AX,AY), B의 좌표는 (BX,BY)이고 나머지 점도 이와 같은 식이다. 점 A,B,C는 모두 겹치지 않으며, D,E,F도 마찬가지다. 모든 숫자는 -1000.0와 1000.0을 포함하는 구간에 있다. 입력의 마지막은 12개의 0.0으로 이루어져 있다.

출력
각각의 테스트 케이스에 대해서 4개의 실수를 출력한다. 점 G와 H의 좌표를 다음과 같은 형식으로 출력한다.

GX GY HX HY

G의 좌표는 (GX,GY), H의 좌표는 (HX,HY)이고, 모두 소수점 넷째자리에서 반올림해서 셋째자리까지 출력해야 한다. 각각의 숫자 사이에는 빈 칸을 출력한다.

예제 입력 1 
0 0 5 0 0 5 3 2 7 2 0 4
1.3 2.6 12.1 4.5 8.1 13.7 2.2 0.1 9.8 6.6 1.9 6.7
0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0
예제 출력 1 
5.000 0.800 0.000 0.800
13.756 7.204 2.956 5.304
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double cross(double ax, double ay, double bx, double by) {
    return ax * by - ay * bx;
}

double triangleArea(Point D, Point E, Point F) {
    double dx1 = E.x - D.x, dy1 = E.y - D.y;
    double dx2 = F.x - D.x, dy2 = F.y - D.y;
    return fabs(cross(dx1, dy1, dx2, dy2)) / 2.0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true) {
        double AX, AY, BX, BY, CX, CY, DX, DY, EX, EY, FX, FY;
        if(!(cin >> AX >> AY >> BX >> BY >> CX >> CY 
                >> DX >> DY >> EX >> EY >> FX >> FY))
            break;
        if(AX==0.0 && AY==0.0 && BX==0.0 && BY==0.0 && 
           CX==0.0 && CY==0.0 && DX==0.0 && DY==0.0 &&
           EX==0.0 && EY==0.0 && FX==0.0 && FY==0.0)
            break;
        
        Point A = {AX, AY}, B = {BX, BY}, C = {CX, CY};
        Point D = {DX, DY}, E = {EX, EY}, F = {FX, FY};
        
        double T = triangleArea(D, E, F);
        
        double ABx = B.x - A.x, ABy = B.y - A.y;
        double ACx = C.x - A.x, ACy = C.y - A.y;
        
        double baseCross = fabs(cross(ABx, ABy, ACx, ACy));
        
        double t = T / baseCross;
        
        Point H = {A.x + t * ACx, A.y + t * ACy};
        Point G = {B.x + (H.x - A.x), B.y + (H.y - A.y)};
        
        cout << fixed << setprecision(3)
             << G.x << " " << G.y << " " << H.x << " " << H.y << "\n";
    }
    
    return 0;
}