/*
Joint Attack

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	512 MB	186	92	71	45.223%
문제
General Torstein has sent the x-coordinate for the next joint attack and is expecting you to promptly follow his orders in order to avoid impeding doom. Unfortunately Torstein hates numbers with more than 2 digits and loves horizontal line segments, and has therefore sent the coordinate as a continued fraction, i.e.

 
 
 
\[ x=x_0+\frac{1}{x_1+\frac{1}{\ldots}}\] 

Your rocket launcher only accepts coordinates as reduced fractions, so you need to quickly compute the correct numbers to feed it in order to commence the attack. Hurry! Failure may have dire consequences!

입력
The first line of output is one integer n (1 ≤ n < 40), the number of coefficients in the continued fraction, followed by a line with n integers (1 ≤ xi < 100) the coefficients of x.

출력
The coordinate x as a reduced fraction. It is guaranteed that the numerator and denominator are both less than 1018.

예제 입력 1 
2
2 3
예제 출력 1 
7/3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long a = 1, b = x[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        long long tmp = a;
        a = b;
        b = x[i] * b + tmp;
    }

    cout << b << "/" << a;

	return 0;
}