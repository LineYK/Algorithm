/*
화난 문법 나치
 
시간 제한 메모리 제한
1초 256MB

문제
당신의 친구는 문법 나치라고 할 수 있습니다. 그는 인기 있는 인터넷 토론 포럼에서 많은 시간을 보냅니다. 
불행히도, 그는 성질이 나쁘고 누군가가 문법 및 철자법 규칙을 끊임없이 위반하며 영어를 더럽힐 때마다 이성을 잃습니다.

키보드, 모니터, 커피잔 받침대를 부수는 것을 피하기 위해 
친구에게 물건을 부수는 대신 화를 낼 때마다 잠시 읽기를 멈추고 10까지 세라고 조언합니다.

친구가 다음 단어 또는 일련의 단어를 읽을 때마다 화를 냅니다:

- “u”, “ur” instead of “you”, “your”.
- “would of”, “should of” instead of “would have”, “should have”.
- “lol” instead of “haha”. 사실 그는 단어에 “lol”이 하위 문자열로 포함되어 있어도 화를 냅니다.

문장을 하나씩 읽고 각 문장에 대해 친구가 해당 문장을 읽은 후
몇 번이나 숫자를 말했을지 계산하는 컴퓨터 프로그램을 작성하기로 결정했습니다. 
친구는 소리 내어 읽지 않으므로 입력 문장의 일부인 숫자는 계산되지 않아야 합니다.

입력
입력의 첫 번째 줄은 테스트 케이스의 수인 단일 정수 T로 구성됩니다. 
다음 T 줄은 각각 하나의 문장, 즉 공백으로 구분된 하나 이상의 단어를 포함합니다.

0 < T ≤ 50
한 문장은 공백을 포함하여 최대 100자로 구성됩니다.
한 단어는 a와 z 사이의 소문자로만 구성됩니다.
인접한 두 단어는 정확히 한 공백으로 구분되며, 한 문장에는 선행 또는 후행 공백이 없습니다.

출력
각 테스트 케이스에 대해 친구가 문장을 읽은 후 숫자를 몇 번 말했는지 출력합니다.

예제 입력 1 
4
u haz lolcats
my car is green
i have a lollipop
u should of lold
예제 출력 1 
20
0
10
30
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string s;  
        getline(cin, s);

        stringstream ss(s);
        string word;
        int cnt = 0;

        vector<string> words;

        while (ss >> word)
        {
            words.push_back(word);
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == "u" || words[i] == "ur")
                cnt++;
            else if (words[i] == "would" && i + 1 < words.size() && words[i + 1] == "of")
                cnt++;
            else if (words[i] == "should" && i + 1 < words.size() && words[i + 1] == "of")
                cnt++;
            else if (words[i].find("lol") != string::npos)
                cnt++;
        }

        cout << cnt * 10 << "\n";
    }
    
    return 0;
}
