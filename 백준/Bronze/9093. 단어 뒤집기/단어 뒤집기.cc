/*
단어 뒤집기
 
시간 제한   메모리 제한
1 초   128 MB

문제
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 
단, 단어의 순서는 바꿀 수 없다. 단어는 영어 알파벳으로만 이루어져 있다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다. 
단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 단어 사이에는 공백이 하나 있다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 모두 뒤집어 출력한다.

예제 입력 1 
2
I am happy today
We want to win the first prize
예제 출력 1 
I ma yppah yadot
eW tnaw ot niw eht tsrif ezirp
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string s;
        getline(cin, s);

        istringstream iss(s);
        string word;
        vector<string> words;

        while (iss >> word) {
            reverse(word.begin(), word.end());
            words.push_back(word);
        }

        for (const string& w : words) {
            cout << w << ' ';
        }
        cout << '\n';
    }
    return 0;
}