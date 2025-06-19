/*
허위 경보
 
시간 제한    메모리 제한
2 초    2048 MB

문제
파이나는 잠을 자려고 하지만, 내일 아침 매우 중요한 대회 때문에 일찍 일어나야 합니다. 그녀는 이미 아침 7시부터 9시 사이의 다양한 시간에 n개의 알람을 설정했습니다.

그러나 파이나는 깊은 잠을 자는 편입니다. 그녀는 깨어나기 위해 10분 이내에 최소 세 개의 알람을 들어야 한다는 것을 알고 있습니다. 즉, 세 개의 알람 중 첫 번째와 마지막 알람의 시간 차이는 10분 이하여야 합니다.

파이나는 현재 설정된 알람이 이 조건을 충족하는지 확신하지 못하며, 경기를 놓칠까 봐 걱정됩니다(그리고 팀원들을 화나게 만들 수도 있죠!). 따라서 추가 알람을 설정하고 싶어합니다. 모든 새로운 알람도 7시부터 9시 사이에 설정되어야 하며, 모든 알람(기존 알람 포함)은 서로 다른 시간에 설정되어야 합니다.

Faina가 확실히 깨어날 수 있도록 추가로 설정해야 할 알람의 최소 개수를 구하세요. 특히, 이미 깨어날 수 있다고 확신할 수 있다면 추가 알람의 개수는 0입니다.

입력
첫 번째 줄에는 Faina가 설정한 알람의 개수 n(1 \le n \le 20)을 나타내는 정수가 있습니다.

다음 n개의 줄 중 i번째 줄에는 i번째 알람의 시간(h:mm 형식)이 표시됩니다(7 \le \mathtt{h} \le 9; 00 \le \mathtt{mm} \le 59; 만약 \mathtt{h} = 9라면 \mathtt{mm} = 00). 알람은 시간 순서대로 증가하는 순서로 주어집니다.

출력
Faina가 깨어날 것을 보장하기 위해 추가로 설정해야 하는 알람의 최소 개수를 출력합니다.

예제 입력 1 
5
7:47
7:56
7:59
8:05
8:13
예제 출력 1 
0
예제 입력 2 
7
8:00
8:10
8:20
8:30
8:40
8:50
9:00
예제 출력 2 
1
예제 입력 3 
3
7:13
7:41
8:36
예제 출력 3 
2
노트
첫 번째 테스트에서 7:56, 7:59, 8:05에 세 개의 알람을 설정하면 Faina가 깨어날 수 있습니다.

두 번째 테스트에서는 8:00과 9:00 사이의 시간 중 기존 알람과 겹치지 않는 시간이 작동합니다.

세 번째 테스트에서는 7:45와 7:46에 두 개의 추가 알람을 설정하는 것이 한 가지 가능한 해결책입니다.
*/

#include <bits/stdc++.h>
using namespace std;

bool has_good_triple(const vector<int>& all) {
    int m = all.size();
    for(int i = 0; i+2 < m; i++){
        if(all[i+2] - all[i] <= 10) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> orig;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;  
        int h = stoi(t.substr(0, t.find(':')));
        int mm = stoi(t.substr(t.find(':')+1));
        orig.push_back(h*60 + mm);
    }
    sort(orig.begin(), orig.end());

    vector<int> cand;
    vector<bool> has(541, false);
    for(int x : orig) has[x] = true;
    for(int t = 420; t <= 540; t++){
        if(!has[t]) cand.push_back(t);
    }

    for(int k = 0; k <= 3; k++){
        vector<int> idx(k);
        iota(idx.begin(), idx.end(), 0);
        while(true) {
            vector<int> all = orig;
            for(int i = 0; i < k; i++){
                all.push_back(cand[idx[i]]);
            }
            sort(all.begin(), all.end());
            if(has_good_triple(all)){
                cout << k << "\n";
                return 0;
            }
            int i;
            for(i = k-1; i >= 0; i--){
                if(idx[i] < (int)cand.size() - (k - i)){
                    idx[i]++;
                    for(int j = i+1; j < k; j++){
                        idx[j] = idx[j-1] + 1;
                    }
                    break;
                }
            }
            if(i < 0) break;  
        }
    }
    return 0;
}
