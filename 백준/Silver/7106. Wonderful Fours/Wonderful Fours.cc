/*
Wonderful Fours
 
시간 제한	메모리 제한
1 초	128 MB	

문제
Let us name a set of five decimal digits K5. (Note that numbers may be repeated within this set).

We can say that a natural five-digit number is properly formed from K5 if it is formed by sequentially writing all the digits of K5 in a row in any order (taking each of them exactly once) and this number does not start with zero.

In this way, for example, if K5 contains four digits 1,1,7,0 and 4, then numbers 17140 and 47011 are properly formed from K5, while 17740 is not.

Let us call four natural five-digit numbers s1,s2,s3,s4 a K5 wonderful four, if the following properties are true for them :

s1 is properly formed from K5;
s2 is properly formed from K5;
s3 is properly formed from K5;
s4 is properly formed from K5;
s1, s2, s3 un s4 are all different numbers;
s1+ s2 + s3 = s4
The task is to compute how many different K5 wonderful fours can be formed from the five digits contained by the set K5 given in the input data. (Change of order of numbers within a wonderful four does not form a new wonderful four).

예제 입력 1 
0 2 6 2 8
예제 출력 1 
4
예제 입력 2 
9 2 3 3 9
예제 출력 2 
0
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> D(5);
    for(int i = 0; i < 5; i++) {
        cin >> D[i];
    }
    sort(D.begin(), D.end());
    set<int> st;
    do {
        if(D[0] == 0) continue; 
        int x = 0;
        for(int d : D) x = x*10 + d;
        st.insert(x);
    } while(next_permutation(D.begin(), D.end()));

    vector<int> V(st.begin(), st.end());
    unordered_set<int> S(st.begin(), st.end());

    int m = V.size();
    long long ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            for(int k = j+1; k < m; k++){
                int sum = V[i] + V[j] + V[k];
                if(S.count(sum)
                   && sum != V[i]
                   && sum != V[j]
                   && sum != V[k]) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
