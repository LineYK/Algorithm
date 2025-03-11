/*
두 직선의 교차 여부
 
시간 제한	메모리 제한	
1 초	128 MB	

문제
두 개의 직선을 나타내는 4개의 점이 입력으로 주어질 때, 두 직선이 만나는지를 확인하는 프로그램을 작성하시오.

입력
입력의 첫 번째 줄에는 테스트 케이스의 개수 N이 주어진다. (N <= 10)

다음 N개의 줄에는 각각 8개의 정수 x1, y1, x2, y2, x3, y3, x4, y4가 주어진다. 이는 두 직선 (x1, y1)-(x2, y2)와 (x3, y3)-(x4, y4)를 나타낸다.

(x1, y1)과 (x2, y2)는 서로 다른 점이며, (x3, y3)와 (x4, y4)는 서로 다른 점임이 보장된다.

모든 x와 y는 [-1000, 1000] 범위 내의 정수이다.

출력
각각의 테스트 케이스에 대해, 다음과 같이 출력한다.

두 직선이 정확히 한 점에서 만난다면, POINT x y의 꼴로 출력한다. 이는 두 직선이 (x,y)에서 교차함을 의미한다. x와 y는 정확히 소숫점 아래 둘째 자리까지 출력한다.
두 직선이 만나지 않는다면, NONE을 출력한다.
두 직선이 무한히 많은 점에서 만난다면,  LINE을 출력한다.
원문에 있는 INTERSECTING LINES OUTPUT/END OF OUTPUT 등은 출력하지 않는다.

예제 입력 1 
5
0 0 4 4 0 4 4 0
5 0 7 6 1 0 2 3
5 0 7 6 3 -6 4 -3
2 0 2 27 1 5 18 5
0 3 4 0 1 2 2 5
예제 출력 1 
POINT 2.00 2.00
NONE
LINE
POINT 2.00 5.00
POINT 1.07 2.20
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Vector {
    double x, y;
    Vector(Point a, Point b) : x(b.x - a.x), y(b.y - a.y) {}
};

double cross(const Vector& a, const Vector& b) {
    return a.x * b.y - a.y * b.x;
}

int ccw(const Point& a, const Point& b, const Point& c) {
    Vector ab(a, b);
    Vector ac(a, c);
    double res = cross(ab, ac);
    if (res > 1e-9) return 1;  
    if (res < -1e-9) return -1; 
    return 0;                   
}

bool areSameLines(const Point& a, const Point& b, const Point& c, const Point& d) {
    return ccw(a, b, c) == 0 && ccw(a, b, d) == 0;
}

Point intersectionPoint(const Point& a, const Point& b, const Point& c, const Point& d) {
    double det = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
    if (abs(det) < 1e-9) {
        return Point(NAN, NAN); 
    }
    double t = ((c.x - a.x) * (d.y - c.y) - (c.y - a.y) * (d.x - c.x)) / det;
    return Point(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        
        Point a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
        
        if (areSameLines(a, b, c, d)) {
            cout << "LINE\n";
        } else {
            Point intersect = intersectionPoint(a, b, c, d);
            if (isnan(intersect.x)) {
                cout << "NONE\n";
            } else {
                cout << fixed << setprecision(2);
                cout << "POINT " << intersect.x << " " << intersect.y << "\n";
            }
        }
    }
    
    return 0;
}