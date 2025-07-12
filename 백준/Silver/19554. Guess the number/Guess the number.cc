/*
숫자를 추측하세요
 
시간 제한    메모리 제한
0.3 초 (추가 시간 없음)    256 MB

문제
1부터 N까지의 범위 내에 있는 정수 X를 추측하는 프로그램을 작성하세요.

프로토콜
이 문제는 상호작용형 과제입니다. 프로그램이 실행되면 입력의 첫 번째 줄에 정수 N (1 ≤ N ≤ 10⁹)이 주어집니다. X의 값은 채점 시스템에 의해 비밀로 유지됩니다.

프로그램은 출력에 “? P” 형식으로 쿼리를 발행할 수 있습니다. 여기서 P는 정수(1 ≤ P ≤ N)입니다. 채점 시스템은 입력의 다음 줄에 응답을 작성합니다. 응답은 P < X일 경우 −1, P = X일 경우 0, P > X일 경우 1입니다. 각 테스트 케이스에서 프로그램은 최대 50개의 쿼리를 발행할 수 있습니다.

프로그램이 숫자 X를 추측하려면 “= X” (1 ≤ X ≤ N)를 출력하고 종료해야 합니다. 채점 시스템은 이 출력에 응답하지 않으며, 그 이후 추가 쿼리를 허용하지 않습니다.

서브태스크
번호    배점    제한
1    29    
1 ≤ N ≤ 50

2    71    
추가 제약 조건 없음

예제 입력 1 
5

-1

1

0

예제 출력 1 

? 1

? 3

? 2

= 2
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long lo = 1, hi = N;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        cout << "? " << mid << "\n" << flush;

        int resp;
        cin >> resp;

        if (resp == 0) {
            cout << "= " << mid << "\n" << flush;
            return 0;
        }
        else if (resp == -1) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    return 0;
}
