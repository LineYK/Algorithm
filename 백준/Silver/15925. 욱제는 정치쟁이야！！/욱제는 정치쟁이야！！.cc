/*
욱제는 정치쟁이야!!
 
시간 제한   메모리 제한
2 초   512 MB   

문제
1학년 1반의 회장인 욱제는 오늘도 위기에 직면했다. 아이들이 컴퓨터실 사용후 컴퓨터를 중구난방으로 켜놓고 퇴실 해버린 것이다! 전교회장 선거에 출마할 생각인 욱제는 여론 관리를 위해 다음 컴퓨터실 시간표를 고려해서 컴퓨터를 모두 켜거나 꺼두려고 한다. 다음 시간에 컴퓨터실을 사용하는 반이 있다면 컴퓨터를 모두 켜두고, 그렇지 않다면 컴퓨터를 모두 꺼둘 것이다.

컴퓨터실은 N*N개의 학생용 컴퓨터가 정사각형 모양으로 격자에 맞춰 배열되어 있다. N은 항상 홀수이다.

욱제는 N*N 격자 밖의 교사용 컴퓨터로 전원을 제어하려고 한다. 교사용 컴퓨터에 설치된 제어 프로그램은 조금 독특하다(왜인지는 교육청에 문의하는 것이 좋겠다). 이 프로그램은 격자 상에서 사용자가 고른 어떤 한 줄(가로, 세로 중 하나)의 컴퓨터 상태를 모두 체크한다. 이때, 그 줄에 켜진 컴퓨터가 꺼진 컴퓨터보다 더 많다면 그 줄의 컴퓨터를 모두 켜고, 반대라면 그 줄의 컴퓨터를 모두 끈다. 이렇게 뒤집는 작업을 횟수 제한 없이 반복할 수 있다.

현재 컴퓨터실의 컴퓨터 전원 상태와, 다음 시간에 컴퓨터실을 사용하는 반이 있는지 여부가 주어진다! 욱제는 컴퓨터들을 다음 시간표에 맞게 모두 켜거나 끌 수 있을까?

입력
첫째 줄에 각 줄의 컴퓨터 개수 N과 이후의 컴퓨터실 사용 여부가 하나의 공백을 사이에 두고 주어진다. 사용 여부는 사용시 1, 미사용시 0으로 주어진다. (1 ≤ N ≤ 31, N % 2 == 1)
이후 둘째 줄부터 N*N의 컴퓨터실의 전원 상태가 주어진다. (i, j)의 컴퓨터가 켜져있으면 1, 꺼져있으면 0으로 표현되며 한 줄의 숫자들은 하나의 공백으로 구분된다.

출력
조건에 맞게 전원을 조작할 수 있다면 1을, 그렇지 않다면 0을 출력한다.

예제 입력 1 
5 0
0 0 0 1 1
1 1 0 1 1
0 1 0 0 0
0 1 1 1 0
1 0 1 1 1
예제 출력 1 
1
예제 입력 2 
5 1
0 0 0 1 1
1 1 0 1 1
0 1 0 0 0
0 1 1 1 0
1 0 1 1 1
예제 출력 2 
1
예제 입력 3 
5 1
1 1 0 0 0
0 1 1 0 0
0 0 1 1 0
0 0 0 1 1
1 0 0 0 1
예제 출력 3 
0
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;
    vector<vector<char>> a(N, vector<char>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x;
            cin >> x;
            a[i][j] = (char)x;
        }
    }

    int th = (N + 1) / 2;
    vector<int> rowCount(N, 0), colCount(N, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (a[i][j] == k) {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    vector<char> rowDone(N, 0), colDone(N, 0);
    queue<pair<int,int>> q;
    for(int i = 0; i < N; i++){
        if (rowCount[i] >= th){
            rowDone[i] = 1;
            q.push({0, i});
        }
    }
    for(int j = 0; j < N; j++){
        if (colCount[j] >= th){
            colDone[j] = 1;
            q.push({1, j});
        }
    }

    while(!q.empty()){
        auto [type, idx] = q.front(); q.pop();
        if (type == 0) {
            for(int j = 0; j < N; j++){
                if (a[idx][j] != k){
                    a[idx][j] = k;
                    if (++colCount[j] == th && !colDone[j]){
                        colDone[j] = 1;
                        q.push({1, j});
                    }
                }
            }
        } else {
            for(int i = 0; i < N; i++){
                if (a[i][idx] != k){
                    a[i][idx] = k;
                    if (++rowCount[i] == th && !rowDone[i]){
                        rowDone[i] = 1;
                        q.push({0, i});
                    }
                }
            }
        }
    }

    int doneRows = accumulate(rowDone.begin(), rowDone.end(), 0);
    int doneCols = accumulate(colDone.begin(), colDone.end(), 0);

    cout << (doneRows == N || doneCols == N ? 1 : 0) << "\n";
    return 0;
}
