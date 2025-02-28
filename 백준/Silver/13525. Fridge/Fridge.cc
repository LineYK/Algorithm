/*
냉장고 
 
시간 제한 메모리 제한
2초 512MB  

문제
냉장고의 기술은 수년에 걸쳐 거의 변하지 않았습니다. 
그럼에도 불구하고 1913년 프레드 W. 울프 가정용 냉장고의 최초 소유자 중 상당수는 현대 가전제품의 크기와 기능에 놀랐을 것입니다. 
하지만 1960년대 이후 전 세계 모든 냉장고 소유자에게 공통된 한 가지가 있었으니 바로 냉장고 자석입니다.
비록 게으른 방법이지만 어린아이를 즐겁게 하는 효과적인 방법은 
자석 숫자와 냉장고와 같은 큰 자석 표면을 제공하여 숫자를 붙일 수 있는 놀이 공간을 제공하는 것입니다.
이 놀이는 시간만 낭비하는 것이 아니라 숫자를 움직여 '1', '2' 등을 만들고 
'10', '11', '12'와 같은 높이까지 만들면서 수 세기라는 수학적 영역에 대한 귀중한 훈련을 제공합니다.
가능성은 무한합니다! ...또는 적어도 숫자의 공급이 제한되지 않는다면 그렇게 될 것입니다. 
우리가 가지고 있는 숫자의 전체 목록이 주어졌을 때, 
각 숫자를 한 번에 최대로 사용할 수 없는 가장 작은 양수는 무엇일까요?

입력
사용 가능한 자릿수가 특정한 순서 없이 포함된 최대 1000자리의 문자열입니다.
출력
주어진 자릿수로 조합할 수 없는 가장 작은 자연수인 양의 정수를 한 줄로 출력합니다.

예제 입력 1 
7129045863
예제 출력 1 
11
예제 입력 2 
55
예제 출력 2 
1
예제 입력 3 
123456789
예제 출력 3 
10
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int cnt[10] = {0};
    for(char c : s){
        cnt[c - '0']++;
    }
    
    string candidate1 = "";
    for (int d = 1; d <= 9; d++){
        string temp(cnt[d] + 1, '0' + d);
        if(candidate1 == "") {
            candidate1 = temp;
        } else {
            if(temp.size() < candidate1.size() || (temp.size() == candidate1.size() && temp < candidate1))
                candidate1 = temp;
        }
    }
    
    string candidate2 = "1" + string(cnt[0] + 1, '0');
    
    if(candidate1.size() < candidate2.size() || (candidate1.size() == candidate2.size() && candidate1 < candidate2))
        cout << candidate1;
    else
        cout << candidate2;
    
    return 0;
}
