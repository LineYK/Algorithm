/*
카드 뒤집기 게임
 
시간 제한	메모리 제한
1 초	1024 MB	

문제
카드 뒤집기 게임은 N개의 카드를 이용해서 진행하는 게임이다. 각 카드에는 1부터 N까지의 번호가 순서대로 매겨져 있으며 앞면은 흰색, 뒷면은 검은색이다. 초기에, N개의 카드는 앞면 또는 뒷면으로 놓여있다.

이 게임의 목표는 가장 높은 점수를 얻는 것이다. 점수는 색깔이 같은 연속된 카드 구간 중 가장 긴 길이로 정의한다.

최대 한 번, N 이하의 양의 정수 X를 골라서 1번부터 X번까지의 카드를 모두 뒤집을 수 있다.

이때, 카드 뒤집기 게임에서 얻을 수 있는 점수의 최댓값을 구하여라.

입력
첫 번째 줄에는 카드의 개수를 나타내는 정수 N(1 \le N \le 300,000)이 주어진다.

두 번째 줄에는 N개의 카드의 초기 상태 A_1, A_2, A_3, ... , A_{N}이 공백으로 구분되어 주어진다.

 0이면 카드의 초기 상태가 앞면임을, 1이면 초기 상태가 뒷면임을 나타낸다.

출력
카드 뒤집기 게임에서 얻을 수 있는 점수의 최댓값을 출력한다.

예제 입력 1 
10
1 1 1 1 1 1 1 1 1 1
예제 출력 1 
10
예제 입력 2 
7
1 1 0 1 1 0 1
예제 출력 2 
3
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    if(n == 1){
        cout << 1;
        return 0;
    }
    
    vector<int> left(n);
    left[0] = 1;
    for (int i = 1; i < n; i++){
        if (A[i] == A[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }
    
    vector<int> right(n);
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--){
        if (A[i] == A[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }
   
    vector<int> pre(n);
    pre[0] = left[0];
    for (int i = 1; i < n; i++){
        pre[i] = max(pre[i - 1], left[i]);
    }
    
    vector<int> suf(n);
    suf[n - 1] = right[n - 1];
    for (int i = n - 2; i >= 0; i--){
        suf[i] = max(suf[i + 1], right[i]);
    }
    
    int ans = 0;
    ans = max(ans, suf[0]);
    
    for (int x = 1; x <= n; x++){
        int candidate = 0;
        candidate = max(candidate, pre[x - 1]);
        
        if (x < n)
            candidate = max(candidate, suf[x]);
        
        if (x < n){
            if (1 - A[x - 1] == A[x])
                candidate = max(candidate, left[x - 1] + right[x]);
        }
        
        ans = max(ans, candidate);
    }
    
    cout << ans << "\n";
    return 0;
}