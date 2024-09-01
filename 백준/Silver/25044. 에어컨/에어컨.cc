/*
에어컨
 
시간 제한   메모리 제한
1 초   1024 MB   

문제
대부분의 DGIST 기초학부 학생들은 기숙사에서 생활하고 있습니다. 
여름이 다가옴에 따라 자유롭게 온도를 설정할 수 있는 시원한 에어컨을 사용하게 될 예정입니다. 
안타깝게도 에어컨은 매일 15, 18, 21시 정각에 자동으로 꺼지게 설계되어 있습니다. 
더군다나 에어컨의 내장 시계가 고장이 나서 세 번째로 꺼질 때마다 에어컨의 시계는 K분간 멈추게 됩니다.

편안한 낮잠을 위해 정시에 맞춰 에어컨을 켜주는 기계를 만들어 둔 
정디지 양은 정확한 시간에 에어컨이 켜지지 않자 화가 나기 시작했습니다. 
정디지양이 회로이론 과제를 내주기 전에 여러분이 N일째의 에어컨이 꺼지는 시각을 예측해 전원을 켜는 기계를 만들어 
정디지양이 화를 내지 않도록 잘 다독여줍시다. (날짜는 0일 00시 00분부터 시작되며 에어컨은 켜져있는 상태입니다.)

입력
날짜를 의미하는 정수 
N과 지연되는 분을 의미하는 정수 
K가 공백을 사이에 두고 주어집니다. 
$(0 \le N \le 1,000, 0\le K < 60)$ 

출력
첫 줄에 N일째에 에어컨이 켜진 횟수 M을 출력합니다.

둘째 줄부터 M개의 줄에 걸쳐 에어컨이 꺼지는 시간을 hh:mm 형식으로 오름차순으로 출력합니다.

예제 입력 1 
0 0
예제 출력 1 
3
15:00
18:00
21:00

예제 입력 2 
1000 59
예제 출력 2 
3
02:00
05:00
23:59
*/

#include <bits/stdc++.h>

using namespace std;

string toTime(int x) {
    string s;
    int hour = (x / 60) % 24;
    int minute = x % 60;
    
    s = (hour < 10 ? "0" : "") + to_string(hour) + ":";
    s += (minute < 10 ? "0" : "") + to_string(minute);
    
    return s;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> stop = {180, 180, 1080};
    int count = 0;
    int startTime = 900;
    int today = n * 60 * 24;  
    int tomorrow = (n+1) * 60 * 24;
    vector<int> ans;
    
    while (startTime < tomorrow) {
        if (startTime >= today) {  
            ans.push_back(startTime);
        }

        startTime = startTime + stop[count % 3];
        if (count % 3 == 2) {  
            startTime += k; 
        }
        count++;
    }
    
    cout << ans.size() << endl;
    
    for (int i : ans) {
        cout << toTime(i) << endl;
    }
    
    return 0;
}