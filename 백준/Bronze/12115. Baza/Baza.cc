/*
Baza 다국어
 
시간 제한   메모리 제한   제출   정답   맞힌 사람   정답 비율
1 초   64 MB   113   103   98   90.741%
문제
Mirko got a summer internship in a big IT company. This company builds a large database consisting of N rows and M columns.

On his first day, Mirko received a total of Q queries. Each query consists of M numbers. However, some numbers got lost during transition, so they are denoted with -1. Mirko wants to know how many rows of the database correspond to the query, i.e., how many rows of t he database have identical numbers as the query, excluding -1.

For example, if the query is in the form of -1 3 2 ​, then we need to count the rows of the database that have any number ​in the first column, have the number 3 in the second column, and have the number 2​ in the third​ column.

Since he just started with his internship, Mirko needs your help. Help him and answer the queries!

입력
The first line of input contains N (1 ≤ N ≤ 103) and M (1 ≤ M ≤ 103), the size of the database.
Each of the following N lines contains M numbers Aij (1 ≤ Aij ≤ 106), the content of the database.
The following line contains Q (1  Q ≤ 50), the number of queries.
Each of the following Q lines contains M numbers Bij (Bij = -1 or 1 ≤ Bij ≤ 106), the description of the i th query.

출력
The output must contain Q lines, each line containing X, the answer to the i th query from the task.

예제 입력 1 
4 3
1 5 2
2 3 4
4 3 2
5 4 6
3
-1 -1 2
-1 3 2
-1 -1 -1
예제 출력 1 
2
1
4
예제 입력 2 
3 8
6 5 97 99 82 50 95 1
85 62 11 64 94 84 88 19
43 99 11 64 94 84 31 19
3
-1 -1 11 64 94 84 -1 19
-1 -1 -1 99 -1 -1 -1 1
95 -1 -1 -1 -1 80 -1 -1
예제 출력 2 
2
1
0
힌트
The first query asks how many rows have the number 2 in the third column. These are rows number 1 (1 5 2) and number 3 (4 3 2).
The second query asks how many rows have the numbers 3 and 2 in the second and third column. This is only row number 3 (4 3 2).
The third query asks how many rows are there in total, and the answer is obviously 4.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> db(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> db[i][j];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        vector<int> query(m);
        for (int j = 0; j < m; j++) {
            cin >> query[j];
        }

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < m; k++) {
                if (query[k] != -1 && query[k] != db[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    
   return 0;
}
