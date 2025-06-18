/*
풋볼 득점
 
시간 제한    메모리 제한
1 초    1024 MB
문제
미국 프로 축구에서 점수를 얻을 수 있는 방법은 다섯 가지입니다:

터치다운 - 6점  
필드 골 - 3점  
세이프티 - 2점  
터치다운 후  
1점 (필드 골 또는 세이프티) - 일반적으로 “포인트 애프터”라고 불림  
2점 (터치다운) - 일반적으로 “투 포인트 컨버전”이라고 불림  
(https://operations.nfl.com/the-rules/nfl-video-rulebook/scoring-plays/)

두 경쟁 팀의 박스 스코어 값을 주어졌을 때, 각 팀의 총 점수를 계산하세요.

입력
두 줄의 입력 데이터가 있으며, 각 줄에는 공백으로 구분된 5개의 비음수 정수 T, F, S, P, C가 포함되어 있습니다. 이 값들은 각각 터치다운, 필드 골, 세이프티, 터치다운 후 포인트, 터치다운 후 2점 컨버전의 수를 나타냅니다. (0 ≤ T ≤ 10), (0 ≤ F ≤ 10), (0 ≤ S ≤ 10), (0 ≤ (P+C) ≤ T). 첫 번째 줄은 방문 팀의 박스 스코어를, 두 번째 줄은 홈 팀의 박스 스코어를 나타냅니다.

출력
단일 출력 행은 방문 팀의 점수와 홈 팀의 점수를 각각 공백으로 구분한 두 개의 정수로 구성됩니다.

예제 입력 1 
1 3 0 0 1
3 1 1 1 1
예제 출력 1 
17 26
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, F, S, P, C;
    int visiting_score = 0, home_score = 0;
    cin >> T >> F >> S >> P >> C;
    visiting_score = T * 6 + F * 3 + S * 2 + P + C * 2;

    cin >> T >> F >> S >> P >> C;
    home_score = T * 6 + F * 3 + S * 2 + P + C * 2;

    cout << visiting_score << " " << home_score << "\n";
    return 0;
}
