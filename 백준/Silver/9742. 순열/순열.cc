/*
순열
 
시간 제한	메모리 제한
5 초	128 MB

문제
집합의 순열이란 집합의 서로 다른 원소를 모두 사용해 만들 수 있는 순서이다. 예를 들어, {2,3,5}의 순열은 다음과 같다.
2 3 5
2 5 3
3 2 5
3 5 2
5 2 3
5 3 2

각각의 순열은 숫자로 나타낼 수 있다. 위의 순열은 사전순으로 쓰여져 있으며, 등장하는 순서를 이용해 나타낸다. 즉, 3 5 2는 위치 4에 있고, 5 3 2는 마지막 위치인 6에 있다.
{b,e,i,n}으로 만들 수 있는 순열은 다음과 같다.
b e i n
b e n i
b i e n
b i n e
b n e i
b n i e
e b i n
e b n i
e i b n
e i n b
e n b i 
e n i b
i b e n
i b n e
i e b n
i e n b
i n b e
i n e b
n b e i
n b i e
n e b i
n e i b
n i b e
n i e b

서로 다른 숫자와 문자로 이루어진 집합과 위치가 주어졌을 때, 그 집합의 순열 중 주어진 위치의 순열을 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 문자열은 서로 다른 숫자와 알파벳으로 이루어져 있으며, 길이는 최대 10이다. 또한, 사전순 순서대로 주어진다. 문자열 다음에는 찾아야 하는 위치가 주어지며, 이 값은 3,628,800보다 작거나 같은 자연수이다.

출력
각각의 테스트 케이스마다, 입력으로 주어진 위치에 해당하는 순열을 공백없이 출력한다. 만약, 해당하는 순열이 없는 경우에는 "No permutation"을 출력한다.

예제 입력 1 
235 4
bein 20
123456 700
mnpqr 130
tuvwxyz 4000
예제 출력 1 
235 4 = 352
bein 20 = nbie
123456 700 = 651342
mnpqr 130 = No permutation
tuvwxyz 4000 = ywuxvzt
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    long long n;
    
    while(cin >> s >> n){
        cout << s << " " << n << " = ";
        
        string original = s;
        sort(s.begin(), s.end());
        
        int len = s.length();
        vector<bool> used(len, false);
        string result = "";
        
        long long total = 1;
        for(int i = 1; i <= len; i++){
            total *= i;
        }
        
        if(n > total){
            cout << "No permutation" << endl;
            continue;
        }      

        n--;
        
        for(int i = 0; i < len; i++){
            total /= (len - i);
            
            int idx = n / total;
            
            int count = 0;
            for(int j = 0; j < len; j++){
                if(!used[j]){
                    if(count == idx){
                        result += s[j];
                        used[j] = true;
                        break;
                    }
                    count++;
                }
            }
            
            n %= total;
        }
        
        cout << result << endl;
    }
    
    return 0;
}