/*
왼쪽 뒤쳐진
 
시간 제한 메모리 제한
1 초 1024 MB

문제
양봉가 빌은 친구들과 함께 연례 양봉가 대회에 갈 준비를 하고 있습니다. 
빌은 꿀을 항아리에 포장했지만, 안타깝게도 일부 항아리의 꿀이 시큼하게 변했습니다. 
빌의 친구들은 빌의 꿀이 너무 많이 시면 빌 없이 대회에 가겠다고 합니다.

빌이 단 꿀보다 신 꿀이 더 많은 병을 가지고 있다면 빌은 “뒤처지게” 됩니다. 
빌이 신 꿀보다 단 꿀이 더 많은 병을 가지고 있다면 그는 대회에 참석하게 됩니다. 
빌의 단 꿀병과 신 꿀병의 개수가 같으면 친구들은 미정입니다. 
마지막으로, 빌의 친구들은 미신을 믿기 때문에 정확히 13개의 병을 가지고 있다면 
다시는 빌과 말을 걸지 않을 것입니다. 빌은 새로운 친구가 필요합니다.

입력
입력은 각각 고유한 줄에 여러 개의 케이스로 구성됩니다. 
각 케이스는 각각 빌이 가지고 있는 새콤달콤한 병과 달콤한 병의 개수인 
두 개의 숫자 x와 y(0 ≤ x, y ≤ 1000)로 구성됩니다. 
입력은 두 개의 0이 포함된 줄로 끝납니다.

출력
각 경우에 대해 다음 결과 중 하나를 자체 줄에 따옴표 없이 출력합니다.

“Left behind.” (맞춤법에 유의하세요. 말장난입니다.)
“Undecided.”
“To the convention.”
“Never speak again.”
빌의 친구들이 다시는 그와 말하지 않겠다는 것이 가장 중요하며 유일한 출력이어야 합니다.


예제 입력 1 
17 3
13 14
8 5
44 44
0 0

예제 출력 1 
To the convention.
Left beehind.
Never speak again.
Undecided.

*/

#include <iostream>

using namespace std;

int main() {
    int x, y;
    while (1) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        if (x + y == 13) cout << "Never speak again." << endl;
        else if (x == y) cout << "Undecided." << endl;
        else if (x < y) cout << "Left beehind." << endl;
        else if (x > y) cout << "To the convention." << endl;
    }

    return 0;
}