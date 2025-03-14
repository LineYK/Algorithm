/*
키 큰 사람 다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	1449	1041	917	73.126%
문제
민우는 학창시절 승부욕이 강해서 달리기를 할 때에도 누가 가장 빠른지를 중요하게 생각하고, 시험을 볼 때에도 누가 가장 성적이 높은지를 중요하게 생각한다. 이번에 반에서 키를 측정하였는데, 민우는 마찬가지로 누구의 키가 가장 큰지 궁금해한다. 민우를 도와 가장 키가 큰 사람을 찾아보자.

입력
입력은 여러개의 테스트케이스로 구성되어있다. 각 테스트케이스는 첫 번째 줄에 학생의 수 N (0 < N ≤ 50)이 주어지고, 이어서 N개의 줄에 각 학생의 이름과 키가 공백으로 구별되어 주어진다. 학생의 이름은 알파벳 대/소문자로만 이루어져 있고, 길이는 10을 넘지 않는다. 학생의 키는 소숫점 이하 2자리까지 주어진다. N이 0으로 주어지는 경우 프로그램을 종료한다.

출력
각 테스트케이스에 대해, 가장 키가 큰 학생의 이름을 한 줄에 출력한다. 같은 키의 사람이 여러명 일 경우 모두 출력해야 하며, 순서는 입력으로 들어온 순서를 유지해야 한다.

예제 입력 1 
3
John 1.75
Mary 1.64
Sam 1.81
2
Jose 1.62
Miguel 1.58
5
John 1.75
Mary 1.75
Sam 1.74
Jose 1.75
Miguel 1.75
0
예제 출력 1 
Sam
Jose
John Mary Jose Miguel
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    while(1) {
        int T;
        cin >> T;
        if(T == 0) break;

        vector<pair<string, double>> v;
        for(int i = 0; i < T; i++) {
            string name;
            double height;
            cin >> name >> height;
            v.push_back({name, height});
        }

        double max_height = 0;
        for(int i = 0; i < T; i++) {
            max_height = max(max_height, v[i].second);
        }

        for(int i = 0; i < T; i++) {
            if(v[i].second == max_height) {
                cout << v[i].first << " ";
            }
        }

        cout << endl;
    }


    return 0;
}