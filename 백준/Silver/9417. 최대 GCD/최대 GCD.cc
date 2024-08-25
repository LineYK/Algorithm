/*
최대 GCD
 
시간 제한   메모리 제한
1 초   128 MB   
문제
정수 M개가 주어졌을 때, 모든 두 수의 쌍 중에서 가장 큰 최대공약수 찾는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 N (1 < N < 100)이 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있으며, 양의 정수 M (1 < M < 100)개가 주어진다. 
모든 수는 -2^31보다 크거나 같고, 2^31 -1보다 작거나 같다. 

출력
각 테스트 케이스마다, 입력으로 주어진 수의 모든 두 수의 쌍의 최대공약수 중 가장 큰 값을 출력한다.

예제 입력 1 
3
10 20 30 40
7 5 12
125 15 25
예제 출력 1 
20
1
25
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> numList(n);

    for (int i = 0; i < n; i++) {
        int num;
        while (cin >> num) {
            numList[i].push_back(num);
            if (cin.get() == '\n') break;
        }
    }

    for (const auto& list : numList) {
        vector<int> ansList;
        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                ansList.push_back(gcd(list[i], list[j]));
            }
        }
        
        cout << *max_element(ansList.begin(), ansList.end()) << endl;
    }

    return 0;
}