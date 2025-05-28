/*
서울사이버대학을 다니고
 
시간 제한	메모리 제한
1 초	512 MB	

문제
서울사이버대학을 다니고 나의 성공 시대 시작됐다

서울사이버대학을 다니고 나를 찾는 회사 많아졌다

서울사이버대학을 다니고 내 인생이 달라졌다

미래를 바꾸는 전략

서울사이버대학교



서울사이버대학교 로고송은 중독성 강한 멜로디로 매우 매우 유명하다. 빅데이터·AI센터에서 데이터 분석을 하던 노교수와 천교수는 어디선가 들려오는 로고송을 듣고 가장 많이 사용된 글자가 몇 번이나 등장하는지 궁금해졌다.

멜로디에 중독된 두 교수를 대신해서 가장 많이 사용된 글자가 몇 번 등장하는지를 출력하자.

입력
첫 번째 줄에 로고송의 길이 
$N$이 주어진다. 
$(1 \le N \le 10^5)$ 

두 번째 줄에 로고송이 한 줄의 문자열로 주어진다. 문자열은 서울사이버대학교 로고송의 영문 번역이 반복되는 형태로 주어지며, 알파벳 소문자와 띄어쓰기, 쉼표, 마침표로만 구성되어 있다. 줄이 띄어쓰기로 끝나는 경우는 주어지지 않는다.

출력
첫 번째 줄에 가장 많이 등장한 알파벳의 등장 횟수를 출력한다. (띄어쓰기, 쉼표, 마침표는 세지 않는다.)

예제 입력 1 
255
my era of success began with seoul cyber university, since attending seoul cyber university, more companies have been seeking me out, my life has changed since i went to seoul cyber university, the strategy that changes the future, seoul cyber university.
예제 출력 1 
34
알파벳 e가 34번 등장한다.

예제 입력 2 
1
m
예제 출력 2 
1
예제 입력 3 
51
my era of success began with seoul cyber university
예제 출력 3 
6
노트
로고송의 영문 번역은 "my era of success began with seoul cyber university, since attending seoul cyber university, more companies have been seeking me out, my life has changed since i went to seoul cyber university, the strategy that changes the future, seoul cyber university. "이다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    string logoSong;
    cin.ignore();
    getline(cin, logoSong);

    unordered_map<char, int> frequency;
    for (char c : logoSong) {
        if (isalpha(c)) {
            frequency[c]++;
        }
    }

    int maxFrequency = 0;
    for (const auto& entry : frequency) {
        maxFrequency = max(maxFrequency, entry.second);
    }

    cout << maxFrequency << '\n';
    
    return 0;
}