/*
캠프파이어
 
시간 제한	메모리 제한
1 초	128 MB	

문제
이번 여름에 선영이와 친구들은 코딩 연습을 하기 위해 E일간 근처 바닷가로 MT를 갔다.

매일 밤에는 캠프파이어 시간이 있다. 캠프파이어에 참가하는 사람들은 모두 모여서 노래를 부른다. 캠프파이어는 필수 코스가 아니기 때문에, 매일 참가하고 싶은 사람만 참가한다.

MT에 참가한 사람 중 가장 인기있는 사람은 선영이다. 

매일 밤, 선영이가 캠프파이어에 참가한다면, 나머지 사람들이 모르는 새로운 노래를 즉석에서 만들어 부른다. 사람들은 모두 그 노래만 캠프파이어가 끝날 때까지 부른다.

선영이가 피곤해서 캠프파이어에 참가하지 않는 날도 있다. 이 날은 사람들이 각자 아는 노래를 서로 공유한다.

매일 캠프파이어에 참가하는 사람이 누구인지 주어졌을 때, 모든 노래를 알게되는 사람이 누구인지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 MT에 참가한 사람의 수 N이 주어진다. (1 ≤ N ≤ 100) 사람들은 1부터 N까지 번호가 매겨져 있으며, 선영이의 번호는 1이다.

둘째 줄에는 E가 주어진다. (1 ≤ E ≤ 50)

다음 E개 줄에는 그날 캠프파이어에 참가한 사람의 수 K와 참가한 사람의 번호가 주어진다. (2 ≤ K ≤ N)

선영이는 적어도 한 번 캠프파이어에 참가한다.

출력
MT가 끝났을 때, 선영이를 포함해 모든 노래를 아는 사람의 번호를 오름차순으로 출력한다.

예제 입력 1 
4
3
2 1 2
3 2 3 4
3 4 2 1
예제 출력 1 
1
2
4
예제 입력 2 
8
5
4 1 3 5 4
2 5 6
3 6 7 8
2 6 2
4 2 6 8 1
예제 출력 2 
1
2
6
8
예제 입력 3 
5
3
2 1 3
2 2 1
4 2 1 4 5
예제 출력 3 
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, E;
    cin >> N >> E;

    vector<unordered_set<int>> days;
    for (int i = 0; i < E; ++i) {
        int K;
        cin >> K;
        unordered_set<int> attendees;
        for (int j = 0; j < K; ++j) {
            int num;
            cin >> num;
            attendees.insert(num);
        }
        days.push_back(attendees);
    }

    int song_count = 0;
    vector<unordered_set<int>> people_songs(N + 1);

    for (const auto& attendees : days) {
        if (attendees.count(1)) {
            song_count++;
            int song = song_count;
            for (int p : attendees) {
                people_songs[p].insert(song);
            }
        } else {
            unordered_set<int> union_set;
            for (int p : attendees) {
                for (int s : people_songs[p]) {
                    union_set.insert(s);
                }
            }
            for (int p : attendees) {
                people_songs[p] = union_set;
            }
        }
    }

    vector<int> result;
    for (int p = 1; p <= N; ++p) {
        if (people_songs[p].size() == song_count) {
            result.push_back(p);
        }
    }

    sort(result.begin(), result.end());

    for (int p : result) {
        cout << p << '\n';
    }

    return 0;
}