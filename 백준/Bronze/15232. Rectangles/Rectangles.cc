/*
Rectangles 다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	512 MB	4045	3318	3166	83.141%
문제
Read two integer numbers R and C from the standard input and then print R lines with C asterisks (*) each.

Example (R=3, C=5):

*****
*****
*****
Example (R=2, C=10):

**********
**********
입력
The first line will contain an interger R. The number of lines to print.

The second line will contain an integer C. The number of asterisks to print in each line.

R, C will be at most 20.

출력
Print a rectangle of R lines and C columns.

예제 입력 1 
3
5
예제 출력 1 
*****
*****
*****
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    
    
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cout << '*';
      }
      cout << endl;
    }
    return 0;
}