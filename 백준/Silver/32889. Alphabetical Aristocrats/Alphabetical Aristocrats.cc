/*
알파벳순 귀족
 
시간 제한 메모리 제한
2 초 (추가 시간 없음) 1024 MB
문제
네덜란드 왕국이 프랑스 압제자로부터 독립한 지 15년이 지난 1830년, 우리 주님의 해입니다. 당신은 룩셈부르크 대공이자 네덜란드의 국왕인 윌리엄 1세의 국무장관 겸 보좌관으로, 앞으로 수 세기에 걸쳐 번영하고 확장될 제국의 운명을 짊어지고 있습니다. 그런데 최근 남쪽에서 온 악당들이 국왕의 자비로운 통치에 감히 도전장을 내밀어 국왕을 당황하게 만들었습니다. 그들은 스스로를 벨기에인이라 부르며 자신들의 왕국을 선포했는데, 윌리엄 왕은 적어도 7~11년 동안은 이 사실을 부인할 것입니다. 윌리엄 왕은 지혜를 모아 가장 신뢰할 수 있는 귀족들에게 9일 이상 지속될 반란 세력에 대한 작전을 계획하기로 결정했습니다.

신뢰할 수 있는 왕족의 명단을 작성하고 네덜란드 규칙에 따라 분류해야 합니다. 네덜란드 규칙에 따르면 성은 ASCII 문자의 값에 따라 사전적으로 비교하고 첫 번째 대문자로 시작하는 부분만 고려해야 합니다. 예를 들어, 윌리엄 왕은 자신이 가장 좋아하는 화가 아브라함 반 덴 헤켄의 성을 헤켄 더 영에 따라 비교합니다.

입력
입력은 다음으로 구성됩니다:

성의 개수인 정수 n(1\leq n\leq 1000)이 포함된 한 줄.
성 중 하나인 문자열 s(1\leq |s|\leq50)가 포함된 n줄. 성은 영문자, 공백, 아포스트로피(A-Z, a-z, ‘ ’, ‘’)로 구성됩니다.
첫 번째 대문자로 시작하는 부분은 고유해야 합니다. 이름에는 선행, 후행 또는 연속 공백이 없습니다.

출력
네덜란드어 규칙에 따라 정렬된 성 목록을 출력합니다.

예제 입력 1 
7
van der Steen
fakederSteenOfficial
Groot Koerkamp
Bakker
van den Hecken the Younger
de Waal
van 't Hek
예제 출력 1 
Bakker
Groot Koerkamp
van den Hecken the Younger
van 't Hek
van der Steen
fakederSteenOfficial
de Waal
예제 입력 2 
5
var Emreis
an Gleanna
Terzieff Godefroy
aep Ceallach
of Rivia
예제 출력 2 
aep Ceallach
var Emreis
an Gleanna
of Rivia
Terzieff Godefroy
예제 입력 3 
7
van den Brand
den Brand Heek
Brand 'Heek
van Brand heek
DeN bRAnD hEeK
den brandHeek
der Brandheek
예제 출력 3 
van den Brand
Brand 'Heek
den Brand Heek
van Brand heek
der Brandheek
DeN bRAnD hEeK
den brandHeek
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<string,string>> v;
    v.reserve(n);

    string s;
    for(int i = 0; i < n; i++){
        getline(cin >> ws, s);

        int pos = 0;
        while(pos < (int)s.size() && !isupper(s[pos])) {
            pos++;
        }
        string key = s.substr(pos);

        v.emplace_back(key, s);
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.first < b.first;
    });

    for(auto &p : v){
        cout << p.second << "\n";
    }

    return 0;
}
