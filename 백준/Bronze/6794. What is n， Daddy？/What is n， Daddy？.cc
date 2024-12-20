/*
n은 무엇인가요, 아빠?
 
시간 제한 메모리 제한
2 초 512 MB

문제
나탈리는 손가락으로 숫자 세는 법을 배우고 있습니다. 아빠가 숫자 n (1 <= n <= 10)을 말하면, 
나탈리는 "총 손가락의 개수가 n이 되도록 하려면 각 손에서 몇 개의 손가락을 펴야 해?"라는 의미로 
"아빠, n이 뭐야?"라고 묻습니다.
간단하게 답하기 위해, 아빠는 손가락으로 숫자를 세는 정확한 방법을 아래의 규칙을 준수하며 보여줍니다:

- 숫자는 한 손 또는 두 손으로 표현합니다;
- 만약 두 손으로 숫자를 표현할 경우, 큰 숫자가 먼저 옵니다.

예를 들어 나탈리가 "아빠, 4가 뭐야?"라고 묻는다면 아빠는 이렇게 답할 것입니다:

- 4는 4야.
- 4는 3과 1이야.
- 4는 2와 2야.

당신은 나탈리의 아빠가 답의 개수를 정확히 말하는지 확인해야 합니다.

입력
입력은 1 ... 10 범위의 하나의 정수입니다.

출력
위의 적힌 규칙을 준수할 때 두 손으로 숫자를 세는 방법의 수를 출력합니다.

예제 입력 1 
4
예제 출력 1 
3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int l = 0, r = 0, ans = 0;
    
    while (l <= 5 && r <= 5) {
        if (l + r == n && l >= r) {
            ans++;
            r++;
            l = 0;
        }
        if (l == 5) {
            r++;
        } else {
            l++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}