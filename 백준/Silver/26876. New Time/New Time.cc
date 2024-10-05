/*
New Time 다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	1024 MB	185	125	100	66.667%
문제
Nikolay has a digital clock that displays time in 24-hour format, showing two integers: hours (from 
$00$ to 
$23$) and minutes (from 
$00$ to 
$59$). For example, the clock can show 00:00, 18:42, or 23:59.

The clock has two buttons that can be used for manual adjustment:

Button A sets the clock forward by 
$1$ minute. For example, 05:33 becomes 05:34, 16:59 becomes 17:00, and 23:59 becomes 00:00.
Button B sets the clock forward by 
$1$ hour. For example, 01:42 becomes 02:42, and 23:14 becomes 00:14.
Nikolay has noticed that the time on his clock does not look right. He wants to adjust the clock to the correct time by pressing the buttons as few times as possible.

Find the smallest number of button presses needed to adjust the clock.

입력
The first line contains the time shown on the clock in the hh:mm format (
$00 \le \mathtt{hh} \le 23$; 
$00 \le \mathtt{mm} \le 59$).

The second line contains the correct time in the same format.

출력
Print a single integer --- the smallest number of button presses Nikolay needs to adjust the time on his clock.

예제 입력 1 
11:57
12:00
예제 출력 1 
3
예제 입력 2 
09:09
21:21
예제 출력 2 
24
예제 입력 3 
19:44
08:50
예제 출력 3 
19
노트
In the first example test, Nikolay can adjust the time by pressing button A three times.

In the second example test, Nikolay should press button A and button B 
$12$ times each.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string before, after;
    cin >> before >> after;

    int beforeMin = stoi(before.substr(3));
    int afterMin = stoi(after.substr(3));
    int beforeHour = stoi(before.substr(0, 2));
    int afterHour = stoi(after.substr(0, 2));

    int answer = 0;
    while (beforeMin != afterMin) {
        beforeMin++;
        answer++;
        if (beforeMin == 60) {
            beforeMin -= 60;
            beforeHour++;
            if (beforeHour == 24) {
                beforeHour -= 24;
            }
        }
    }
    while (beforeHour != afterHour) {
        beforeHour++;
        answer++;
        if (beforeHour == 24) {
            beforeHour -= 24;
        }
    }
    cout << answer << endl;

    return 0;
}