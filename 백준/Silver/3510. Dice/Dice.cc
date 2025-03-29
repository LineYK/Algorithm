/*
주사위 
 
시간 제한 메모리 제한
2초 512MB	

문제
페다고르는 다른 것들과 함께 탁상용 롤플레잉 게임을 좋아합니다. 그는 방금 새로운 게임을 발견했고 친구들과 함께 플레이하고 싶어합니다. 안타깝게도 이 게임에는 매우 특이한 주사위가 필요하기 때문에 지금 당장 친구들에게 전화를 걸 수 없습니다. 게임 설명에 따르면 주사위는 n 개가 있어야 하고, 주사위 하나는 인공지능 얼굴이 있어야 한다고 나와 있습니다. 각 주사위의 얼굴이 똑같이 떨어지도록 모양을 만들어야 합니다.

게임 설명서에 따르면 1부터 m까지의 숫자, 즉 m = ∑ai(1 ≤ i ≤ n)가 주사위의 면에 적혀 있어야 하며, 각 간격의 숫자는 정확히 한 번만 사용해야 합니다. 숫자 배열은 모든 주사위를 동시에 던지면 해당 실험에서 총 값의 수학적 기대치 E가 최대가 되도록 선택해야 합니다.

매뉴얼에 따르면 마이아르만이 숫자를 적절하게 배열 할 수있는 충분한 지혜를 가지고 있다고 말합니다 (따라서 유일한 선택은 133 달러에 주사위를 구입하는 것입니다. 텔레파시는 현재 상당히 비쌉니다). 하지만 적절한 배열을 하는 더 간단한 방법이 있을까요?

입력
입력 파일의 첫 번째 줄에는 단일 정수 n(1 ≤ n ≤ 1000)이 들어 있습니다. 다음 줄에는 n개의 정수 a1, a2 ..., an(1 ≤ ai ≤ 100)이 포함됩니다.

출력
출력 파일의 첫 줄에는 소수점 이하 5자리까지 정확한 부동소수점 숫자 최대 기대치 E가 포함되어야 합니다.

다음 n 줄에는 숫자 배열이 포함되어야 합니다: i번째 줄에는 i번째 주사위의 면에 기록할 숫자, 즉 ai 정수가 포함되어야 합니다.

예제 입력 1 
2
1 4
예제 출력 1 
7.50000
5
1 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;

struct Die {
    int faces;
    int index;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<Die> dice(n);
    vector<int> a(n);
    int totalFaces = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dice[i] = {a[i], i};
        totalFaces += a[i];
    }
    
    sort(dice.begin(), dice.end(), [](const Die &d1, const Die &d2){
        return d1.faces < d2.faces;
    });
    
    vector<vector<int>> assignment(n);
    
    int num = totalFaces;
    for(auto &d : dice) {
        for(int i = 0; i < d.faces; i++){
            assignment[d.index].push_back(num--);
        }
        sort(assignment[d.index].begin(), assignment[d.index].end());
    }
    
    double E = 0;
    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(auto num : assignment[i]){
            sum += num;
        }
        E += (double) sum / a[i];
    }
    
    cout << fixed << setprecision(5) << E << "\n";
    for(int i = 0; i < n; i++){
        for(auto num : assignment[i]){
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
