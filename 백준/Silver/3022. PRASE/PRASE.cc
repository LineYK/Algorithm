/*
PRASE 다국어
 
시간 제한	메모리 제한
1 초	128 MB

문제
N명의 아이들이 식탁에서 점심을 먹고 있습니다. 아이들은 교대로 식탁에서 음식을 가져갑니다. 

일부 아이들은 아직 올바른 예절을 배우지 못했기 때문에
 다른 아이들에게 기회를 주지 않고 음식에 달려듭니다. 
 어느 시점에서 한 아이가 음식을 가져가는데 
 그 아이가 이미 다른 아이들보다 더 많은 음식을 가져간 경우(새 음식은 포함하지 않음), 
 어머니는 그 아이에게 행동에 주의하라고 경고합니다. 

아이들이 음식을 먹는 순서가 주어집니다. 
엄마가 아이들에게 경고해야 하는 횟수를 계산하는 프로그램을 작성하세요. 

입력
입력의 첫 번째 줄에는 아이들이 가져가는 음식의 개수인 정수 N(1 ≤ N ≤ 100)이 들어 있습니다. 

다음 N 줄에는 각각 음식 한 조각을 먹은 아이의 이름이 들어 있습니다. 
이름은 영어 알파벳 소문자 20자 이내로 구성된 문자열입니다. 

출력
한 줄에 경고 수를 출력합니다. 

예제 입력 1 
4
mirko
stanko
stanko
stanko
예제 출력 1 
1

예제 입력 2 
17
a
b
b
a
a
a
c
a
b
b
c
b
b
b
b
b
b
예제 출력 2 
4
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    map<string, int> m;
    int warn = 0;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        
        m[name]++;

        int other = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first != name) {
                other += it->second;
            }
        }

        if (m[name] > other+1) {
            warn++;
        }
    
    }

    cout << warn << endl;

    return 0;
}