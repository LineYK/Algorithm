/*
Swords 
 
시간 제한 메모리 제한	
1초 1024MB	

문제
얀 하오는 1부터 n까지 번호가 매겨진 검을 가지고 있습니다. 검 i는 공격력 a[i]와 방어력 b[i]를 가지고 있습니다.

얀 하오는 a[i] ≤ a[j], b[i] ≤ b[j]인 다른 검 j(j != i)가 존재한다면 검 i는 쓸모없다고 생각합니다. 
즉, 다른 검 j의 공격력과 방어력이 적어도 검 i의 공격력과 방어력만큼 좋으면 검 i는 쓸모없고, 
검이 쓸모없지 않으면 유용하다고 말합니다.

두 검의 공격력과 방어력이 같으면 두 검은 동등한 것으로 간주합니다. 
동등한 검은 한 쌍도 없다는 것을 보장합니다.

얀하오의 컬렉션에서 유용한 검의 개수를 찾도록 도와주세요.

입력
첫 번째 입력 줄에는 정확히 하나의 정수, n이 들어 있습니다.

다음 n줄의 입력은 각각 공백으로 구분된 두 개의 정수를 포함합니다. 
이러한 입력의 i번째 줄에는 검 i의 공격과 방어를 나타내는 a[i], b[i]가 각각 포함됩니다.

출력
출력에는 유용한 검의 개수인 정수가 하나 포함됩니다.

제한
1 ≤ n ≤ 100,000
1 ≤ a[i], b[i] ≤ 10^9
1 ≤ i < j ≤ n 모두에 대해, a[i] != a[j] 또는 b[i] != b[j]

서브태스크
번호 배점 제한
1 11	
n ≤ 500

2 21	
A[I], B[I] ≤ 500

3 34	
a[i] = i

4 25	
1 ≤ i < j ≤ n마다 a[i] != a[j]

5 9	
추가 제약 조건 없음

예제 입력 1 
3
2 3
1 3
5 3
예제 출력 1 
1

검 1과 검 3을 비교하면 a[1] = 2 ≤ 5 = a[3], b[1] = 3 ≤ 3 = b[3]이므로 검 1은 쓸모가 없습니다.
검 2와 검 1을 비교하면 a[2] = 1 ≤ 2 = a[1], b[2] = 3 ≤ 3 = b[1]이므로 검 2는 쓸모가 없습니다.
검 3이 유일하게 유용한 검입니다.

예제 입력 2 
4
5 6
2 5
6 9
1 3
예제 출력 2 
1
*/

#include <bits/stdc++.h>

using namespace std;

struct Sword {
    int attack, defense;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Sword> swords(n);
    for (int i = 0; i < n; i++) {
        cin >> swords[i].attack >> swords[i].defense;
    }
    
    sort(swords.begin(), swords.end(), [](const Sword &s1, const Sword &s2) {
        if (s1.attack == s2.attack)
            return s1.defense > s2.defense;
        return s1.attack > s2.attack;
    });
    
    int usefulCount = 0;
    int maxDefense = 0;
    
    for (auto &s : swords) {
        if (s.defense > maxDefense) {
            usefulCount++;
            maxDefense = s.defense;
        }
    }
    
    cout << usefulCount << "\n";
    return 0;
}