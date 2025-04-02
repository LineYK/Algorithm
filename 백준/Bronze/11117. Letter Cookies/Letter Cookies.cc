/*
문자 쿠키 
 
시간 제한 메모리 제한
1초 256MB	

문제
세트레는 마침내 유명한 레터 쿠키를 다시 시장에 출시하기로 결정했습니다. 물론 먹는 것만큼이나 가지고 노는 것도 재미있어요. 여동생은 상자에서 찾은 글자로 단어를 만들려고 하지만, 당신은 여동생보다 더 빨리 단어를 만들 수 있는지 아닌지를 결정하고 싶어요.

쿠키 상자의 글자가 주어졌을 때, 여동생이 철자를 알고 있는 단어의 철자를 맞출 수 있을까요? (단어를 만든 후 여동생은 쿠키를 다시 스크램블하여 나중에 단어에 글자를 재사용할 수 있습니다.)

입력
입력의 첫 줄은 여동생이 가지고 있는 글자 쿠키 상자의 개수인 숫자 T 하나로 구성됩니다. 각 테스트 케이스는 특별한 순서 없이 이 상자의 모든 글자를 설명하는 한 줄로 시작됩니다. 그런 다음 누나가 철자하고자 하는 단어의 수인 W가 있는 줄을 따라 한 줄에 각각 한 단어씩 적습니다.

0 < T ≤ 100
0 < W ≤ 100
모든 글자는 영어 알파벳(A-Z)의 대문자입니다.
각 쿠키 상자에는 최대 1000개의 문자가 있습니다.
각 단어는 최대 100개의 문자로 구성됩니다(반드시 실제 영어 단어일 필요는 없음).
출력
각 단어에 대해 해당 단어의 철자가 가능하면 YES를, 불가능하면 NO를 한 줄로 출력합니다.

예제 입력 1 
1
ABANANACOOKIE
4
BANANA
LETTER
COOKIES
CAN
예제 출력 1 
YES
NO
NO
YES
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string box;
        cin >> box;

        unordered_map<char, int> boxCount;
        for (char c : box) {
            boxCount[c]++;
        }

        int W;
        cin >> W;

        while (W--) {
            string word;
            cin >> word;

            unordered_map<char, int> wordCount;
            for (char c : word) {
                wordCount[c]++;
            }

            bool canForm = true;
            for (const auto& [c, count] : wordCount) {
                if (boxCount[c] < count) {
                    canForm = false;
                    break;
                }
            }

            cout << (canForm ? "YES" : "NO") << '\n';
        }
    }
    
    return 0;
}