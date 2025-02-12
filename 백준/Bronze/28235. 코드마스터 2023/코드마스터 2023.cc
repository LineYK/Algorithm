/*
코드마스터 2023
 
시간 제한	메모리 제한	
1 초	1024 MB

문제
송도고등학교에서 주최하는 첫 중고등학생 대상 알고리즘 대회, "코드마스터 2023"이 열렸다!

이 대회가 중고등학생들에게 인기 있는 알고리즘 대회이자 오프라인 이벤트로서 자리매김할 수 있도록 운영진은 각고의 준비를 했다.

대회를 시작하며 다음 네 가지 구호에 맞춰 알맞은 응원을 하는 프로그램을 작성하여라.

구호 SONGDO에 대해 HIGHSCHOOL로 응원.
구호 CODE에 대해 MASTER로 응원.
구호 2023에 대해 0611로 응원.
구호 ALGORITHM에 대해 CONTEST로 응원.
입력
첫 번째 줄에 네 가지 구호 중 한 가지에 해당하는 문자열이 주어진다.

출력
주어진 구호에 맞춰 알맞은 응원에 해당하는 문자열을 출력한다.

예제 입력 1 
SONGDO
예제 출력 1 
HIGHSCHOOL
예제 입력 2 
CODE
예제 출력 2 
MASTER
노트
문자열의 대소문자를 구분하여야 함에 유의하라.
*/

#include <bits/stdc++.h>

using namespace std;

map<string, string> m = {
    {"SONGDO", "HIGHSCHOOL"},
    {"CODE", "MASTER"},
    {"2023", "0611"},
    {"ALGORITHM", "CONTEST"}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;

    cout << m[s] << "\n";
    
    return 0;
}