/*
김식당
 
시간 제한   메모리 제한
2 초   256 MB

문제
인하대학교 축제를 맞이하여 알고리즘 동아리 CTP에서는 식당을 열기로 하였다. 요리는 세진이가 하게 되었고, 주문을 받는 것은 한솔이가 하게 되었다. 식당의 음식이 너무 맛있어서 주문은 끊임없이 계속되었고, 한솔이는 밀려오는 주문에 주문 순서를 혼동하게 되었다.

이러한 이유로 한솔이는 주문 받을 때 테이블의 번호와 주문한 시간을 포스트잇에 적어서 세진이에게 넘겨주었지만, 요리를 하느라 바쁜 세진이가 주문들의 순서를 파악하는 것은 쉽지 않았다. 이때, 지나가던 토쟁이가 포스트잇들을 시간 순서에 맞게 정렬해서 보여주며, 요리가 완성된 테이블의 포스트잇을 제거하는 프로그램을 만들어주기로 하였지만 시험기간이 얼마 남지 않아 힘들다. 만들 프로그램의 명령어와 수행 기능은 다음과 같다.

order (테이블 번호 n) (주문시간 t): 주문 시간 t에 테이블 n에서 주문 들어옴 (주문이 들어오면 갖고 있는 포스트잇들의 맨 뒤에 새 포스트잇을 추가)
sort: 주문 시간이 빠른 순서대로 정렬
complete n: n번 테이블의 요리 완성. (요리를 완성하는 시점에 해당 테이블에 두 개 이상의 주문이 밀려 있거나 주문이 없는 경우는 존재하지 않음)
코딩을 잘하는 여러분이 토쟁이를 도와 김식당을 부흥시켜줄 프로그램을 만들어 보자.

입력
입력의 첫째 줄에 질의의 수 N과 테이블의 수 M이 주어진다. (1≤N, M≤100)

다음 N줄에 각각의 명령어들이 주어진다. 포스트잇을 정렬할 때 주문 시간이 같다면 테이블 번호가 작은 것을 더 앞에 놓는다. (1 ≤ 주문 시간 ≤ 1,000 , 1 ≤ 테이블 번호 ≤ M)

출력
각 줄에 각 명령어가 수행된 뒤의 포스트잇들에 적힌 테이블 번호를 출력한다. 아무 포스트잇도 없을 경우 sleep을 출력한다.

예제 입력 1 
7 3
order 1 4
order 2 2
order 3 3
sort
complete 3
complete 2
complete 1
예제 출력 1 
1
1 2
1 2 3
2 3 1
2 1
1
sleep
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> notes;

    for(int qi = 0; qi < N; qi++){
        string cmd;
        cin >> cmd;
        if(cmd == "order"){
            int table, t;
            cin >> table >> t;
            // 맨 뒤에 추가
            notes.emplace_back(table, t);
        }
        else if(cmd == "sort"){
            sort(notes.begin(), notes.end(),
                 [](auto &A, auto &B){
                    if(A.second != B.second) return A.second < B.second;
                    return A.first < B.first;
                 });
        }
        else if(cmd == "complete"){
            int table;
            cin >> table;
            for(auto it = notes.begin(); it != notes.end(); ++it){
                if(it->first == table){
                    notes.erase(it);
                    break;
                }
            }
        }

        if(notes.empty()){
            cout << "sleep\n";
        } else {
            for(int i = 0; i < (int)notes.size(); i++){
                if(i) cout << ' ';
                cout << notes[i].first;
            }
            cout << "\n";
        }
    }

    return 0;
}
