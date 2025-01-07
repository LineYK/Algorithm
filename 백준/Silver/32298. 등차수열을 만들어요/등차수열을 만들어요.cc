#include <bits/stdc++.h>
using namespace std;

// 소수 판별 함수
bool isPrime(int n) {
    if (n < 2) return false;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 주어진 시작점에서 등차수열 생성 시도
vector<int> tryMakeSequence(int start, int n, int diff) {
    vector<int> sequence;
    int current = start;
    
    while (sequence.size() < n) {
        if (current > 2000000 || isPrime(current)) {
            return vector<int>();  // 빈 벡터 반환하여 실패 표시
        }
        sequence.push_back(current);
        current += diff;
    }
    
    return sequence;
}

// 결과 출력 함수
void printSequence(const vector<int>& sequence) {
    for (int num : sequence) {
        cout << num << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    // 가능한 시작점마다 시도
    for (int start = 1; start <= 2000000; start++) {
        vector<int> result = tryMakeSequence(start, N, M);
        
        if (!result.empty()) {
            printSequence(result);
            return 0;
        }
    }
    
    cout << -1;  // 해를 찾지 못한 경우
    return 0;
}