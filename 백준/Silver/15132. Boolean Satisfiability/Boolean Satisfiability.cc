/*
부울 만족성 문제
 
시간 제한    메모리 제한
3 초    512 MB

문제
부울 만족성 문제(SAT)는 컴퓨터 과학 분야에서 매우 어려운 문제로 알려져 있습니다. 이 문제에서는 Boolean 공식을 주어지며, 주어진 공식의 변수들이 true 또는 false로 일관되게 대체될 수 있는지, 그리고 그 대체된 값으로 공식이 true로 평가되는지 확인해야 합니다. SAT는 NP-완전 문제로 알려져 있습니다. 또한 3-CNF 공식(3-SAT)의 경우에도 NP-완전입니다. 그러나 예를 들어, 2-CNF 공식에 대한 SAT 문제(2-SAT)는 P에 속합니다.

#SAT는 SAT 문제의 확장입니다. 이 문제에서는 변수에 값을 할당하는 것이 가능한지 확인하고, 그 방법을 세는 것이 필요합니다. 이 문제는 2-CNF 공식에 대해서도 #P-완전 문제로 알려져 있습니다. 우리는 #1-DNF-SAT를 해결해 주시기를 요청합니다. 이는 1-DNF 형식의 공리식(1-DNF formula)에 대한 #SAT 문제입니다.  

1-DNF 형식의 부울 공리식이 주어집니다. 이는 하나 이상의 공리(clause)의 논리적 또는(disjunction)로 구성되며, 각 공리는 정확히 하나의 리터럴(literal)로 이루어져 있으며, 각 리터럴은 변수(variable) 또는 그 부정(logical not)입니다.

형식적으로:

 ⟨formula⟩ ::= ⟨clause⟩ | ⟨formula⟩ ∨ ⟨clause⟩
  ⟨clause⟩ ::= ⟨literal⟩
 ⟨literal⟩ ::= ⟨variable⟩ | ¬ ⟨변수⟩
⟨변수⟩ ::= A . . . Z | a . . . z
귀하의 임무는 모든 변수를 true와 false 값으로 대체하는 방법의 수를 찾는 것입니다(같은 변수의 모든 발생은 같은 값으로 대체되어야 하며), 이 때 공식이 true로 평가되어야 합니다.

입력
입력 파일의 유일한 줄에는 1-DNF 형식의 논리 공식(1000개 이하의 기호로 구성됨)이 포함됩니다. 논리 연산은 ‘|’ (합집합)과 ‘~’ (부정)로 표시됩니다. 변수는 ‘A’ . . . ‘Z’와 ‘a’ . . . ‘z’입니다(대소문자는 서로 다른 변수로 간주됩니다). 공식에는 공백이나 문법에서 언급되지 않은 다른 문자가 포함되지 않습니다.

출력
단일 정수 값을 출력합니다 — 주어진 공식에 대한 #SAT 문제의 답입니다.

예제 입력 1 
a
예제 출력 1 
1
예제 입력 2 
B|~B
예제 출력 2 
2
예제 입력 3 
c|~C
예제 출력 3 
3
예제 입력 4 
i|c|p|c
예제 출력 4 
7
*/

#include <bits/stdc++.h>
using namespace std;

int idx_of(char c){
    if('A' <= c && c <= 'Z') return c - 'A';
    return 26 + (c - 'a');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if(!(cin >> s)) return 0;

    const int MAXV = 52;
    vector<bool> pos(MAXV,false), neg(MAXV,false);

    for(size_t i=0;i<s.size();){
        if(s[i] == '|'){ i++; continue; }
        if(s[i] == '~'){
            char v = s[i+1];
            neg[idx_of(v)] = true;
            i += 2;
        } else {
            char v = s[i];
            pos[idx_of(v)] = true;
            i += 1;
        }
    }

    int n = 0;
    bool both_exists = false;
    for(int i=0;i<MAXV;i++){
        if(pos[i] || neg[i]) n++;
        if(pos[i] && neg[i]) both_exists = true;
    }

    unsigned long long total;
    if(both_exists){
        total = 1ULL << n;        
    } else {
        total = (1ULL << n) - 1;  
    }

    cout << total << '\n';
    return 0;
}
