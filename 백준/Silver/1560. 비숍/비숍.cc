/*
비숍
 
시간 제한	메모리 제한
2 초	128 MB	

문제
인간과 컴퓨터의 체스대결은 1997년부터 시작되었다.

지난 1997년 러시아의 체스마스터 게리 카스파로프(Garry Kasparov)가 IBM 수퍼컴퓨터 '딥블루(Deep Blue)'와의 대결에서 패한 후, 2002년 10월에는 세계 체스챔피언인 러시아의 블라디미르 크람니크(Vladimir Kramnik)가 독일의 수퍼컴퓨터 '딥프리츠(Deep Fritz)'와 두뇌대결을 벌여 무승부를 기록했다.

2003년 1월~2월 슈퍼컴퓨터와의 체스게임에 재도전한 게리 카스파로프(Garry Kasparov)는 이스라엘에서 만든 슈퍼컴퓨터 '딥주니어(Deep Junior)'와 6차례 경기를 펼쳐 '3대3'으로 무승부를 이루었다.

2003년 11월에도 카스파로프는 가상현실 프로그램개발 전문업체인 X3D 테크놀로지社가 개발한 컴퓨터 체스프로그램 'X3D 프리츠'와 체스경기를 펼쳤으나, 1승2무1패의 무승부로 끝났다.

하지만, 2008년 6월 모든 체스프로그램을 이기고 등장한 사람이 한국에 있었으니, 그 이름은 바로 "오세준" 이였다. 오세준은 컴퓨터와 사람을 모두 이겼으므로 더 이상 대적할 상대가 없었다.

세준이는 따분해진 나머지 갑자기 체스 판의 크기를 마음대로 조정하는 체스 판을 만들었다.

세준이는 N*N 크기의 체스 판에 과연 몇 개의 비숍 (BISHOP)을 세울 수 있는지 궁금해 졌다.

비숍 (BISHOP)은 자신의 위치에서 대각선 왼쪽 위, 대각선 왼쪽 아래, 대각선 오른쪽 위, 대각선 오른쪽 아래 () 이렇게 4방향으로 움직일 수 있는 말이다.

체스판의 크기가 주어졌을 때, 서로 잡아먹지 않게 최대로 비숍을 몇 개를 놓을 수 있는지 구하는 프로그램을 작성하시오.

입력
체스판의 크기 N이 주어진다. N은 10진수로 70자리 이하인 자연수이다.

출력
최대로 비숍을 몇 개 놓을 수 있는지 출력한다.

예제 입력 1 
3
예제 출력 1 
4
예제 입력 2 
2
예제 출력 2 
2
*/

#include <bits/stdc++.h>
using namespace std;

string multiply_two(string s) {
    reverse(s.begin(), s.end());
    int carry = 0;
    string res;
    for (int i = 0; i < s.size(); ++i) {
        int digit = s[i] - '0';
        int mul = digit * 2 + carry;
        res.push_back((mul % 10) + '0');
        carry = mul / 10;
    }
    if (carry != 0)
        res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

string subtract_two(string s) {
    reverse(s.begin(), s.end());
    int need = 2;
    int i = 0;
    while (need > 0 && i < s.size()) {
        int digit = s[i] - '0';
        if (digit >= need) {
            digit -= need;
            s[i] = digit + '0';
            need = 0;
        } else {
            digit += 10 - need;
            s[i] = digit + '0';
            need = 1;
        }
        i++;
    }
    reverse(s.begin(), s.end());
    string result;
    bool leading_zero = true;
    for (char c : s) {
        if (leading_zero && c == '0')
            continue;
        leading_zero = false;
        result.push_back(c);
    }
    return result.empty() ? "0" : result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    if (N == "1")
        cout << "1\n";
    else
        cout << subtract_two(multiply_two(N)) << "\n";

    return 0;
}