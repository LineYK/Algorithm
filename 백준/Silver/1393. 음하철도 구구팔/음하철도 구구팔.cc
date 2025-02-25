/*
음하철도 구구팔
 
시간 제한	메모리 제한
2 초	128 MB	

문제
최백준은 음하철도 구구팔에 탔다.

문제는 구구팔의 기장인 조교 김재홍이 반쯤 미쳐서 열차를 멈추지 않는다는 것이다. 
그래서 최백준은 달리고 있는 열차에서 뛰어내려야 한다.

그런데 뛰어내릴 때 정류장 까지 거리가 너무 멀면 마이 아플 수 있다.

그래서 철도가 정류장에 가장 많이 근접했을 때 뛰어내리고자 한다.

어디서 뛰어내려야 하는가?

입력
첫번째 줄에는 xs와 ys가 주어진다. 이는 정류장의 위치가 (xs, ys)임을 의미한다.

두번째 줄에는 xe, ye, dx, dy가 주어진다. 이는 현재 열차 위치가 (xe, ye)이고, 
열차가 1초마다 x가 증가하는 방향으로 dx만큼, y가 증가하는 방향으로 dy만큼 이동함을 의미한다

주어지는 모든 수는 -100이상, 100이하의 정수이다.

출력
최백준이 뛰어내릴 위치의 x좌표와 y좌표를 출력한다. 뛰어내릴 위치의 좌표가 항상 정수인 입력만 주어진다.

예제 입력 1 
5 2
2 1 2 4
예제 출력 1 
3 3
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int xs, ys, xe, ye, dx, dy;
    cin >> xs >> ys >> xe >> ye >> dx >> dy;

    if(dx == 0 && dy == 0){
        cout << xe << " " << ye;
        return 0;
    }
        
    double denominator = dx*dx + dy*dy;
    double t = - (dx * (xe - xs) + dy * (ye - ys)) / double(denominator);
    
    if(t < 0) t = 0;
    
    int x = round(xe + dx * t);
    int y = round(ye + dy * t);

    cout << x << " " << y;
    
    return 0;
}