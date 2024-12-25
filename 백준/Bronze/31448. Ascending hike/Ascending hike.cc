/*
Ascending hike 다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
0.5 초	1024 MB	131	82	67	67.000%
문제
Participating in the Olympics requires training, e.g., climbing from deep valleys to high peaks. Hence, you decided to go out for a hike in which you would be continuously walking on an upward slope, with the largest possible elevation gain.

You have noted the altitude of several remarkable points through which your hike would go: these altitudes are pairwise distinct integers 
$A_1, A_2, \dots , A_N$. The slope between the 
$k$ th and 
$(k + 1)$ th remarkable points is upward if 
$A_k < A_{k+1}$, and downward if 
$A_k > A_{k+1}$ . Given this list of altitudes, what is the maximal elevation gain of a continuously upward slope on your hike?

입력
The input consists of two lines. The first line contains the number 
$N$. The second line contains 
$N$ space-separated integers 
$A_1, A_2, \dots , A_N$.

출력
The output should contain a single line, consisting of a single number: the maximal integer 
$G$ for which there exist integers 
$k, k + 1, k + 2, \dots , \ell$ such that 
$A_k < A_{k+1} < A_{k+2} < \dots < A_{\ell} = A_k + G$.

제한
 
$2 \le N \le 1\, 000\, 000$ 
 
$0 \le A_k \le 1\, 000\, 000\, 000$ for all 
$k ⩽ N$ 
예제 입력 1 
9
3 4 5 8 1 2 7 6 9
예제 출력 1 
6
예제 입력 2 
3
8 5 3
예제 출력 2 
0
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int max_diff = 0;
    int start = 0;

    for (int i = 1; i < N; i++)
    {
        if (A[i] <= A[i - 1])
        {
            max_diff = max(max_diff, A[i - 1] - A[start]);
            start = i;
        }
    }

    max_diff = max(max_diff, A[N - 1] - A[start]);

    cout << max_diff;

    return 0;
}
