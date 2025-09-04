#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string X;
    if(!(cin >> X)) return 0;
    int n = X.size();
    if(n < 3) { // 제약상 n>=3 이지만 안전히 처리
        cout << "NON ALPSOO\n";
        return 0;
    }

    vector<int> diff;
    diff.reserve(n-1);
    for(int i=0;i<n-1;i++){
        int a = X[i]-'0';
        int b = X[i+1]-'0';
        int d = b - a;
        if(d == 0){
            cout << "NON ALPSOO\n";
            return 0;
        }
        diff.push_back(d);
    }

    // 첫 diff는 양수여야 하고 마지막 diff는 음수여야 함
    if(diff.front() <= 0 || diff.back() >= 0){
        cout << "NON ALPSOO\n";
        return 0;
    }

    // 각 단조 구간에서 차이값이 모두 동일한지 검사
    int curSign = (diff[0] > 0) ? 1 : -1;
    int curStep = diff[0]; // 실제 부호 포함한 차이값
    for(size_t i=1;i<diff.size();++i){
        int d = diff[i];
        int s = (d > 0) ? 1 : -1;
        if(s == curSign){
            // 같은 단조 구간 안: 차이값(증가량/감소량)이 같아야 함
            if(d != curStep){
                cout << "NON ALPSOO\n";
                return 0;
            }
        } else {
            // 단조 구간이 바뀌었음 -> 새 구간 시작
            curSign = s;
            curStep = d;
        }
    }

    cout << "ALPSOO\n";
    return 0;
}