/*
악마 게임
 
시간 제한	메모리 제한
1 초	256 MB

문제
악마 게임은 프로스트 엔터테인먼트에서 제작한 RPG 게임으로 3번째 시리즈까지 나왔다. 
악마 게임은 출중한 게임성으로 인해 두터운 팬층을 갖고 있다.

며칠 전에 악마 게임 개발발표회가 있었다. 
제작진들은 전부터 계속 신작 떡밥을 뿌려왔기 때문에 팬들은 엄청난 기대를 하고 있었다. 
팬들은 다 같이 ‘Devil IV’의 출시를 목놓아 외치고 있었다.

마침내 개발발표회가 있던 날이 다가왔다. 사회자가 화면에 ‘Devil IV’를 띄우자 관중은 환호했다. 
그러나 그 환호는 잠깐이었다. ‘Devil IV’의 뒤에 작대기가 하나 그어져 ‘Devil IVI’가 된 순간, 
발표회 분위기가 순식간에 싸늘해졌다. 
팬들은 갑작스러운 상황 변화를 받아들이지 못하여 분노하기 시작했다. 
그때 분위기는 어느 팬이 외쳤던 ‘이거 철 지난 만우절 장난이죠?’라는 질문 하나로 설명할 수 있을 것이다.

악마 게임의 오랜 팬인 동엽이는 그 때의 일에 충격받아 이걸 팀플 발표에 써먹으려고 한다. 
동엽이는 우선 재밌는 단어를 ppt에 띄워서 청중의 관심을 유발한 다음에 
단어 처음, 끝, 중간에 몇 글자를 끼워넣어 분위기를 싸하게 만들 것이다.

동엽이는 ‘갑분싸 사전’을 갖고 있다. 
그는 원래 단어로부터 사전에 있는 단어를 만들어 분위기를 얼어붙게 할 것이다. 
사전에 있는 단어들은 단어별로 갑분싸의 정도가 다른데, 
동엽이는 최대한 갑분싸의 정도가 큰 단어를 만들려고 한다. 
그러나 글자를 너무 많이 끼워 넣으면 재미없기 때문에 
동엽이는 추가한 글자 수 대비 갑분싸의 정도가 가장 큰 단어를 선택하려고 한다. 
동엽이를 도와 단어를 선택하는 프로그램을 작성하여라.

입력
첫 번째 줄에 동엽이가 재밌다고 생각하는 원래 단어 m이 주어진다.

두 번째 줄에 갑분싸 사전에 있는 단어의 수 N이 주어진다. (1 ≤ N ≤ 100)

이후 N 개의 줄에 걸쳐 갑분싸 사전에 있는 단어들이 주어지며, 
각 줄에 단어 w와 그 단어의 갑분싸 정도 g가 공백으로 구분되어 주어진다. (1 ≤ g ≤ 10,000)

모든 단어는 알파벳 대문자로만 이루어져 있으며 길이는 1 이상 100 이하이다.

원래 단어와 사전에 있는 단어들은 서로 다르다.

출력
첫 번째 줄에 넣은 글자 수 대비 갑분싸의 정도가 가장 큰 단어를 출력한다.

만약 그런 단어가 여러 개라면, 갑분싸 사전에서 가장 먼저 등장하는 단어를 출력한다.

만약 만들 수 있는 단어가 없다면, "No Jam"을 쌍따옴표를 제외하고 출력한다.

예제 입력 1 
DEVILIV
4
DEVILIVI 10
DEVILM 11
DEVILIVCONFIRMED 66
DENVERVILLAINV 70
예제 출력 1 
DEVILIVI

DEVILM은 DEVILIV에 글자를 끼워 넣어서 만들 수 없다.

나머지 세 단어의 갑분싸 가성비는 각각 10/1, 66/9, 70/7로 DEVILIV와 DENVERVILLAINV가 가장 높다. 
둘 중에서 DEVILIVI가 사전에 먼저 등장했으므로 DEVILIVI가 답이다.

예제 입력 2 
SUBINIUM
3
INSSADANCINGMACHINE 12
SOULLESSDANCINGMACHINE 345
ALGORITHMDANCINGMACHINE 6789
예제 출력 2 
No Jam
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string m;
    cin >> m;

    int N;
    cin >> N;

    vector<pair<string, int>> words;

    for (int i = 0; i < N; i++)
    {
        string w;
        int g;
        cin >> w >> g;
        words.emplace_back(w, g);
    }

    double max_ratio = 0.0;
    string ans = "No Jam";

    for (const auto& entry : words)
    {
        const string& w = entry.first;
        int g_val = entry.second;

        if (w.size() < m.size())
            continue;

        int idx = 0;
        for (char c : w)
        {
            if (idx < m.size() && c == m[idx])
                idx++;
        }

        if (idx == m.size())
        {
            int added = w.size() - m.size();
            if (added == 0)
                continue;
            double ratio = static_cast<double>(g_val) / added;

            if (ratio > max_ratio || (ratio == max_ratio && ans == "No Jam"))
            {
                max_ratio = ratio;
                ans = w;
            }
        }
    }

    cout << ans;

    return 0;
}