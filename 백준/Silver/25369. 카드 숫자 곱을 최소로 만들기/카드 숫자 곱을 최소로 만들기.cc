/*
카드 숫자 곱을 최소로 만들기
 
시간 제한   메모리 제한
1 초   512 MB   

문제
1부터 9사이의 정수가 하나씩 적힌 카드가 무수히 많이 주어진다. 이 카드 중 n장의 카드를 선택하자. 같은 정수가 적힌 카드를 여러 개 선택할 수 있다. 내가 선택한 n장의 카드 집합을 A, 친구가 선택한 n장의 카드 집합을 B라고 하자. 집합 A에 있는 카드에 적힌 정수의 곱을 P(A), 집합 B에 있는 카드에 적힌 정수의 곱을 P(B)라고 하자. 집합 A가 주어지면, P(A) < P(B)를 만족하는 집합 B를 하나 출력하자. 집합 B가 여러 개면 집합 B의 원소를 오름차순 정렬하여 이어붙인 수가 가장 작은 경우의 집합 B를 출력하자. 집합 B가 없으면 B = {-1}을 출력하자.

입력
첫 번째 줄에 선택할 카드 개수 n이 주어진다.

두 번째 줄에 내가 선택한 n장의 카드의 수가 공백을 사이에 두고 순서대로 주어진다.

출력
첫 번째 줄에 친구가 선택한 집합 B의 원소를 오름차순으로 빈칸을 사이에 두고 순서대로 출력한다.

제한
1 ≤ n ≤ 7

예제 입력 1 
1
7
예제 출력 1 
8
{8}, {9} 중에서 8 < 9 이므로 B = {8}이 정답이다.

예제 입력 2 
2
5 5
예제 출력 2 
3 9
{3, 9}, {4, 7}, {4, 8}, {4, 9}, ... , {8, 9}, {9, 9} 중에서 B = {3, 9}가 정답이다.

예제 입력 3 
1
9
예제 출력 3 
-1
*/

#include <bits/stdc++.h>
using namespace std;


int n;
long long prodA;
bool found = false;

vector<int> B;

void dfs(int pos, int start) {
    if (found) return; 
    if (pos == n) {
        long long prodB = 1;
        for (int d : B) {
            prodB *= d;
        }
        if (prodB > prodA) {
            for (int d : B)
                cout << d << " ";
            cout << "\n";
            found = true;
        }
        return;
    }
    for (int d = start; d <= 9; d++) {
        B.push_back(d);
        dfs(pos + 1, d);
        if (found) return;
        B.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<int> A(n);
    prodA = 1;
    for (int i = 0; i < n; i++){
        cin >> A[i];
        prodA *= A[i];
    }
    
    dfs(0, 1);
    
    if (!found)
        cout << -1 << "\n";
    
    return 0;
}