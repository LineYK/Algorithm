/*
바코드 닉네임
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	1024 MB	947	785	731	83.447%
문제
본 문제에는 문자 'l'과 'I'가 동시에 등장합니다. 예제를 제외한 지문에서 소문자 'l'은 빨간색 
$\color{red}{\text{l}}$, 대문자 'I'는 파란색 
$\color{blue}{\text{I}}$로 표시합니다.

바코드 닉네임이란, 인터넷에서 계정을 익명화하기 위해 닉네임에 소문자 
$\color{red}{\text{l}}$과 대문자 
$\color{blue}{\text{I}}$만을 사용하는 것을 의미합니다. 이 두 문자는 쉽게 구별하기 어렵기 때문에, 바코드 닉네임은 그 사용자가 누구인지 알아보기 어렵게 만듭니다.

이러한 바코드 닉네임을 쉽게 구별할 수 있는 방법이 있습니다. 모든 문자의 대소문자 여부를 바꾸면, 
$\color{red}{\text{l}}$은 'L'이, 
$\color{blue}{\text{I}}$는 'i'가 됩니다. 따라서 이 방법을 사용하면 비슷하게 생긴 두 문자를 편리하게 구별할 수 있습니다.

바코드 닉네임이 주어질 때, 모든 문자의 대소문자 여부를 바꾸어 출력하는 프로그램을 작성해 주세요.

입력
첫 번째 줄에 바코드 닉네임의 길이 
$n$이 주어집니다. (
$1 \le n \le 500$)

두 번째 줄에 바코드 닉네임을 나타내는 문자열 
$S$가 주어집니다. (
$S_i = \color{red}{\text{l}}$ 또는 
$S_i = \color{blue}{\text{I}}$)

출력
입력된 문자열의 모든 문자의 대소문자 여부를 바꾸어 한 줄에 출력합니다.

예제 입력 1 
10
IllIllIlIl
예제 출력 1 
iLLiLLiLiL
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            cout << 'i';
        } else {
            cout << 'L';
        }
    }

    return 0;
}