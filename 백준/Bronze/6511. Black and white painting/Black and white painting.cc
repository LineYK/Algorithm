/*
Black and white painting
 
시간 제한	메모리 제한	
1 초	128 MB	

문제
You are visiting the Centre Pompidou which contains a lot of modern paintings. In particular you notice one painting which consists solely of black and white squares, arranged in rows and columns like in a chess board (no two adjacent squares have the same colour). By the way, the artist did not use the tool of problem A to create the painting.

Since you are bored, you wonder how many 8 × 8 chess boards are embedded within this painting. The bottom right corner of a chess board must always be white.

입력
The input contains several test cases. Each test case consists of one line with three integers n, m and c. (8 ≤ n, m ≤ 40000), where n is the number of rows of the painting, and m is the number of columns of the painting. c is always 0 or 1, where 0 indicates that the bottom right corner of the painting is black, and 1 indicates that this corner is white.

The last test case is followed by a line containing three zeros.

출력
For each test case, print the number of chess boards embedded within the given painting.

예제 입력 1 
8 8 0
8 8 1
9 9 1
40000 39999 0
0 0 0
예제 출력 1 
0
1
2
799700028
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    while (cin >> n >> m >> c, n || m || c) {
        long long ans = 0;
        if (c == 0) {
            ans = ((long long)(n - 7) * (m - 7)) / 2;
        } else {
            ans = ((long long)(n - 7) * (m - 7) + 1) / 2;
        }
        cout << ans << '\n';
    }

    return 0;
}