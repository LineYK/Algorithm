/*
최대 단어 빈도
 
시간 제한 메모리 제한
1초 128MB	

문제
용어 빈도-역문서 빈도(tf-idf)는 문서 컬렉션에서 단어의 중요도를 반영하는 수치 통계입니다. 정보 검색 시스템에서 자주 사용됩니다. 문서에 단어가 나타나는 횟수(단어 빈도)는 tf-idf를 얻기 위한 주요 요소 중 하나입니다. 

문서에서 가장 빈번하게 등장하는 단어를 찾는 프로그램을 작성하라는 요청을 받습니다. 

입력
첫 번째 줄에는 단어의 수를 결정하는 정수 n(1≤ n ≤ 1000)이 들어 있습니다. 다음 n줄에는 한 줄에 한 단어씩 단어 목록이 포함됩니다. 단어에는 소문자만 포함되며 최대 20자까지 포함할 수 있습니다. 

출력
가장 높은 빈도를 가진 단어와 그 빈도를 공백으로 구분하여 출력합니다. 결과가 2개 이상 나오면 사전적 순서에서 나중에 나오는 것만 선택합니다. 

예제 입력 1 
10
mountain
lake
lake
zebra
tree
lake
zebra
zebra
animal
lakes
예제 출력 1 
zebra 3

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    map<string, int> freq;
    string word;

    for (int i = 0; i < n; i++) {
        cin >> word;
        freq[word]++;
    }

    int max_freq = 0;
    string max_word;

    for (auto &p : freq) {
        if (p.second > max_freq) {
            max_freq = p.second;
            max_word = p.first;
        } else if (p.second == max_freq) {
            if (p.first > max_word) {
                max_word = p.first;
            }
        }
    }

    cout << max_word << " " << max_freq << "\n";

    return 0;
}