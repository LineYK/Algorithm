/*
PCR 검사 풀링 다국어
 
시간 제한 메모리 제한
1 초 1024 MB

문제
중합효소 연쇄 반응(PCR) 검사는 DNA 샘플을 반복적으로 복사한 다음 
COVID 특정 DNA 세그먼트의 존재 여부를 검사하는 COVID-19 검사입니다. 
시간이 오래 걸리고 필요한 시약이 제한될 수 있습니다. 
처리량을 개선하기 위한 한 가지 제안은 샘플 풀링입니다.

이 아이디어는 N개의 샘플을 결합하고 결합된 샘플에 대해 PCR 검사를 실행하는 것입니다. 
테스트가 음성이면 추가 테스트가 필요하지 않습니다. 
검사 결과가 양성이면 N명 모두 개별적으로 재검사를 받아야 합니다. 
양성 판정 확률이 낮으면 필요한 검사 횟수를 크게 줄일 수 있습니다.

한 사람이 양성 판정을 받을 확률 p를 입력으로 받아 
결합할 최적의 샘플 수 N을 출력하는 프로그램을 작성합니다.

P가 N명 모두가 음성 판정을 받을 확률이라면, 
필요한 예상 검사 횟수인 E(T)는 다음과 같습니다:

E(T) = 1*P + N*(1 - P)

E(T) / N을 최소화하려면 N을 선택합니다.

예를 들어, N이 2이고 p가 0.5인 경우, P는 0.25이고 E(T) = 0.25 + 2*0.75 = 1.75로 N보다 약간 적습니다.

각 사람의 샘플이 충분한지 확인하려면 N이 16을 넘지 않아야 합니다.

입력
입력은 한 사람이 코로나19 양성 판정을 받을 확률인 
소수점 이하 부동 소수점 값 p(0 < p < 1)를 포함하는 한 줄로 구성됩니다.

출력
출력은 십진수 한 줄을 포함하는 한 줄입니다. 
모든 N에 대해 E(T) ≥ N이면 값 1을 출력합니다. 
그렇지 않으면 E(T) / N을 최소화하는 2 ≤ N ≤ 16의 값을 출력합니다.

예제 입력 1 
0.1
예제 출력 1 
4
예제 입력 2 
0.02
예제 출력 2 
8
예제 입력 3 
0.01
예제 출력 3 
10
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double expectedTests(int N, double p) {
    double P = pow(1 - p, N);
    return P + N * (1 - P);
}

int main() {
    double p;
    cin >> p;

    int optimalN = 1;
    double minRatio = 1.0;

    for (int N = 1; N <= 16; ++N) {
        double E_T = expectedTests(N, p);
        double ratio = E_T / N;

        if (ratio < minRatio) {
            minRatio = ratio;
            optimalN = N;
        }
    }

    cout << optimalN << endl;

    return 0;
}