/*
만족도 점수

시간 제한	메모리 제한
2 초	512 MB

문제
테니스 동호회 회장은 매주 참가 회원들이 만족할 만 하도록 2대 2 복식 조들을 짜야 한다.
각 회원은 참여한 게임이 대등하게 펼쳐졌을 수록 만족도가 높다.
참가 회원들의 실력 점수는 0 이상 10이하의 정수로 주어진다고 가정할 때,
한 경기에 참여한 회원의 만족도 점수는 다음과 같이 표현된다.
1 -  ( |상대 팀의 실력 점수 평균 - 본인 팀의 실력 점수 평균| / 10)

이 점수는 최악의 경우 0, 최상의 경우 1점을 범위로 갖는다.

회장의 목표는 너무 불만족해 탈퇴하는 회원이 없도록 하는 것이다.
이를 위해 모든 회원들이 최소 1번은 참가하게 하고, 만족도 점수의 하한을 극대화 하고 싶다.

2개의 테니스 코트를 쓸 수 있고, 각 코트에서 한 게임씩만 할 수 있으며 8명의 회원이 참여한다고 하자.
목표에 맞게 조를 짰을 때, 만족도 점수의 하한을 구하는 프로그램을 작성하라.

입력
8명 회원의 실력 점수가 입력으로 주어진다. 점수는 공백으로 구분되어져 있다.

출력
첫째 줄에 만족도 점수의 하한을 출력한다.

정답이 정수 또는 소수점 한 자리의 실수로 표현할 수 있는 경우 소수점 첫째 자리까지, 두 자리의 실수로 표현할 수 있는 경우 소수점 둘째 자리까지 출력한다.

예제 입력 1
3 8 3 7 1 4 2 2
예제 출력 1
1.0
예제 입력 2
1 0 9 1 0 1 2 1
예제 출력 2
0.7
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> scores(8);  // 입력받은 실력 점수
vector<bool> used(8);   // 선수 사용 여부
double max_satisfaction = 0;

// 한 코트에서의 만족도 계산
double calculateCourtSatisfaction(vector<int>& court) {
    // court[0],court[1]이 한 팀, court[2],court[3]이 다른 팀
    double team1_avg = (court[0] + court[1]) / 2.0;
    double team2_avg = (court[2] + court[3]) / 2.0;
    double satisfaction = 1.0 - abs(team1_avg - team2_avg) / 10.0;
    return satisfaction;
}

// 한 코트의 모든 가능한 팀 조합에 대한 최소 만족도 계산
double findBestCourtArrangement(vector<int>& court) {
    double best_satisfaction = 0;
    vector<int> temp = court;
    
    // 4명을 2:2로 나누는 모든 경우의 수
    do {
        double curr_satisfaction = calculateCourtSatisfaction(temp);
        best_satisfaction = max(best_satisfaction, curr_satisfaction);
    } while (next_permutation(temp.begin(), temp.end()));
    
    return best_satisfaction;
}

void solve(int count, vector<int>& court1, vector<int>& court2) {
    if (count == 8) {  // 모든 선수가 배정됨
        if (court1.size() == 4 && court2.size() == 4) {
            double court1_satisfaction = findBestCourtArrangement(court1);
            double court2_satisfaction = findBestCourtArrangement(court2);
            double min_satisfaction = min(court1_satisfaction, court2_satisfaction);
            max_satisfaction = max(max_satisfaction, min_satisfaction);
        }
        return;
    }
    
    for (int i = 0; i < 8; i++) {
        if (!used[i]) {
            used[i] = true;
            
            if (court1.size() < 4) {
                court1.push_back(scores[i]);
                solve(count + 1, court1, court2);
                court1.pop_back();
            }
            
            if (court2.size() < 4) {
                court2.push_back(scores[i]);
                solve(count + 1, court1, court2);
                court2.pop_back();
            }
            
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    for (int i = 0; i < 8; i++) {
        cin >> scores[i];
    }
    
    vector<int> court1, court2;
    solve(0, court1, court2);
    
    // 출력 형식 지정
    cout << fixed;
    if (int(max_satisfaction * 10) == max_satisfaction * 10) {
        cout.precision(1);
    } else {
        cout.precision(2);
    }
    cout << max_satisfaction << "\n";
    
    return 0;
}