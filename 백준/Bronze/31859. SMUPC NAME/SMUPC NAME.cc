/*
SMUPC NAME
 
시간 제한	메모리 제한
1 초	512 MB
문제
연재는 제4회 SMUPC에 출전하는 사람들을 위해 SMUPC NAME을 만들어주려고 한다. 
SMUPC NAME을 만드는 방법은 아래와 같다.

1. 출전자의 영어 이름에서 알파벳이 중복되지 않도록 추출한다. 
특정 알파벳이 여러 번 등장한다면 처음 등장한 경우를 제외하고 해당 알파벳을 버린다.
2. 1번을 통해 만들어진 문자열 맨 뒤에 1번 과정에서 버려진 문자의 총개수에 4를 더한 값을 붙인다.
3. 2번을 통해 만들어진 문자열 맨 앞에 출전 등록 번호에 1906을 더한 값을 붙인다.
4. 3번을 통해 만들어진 문자열을 뒤집는다.
5. 4번을 통해 만들어진 문자열 맨 앞에 "smupc_"를 붙인다.

출전 등록 번호가 2이며 "yeonjaechoi" 라는 영어 이름을 가진 사람의 SMUPC NAME을 규칙에 따라 만들면 다음과 같다.

yeonjachi
yeonjachi6
1908yeonjachi6
6ihcajnoey8091
smupc_6ihcajnoey8091

출전 등록 번호와 영어 이름이 주어지면 그 사람의 SMUPC NAME을 출력하자.

입력
첫째 줄에 출전 등록 번호 정수 N (1 <= N <= 100)과 
공백 없이 알파벳 소문자로만 구성된 영어 이름 S (1 <= |S| <= 20)가 공백으로 구분되어 주어진다.

출력
규칙에 따라 만든 SMUPC NAME을 출력한다.

예제 입력 1 
2 yeonjaechoi
예제 출력 1 
smupc_6ihcajnoey8091
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    string result = "";

    set<char> set;

    for (int i = 0; i < S.size(); i++) {
        if (set.find(S[i]) == set.end()) {
            set.insert(S[i]);
            result += S[i];
        }
    }

    result += to_string(S.length() - set.size() + 4);
    result = to_string(1906 + N) + result;
    reverse(result.begin(), result.end());
    result = "smupc_" + result;

    cout << result << endl;
    return 0;
}