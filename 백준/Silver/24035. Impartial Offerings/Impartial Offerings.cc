/*
공정한 제공
 
시간 제한 메모리 제한
10초 (추가 시간 없음) 1024MB

문제
아로하는 동물을 무척 좋아해서 여가 시간에 사랑하는 사람들의 반려동물을 돌보는 데 시간을 보냅니다. 그녀는 간식을 주는 것을 좋아하지만 공정한 방법으로 간식을 주고 싶어 합니다.

아로하는 같은 크기의 반려동물은 같은 양의 간식을 주고, 큰 반려동물은 작은 반려동물보다 더 많은 간식을 주는 것이 합리적이라고 생각했습니다. 예를 들어 10, 20, 10, 25 사이즈의 반려동물 4마리를 키우는 경우 10 사이즈의 반려동물에게는 2개의 간식을, 20 사이즈의 반려동물에게는 3개의 간식을, 25 사이즈의 반려동물에게는 5개의 간식을 제공할 수 있습니다. 이렇게 하려면 총 2+3+2+5=12개의 간식을 구매해야 합니다. 그러나 아로하는 4마리의 애완동물에게 모두 간식을 줄 수 있으며, 10사이즈 애완동물에게 1개, 20사이즈 애완동물에게 2개, 25사이즈 애완동물에게 3개씩 총 7개의 간식을 제공함으로써 자신의 규칙을 준수할 수 있습니다.

아로하가 다음 반려동물의 날을 계획하도록 도와주세요. 아로하와 함께할 모든 반려동물의 크기가 주어졌을 때, 공평성 규칙을 준수하면서 모든 반려동물에게 하나 이상의 간식을 제공하기 위해 구입해야 하는 최소 간식 개수를 계산하세요.

입력
입력의 첫 줄에는 테스트 케이스의 개수인 T를 입력하고, 그 뒤에 테스트 케이스가 이어집니다. 각 테스트 케이스는 두 줄로 구성됩니다. 테스트 케이스의 첫 번째 줄에는 아로하가 다음 펫 데이에 키울 펫의 수인 단일 정수 N이 들어 있습니다. 테스트 케이스의 두 번째 줄에는 각 펫의 크기를 나타내는 정수 S_1,S_2,\cdots,S_N이 포함됩니다.

출력
각 테스트 케이스에 대해 케이스 #x: y가 포함된 한 줄을 출력합니다. 여기서 x는 테스트 케이스 번호(1부터 시작)이고 y는 공정성 규칙을 준수하면서 모든 애완동물에게 적어도 한 개 이상의 간식을 제공하기 위해 구입해야 하는 최소 간식 개수입니다.

제한
 1≤T≤100.
 1≤S_i≤100, for all i.
Test Set 1 (6점)
 2≤N≤5.
Test Set 2 (10점)
 2≤N≤100.
예제 입력 1 
3
4
10 20 10 25
5
7 7 7 7 7
2
100 1
예제 출력 1 
Case #1: 7
Case #2: 5
Case #3: 3
힌트
Sample Case #1 is the case explained above.

In Sample Case #2, all pets are of the same size, so Aroha must offer them all the same amount of treats. The minimum total is attained by offering each pet a single treat.

In Sample Case #3, both pets are of different size so they need a different amount of treats each. Buying less than 2 treats is not enough to give treats to both pets. Buying 2 treats and making sure both pets get something would force Aroha to give both pets the same amount, despite them having different size. Using 3 treats Aroha can give 11 to the small pet and 2 to the big pet and thus comply with all her rules.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        
        vector<int> sizes(N);
        for (int i = 0; i < N; i++) {
            cin >> sizes[i];
        }
        
        vector<pair<int, int>> pets;
        for (int i = 0; i < N; i++) {
            pets.push_back({sizes[i], i});
        }
        
        sort(pets.begin(), pets.end());
        
        vector<int> treats(N, 0);
        
        treats[pets[0].second] = 1;
        
        int currentSize = pets[0].first;
        int currentTreats = 1;
        
        for (int i = 1; i < N; i++) {
            if (pets[i].first > currentSize) {
                currentSize = pets[i].first;
                currentTreats++;
            }
            treats[pets[i].second] = currentTreats;
        }
        
        int totalTreats = 0;
        for (int i = 0; i < N; i++) {
            totalTreats += treats[i];
        }
        
        cout << "Case #" << tc << ": " << totalTreats << '\n';
    }
    
    return 0;
}