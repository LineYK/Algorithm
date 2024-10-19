/*
Divide the Cash 다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초 (추가 시간 없음)	1024 MB	1026	866	825	85.139%
문제
The UCF Programming Team coaches schedule practices regularly in fall and spring (by the way, all UCF students are welcome to the practices). During summer, the majority of the team members are gone but the coaches know how to make sure the students don’t get “rusty”. The coaches usually give prize money and reward the team members based on how many problems they solve during summer. For example, let’s assume the coaches have $1,000 in prize money and there are three students. Let’s also assume the three students solve, respectively, 5, 8 and 7 problems, i.e., a total of 20 problems. So, the reward for one problem will be $50 ($1000/20) and the three team members will receive, respectively, $250, $400 and $350.

Given the total prize money and the number of problems each team member has solved, compute the reward for each student.

입력
The first input line contains two integers: n (1 ≤ n ≤ 30), indicating the number of team members and d (1 ≤ d ≤ 30,000), indicating the dollar amount to be divided among the students. Each of the next n input lines contains an integer (between 1 and 300, inclusive) indicating the number of problems a team member has solved. Assume that the input values are such that the reward for one problem will be an integer number of dollars.

출력
Print the pay, in dollars, for each team member (in the same order as they appear in the input).

예제 입력 1 
3 1000
5
8
7
예제 출력 1 
250
400
350
예제 입력 2 
1 500
10
예제 출력 2 
500
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    int sum = 0;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    for (int i = 0; i < n; i++) {
        cout << (v[i] * d) / sum << endl;
    }
        
    return 0;
}
