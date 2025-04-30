/*
워드 믹스
 
시간 제한 메모리 제한
1 초 1024 MB

문제
두 단어를 새로운 단어로 결합하는 프로그램을 작성하세요. 
두 단어의 길이는 알 수 없습니다. 
새 단어는 짧은 단어와 같은 길이가 될 것입니다. 
짝수 인덱스의 문자는 해당 인덱스의 첫 번째 단어에서 가져오고, 
홀수 인덱스의 문자는 해당 인덱스의 두 번째 단어에서 가져옵니다.

입력
입력은 한 줄에 공백으로 구분된 두 단어를 포함합니다.

출력
혼합된 단어를 표시합니다.

예제 입력 1 
stat better
예제 출력 1 
seat
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    string result = "";
    int n = min(a.size(), b.size());

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result += a[i];
        } else {
            result += b[i];
        }
    }

    cout << result << "\n";

    return 0;
}
