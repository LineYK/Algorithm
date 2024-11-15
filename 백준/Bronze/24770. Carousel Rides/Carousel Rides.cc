/*
Carousel Rides

시간 제한	메모리 제한
1 초	1024 MB

문제
칼은 회전목마를 타는 것을 좋아합니다. 
회전목마 직원은 여러 번 타면 할인을 제공해줍니다. 
칼은 어떤 할인 조건이 자신에게 가장 이익인지 궁금합니다.
그를 도와 프로그램을 작성합시다.

입력
입력은 여러 테스트 케이스로 이루어져 있습니다. 
테스트 케이스는 두 수 n(1 <= n <= 10)과 m(1 <= m <= 20)이 주어지는 줄로 시작합니다. 
칼은 자신이 m개를 넘는 표를 사야 하는 할인 조건은 고려하지 않을 것입니다. 
이후 n개의 줄 각각에, a개의 표를 $b에 살 수 있다는 것을 나타내는 두 수 a와 b가 주어집니다.

입력은 0 0 한 줄이 들어오면 종료됩니다.

출력
각 테스트 케이스에 대해, 그의 요구 조건에 가장 부합하는 Buy a tickets for $b를 출력합니다. 
그러한 경우가 여럿이라면, 더 많은 티켓을 구매하는 할인 조건을 출력합니다. 
조건을 만족하는 경우가 없을 경우, No suitable tickets offered를 출력합니다. 

예제 입력 1 
3 5
1 3
3 5
4 7
3 2
3 5
1 3
4 7
3 2
3 6
1 2
2 4
1 3
4 10
0 0
예제 출력 1 
Buy 3 tickets for $5
Buy 1 tickets for $3
Buy 2 tickets for $4
No suitable tickets offered
*/

#include <bits/stdc++.h>

using namespace std;

int main() {

	while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        double minPricePerTicket = numeric_limits<double>::max();
        int bestTicketCount = 0;
        int bestPrice = 0;

        for (int i = 0; i < n; i++) {
            double countOfTicket, price;
            cin >> countOfTicket >> price;
            
            if (countOfTicket > m) {
                continue;
            }

            double pricePerTicket = price / countOfTicket;
            if (pricePerTicket < minPricePerTicket) {
                minPricePerTicket = pricePerTicket;
                bestTicketCount = (int)(countOfTicket);
                bestPrice = (int)(price);
            } 
            else if (pricePerTicket == minPricePerTicket && countOfTicket > bestTicketCount) {
                bestTicketCount = (int)(countOfTicket);
                bestPrice = (int)(price);
            }
        }

        if (minPricePerTicket == numeric_limits<double>::max()) {
            cout << "No suitable tickets offered" << endl;
        } else {
            cout << "Buy " << bestTicketCount << " tickets for $" << bestPrice << endl;
        }
    }


	return 0;
}

