/*
저항

시간 제한   메모리 제한
2 초 (추가 시간 없음)   128 MB

문제
전자 제품에는 저항이 들어간다. 저항은 색 3개를 이용해서 그 저항이 몇 옴인지 나타낸다.
처음 색 2개는 저항의 값이고, 마지막 색은 곱해야 하는 값이다. 저항의 값은 다음 표를 이용해서 구한다.

색   값   곱
black   0   1
brown   1   10
red   2   100
orange   3   1,000
yellow   4   10,000
green   5   100,000
blue   6   1,000,000
violet   7   10,000,000
grey   8   100,000,000
white   9   1,000,000,000
예를 들어, 저항의 색이 yellow, violet, red였다면 저항의 값은 4,700이 된다.

입력
첫째 줄에 첫 번째 색, 둘째 줄에 두 번째 색, 셋째 줄에 세 번째 색이 주어진다. 위의 표에 있는 색만 입력으로 주어진다.

출력
입력으로 주어진 저항의 저항값을 계산하여 첫째 줄에 출력한다.

예제 입력 1
yellow
violet
red
예제 출력 1
4700
예제 입력 2
orange
red
blue
예제 출력 2
32000000
예제 입력 3
white
white
white
예제 출력 3
99000000000
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> color_to_value = {
    {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
    {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},
    {"grey", 8}, {"white", 9}
};

unordered_map<string, int> color_to_multiplier = {
    {"black", 1}, {"brown", 10}, {"red", 100}, {"orange", 1000},
    {"yellow", 10000}, {"green", 100000}, {"blue", 1000000},
    {"violet", 10000000}, {"grey", 100000000}, {"white", 1000000000}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string first, second, third;
    cin >> first >> second >> third;

    long long resistance_value = color_to_value[first] * 10 + color_to_value[second];
    resistance_value *= color_to_multiplier[third];

    cout << resistance_value << "\n";

    return 0;
}