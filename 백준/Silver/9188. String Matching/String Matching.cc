/*
문자열 일치
 
시간 제한    메모리 제한
1 초    128 MB

문제
두 단어가 동일인지 확인하는 것은 쉽습니다 - 단순히 문자를 비교하면 됩니다. 하지만 두 단어가 거의 동일하다고 판단하려면 어떻게 해야 할까요? 그리고 '거의 동일'이란 얼마나 가까운 것을 의미할까요?

근사 문자열 일치에는 다양한 기술이 있습니다. 그 중 하나는 최상의 부분 문자열 일치를 결정하는 것입니다. 이는 두 단어를 글자별로 비교할 때 공통된 글자의 수를 의미합니다. 이 접근법의 핵심은 두 단어가 어떤 방식으로든 겹칠 수 있다는 점입니다. 예를 들어, CAPILLARY와 MARSUPIAL이라는 단어를 고려해 보겠습니다. 이들을 비교하는 한 가지 방법은 다음과 같이 겹쳐보는 것입니다:

CAPILLARY
MARSUPIAL
공통된 글자는 단 하나(A)입니다. 더 나은 방법은 다음과 같은 중첩입니다:

CAPILLARY
     MARSUPIAL
공통된 글자가 두 개(A와 R)이지만, 가장 좋은 방법은:

   CAPILLARY
MARSUPIAL
공통된 글자가 세 개(P, I, L)입니다.

두 단어 간의 근사도 측정값 appx(word1, word2)는 다음과 같이 계산됩니다:

     공통 글자 수 * 2
-----------------------------
length(word1) + length(word2)
따라서 이 예시에서 appx(CAPILLARY, MARSUPIAL) = 6 / (9 + 9) = 1/3입니다.  명백히, 어떤 단어 W에 대해 appx(W, W) = 1이며, 이는 좋은 성질입니다. 공통 문자가 없는 단어들은 appx 값이 0입니다.

입력
프로그램의 입력은 줄당 두 개의 단어로 구성된 단어 목록으로, 파일 끝 표시기 -1까지 계속됩니다. 위 기술을 사용하여 줄에 있는 단어 쌍에 대해 appx()를 계산하고 결과를 출력해야 합니다. 모든 단어는 대문자로 표시됩니다.

출력
각 단어 쌍에 대한 appx() 값을 약분된 분수로 출력합니다. 0 또는 1로 약분되는 분수는 분모를 생략합니다.

예제 입력 1 
CAR CART
TURKEY CHICKEN
MONEY POVERTY
ROUGH PESKY
A A
-1
예제 출력 1 
appx(CAR,CART) = 6/7
appx(TURKEY,CHICKEN) = 4/13
appx(MONEY,POVERTY) = 1/3
appx(ROUGH,PESKY) = 0
appx(A,A) = 1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string word1, word2;
    while (cin >> word1 >> word2) {
        int len1 = word1.size(), len2 = word2.size();
        int max_common = 0;

        for (int offset = -len2 + 1; offset < len1; ++offset) {
            int common = 0;
            for (int i = 0; i < len2; ++i) {
                if (offset + i >= 0 && offset + i < len1 && word1[offset + i] == word2[i]) {
                    common++;
                }
            }
            max_common = max(max_common, common);
        }

        int numerator = max_common * 2;
        int denominator = len1 + len2;

        if (numerator == 0) {
            cout << "appx(" << word1 << "," << word2 << ") = 0\n";
        } else if (numerator == denominator) {
            cout << "appx(" << word1 << "," << word2 << ") = 1\n";
        } else {
            int gcd = __gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            cout << "appx(" << word1 << "," << word2 << ") = " 
                 << numerator;
            if (denominator != 1) {
                cout << "/" << denominator;
            }
            cout << "\n";
        }
    }

    return 0;
}