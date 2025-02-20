/*
T9 맞춤법(대형) 
 
시간 제한 메모리 제한	
5초 512MB	

문제
라틴 알파벳은 26개의 문자로 구성되어 있고 전화기 키패드에는 10자리 숫자만 있습니다. 
원하는 문자를 표시하기 위해 일련의 키를 눌러 친구에게 메시지를 쉽게 쓸 수 있도록 하려고 합니다. 
문자는 아래와 같이 숫자에 매핑됩니다. 예를 들어 문자 B를 삽입하려면 22를 누릅니다. 
동일한 키에서 두 문자를 연속으로 삽입하려면 사용자는 키를 두 번 누르기 전에 잠시 멈춰야 합니다. 
공백 문자 ' ' 를 인쇄하여 일시 중지를 표시해야 합니다. 예를 들어 2 2는 AA를 나타내고 22는 B를 나타냅니다.

입력
입력의 첫 줄은 케이스 수인 N. N개의 테스트 케이스가 이어집니다. 
각 케이스는 다음과 같은 형식의 텍스트 한 줄입니다.

desired_message

각 메시지는 소문자 a-z와 공백 문자 ' ' 로만 구성됩니다. 0을 누르면 공백이 표시됩니다.

제한값
1 ≤ N ≤ 100.
1 ≤ 메시지 길이(문자) ≤ 1000자.
출력
각 테스트 케이스에 대해 “케이스 #x.”가 포함된 한 줄을 출력합니다: “와 그 뒤에 키 누름 시퀀스로 변환된 메시지를 출력합니다.

예제 입력 1 
4
hi
yes
foo  bar
hello world
예제 출력 1 
Case #1: 44 444
Case #2: 999337777
Case #3: 333666 6660 022 2777
Case #4: 4433555 555666096667775553
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> key = {
    {" "},
    {""},
    {"a", "b", "c"},
    {"d", "e", "f"},
    {"g", "h", "i"},
    {"j", "k", "l"},
    {"m", "n", "o"},
    {"p", "q", "r", "s"},
    {"t", "u", "v"},
    {"w", "x", "y", "z"}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        cout << "Case #" << i + 1 << ": ";
        int prev_key = -1;

        for (char c : s) {
            int current_key = -1;
            int presses = 0;

            if (c == ' ') {
                current_key = 0;
                presses = 1;
            } else {
                for (int l = 0; l < key.size(); ++l) {
                    bool found = false;
                    for (int m = 0; m < key[l].size(); ++m) {
                        if (key[l][m][0] == c) {
                            current_key = l;
                            presses = m + 1;
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
            }

            if (current_key == prev_key) {
                cout << " ";
            }

            for (int p = 0; p < presses; ++p) {
                cout << current_key;
            }

            prev_key = current_key;
        }

        cout << "\n";
    }

    return 0;
}
