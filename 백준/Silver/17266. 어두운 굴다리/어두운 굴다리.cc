/*
어두운 굴다리
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	9719	3790	2976	38.400%
문제
인하대학교 후문 뒤쪽에는 어두운 굴다리가 있다. 겁쟁이 상빈이는 길이 조금이라도 어둡다면 가지 않는다. 따라서 굴다리로 가면 최단거리로 집까지 갈수 있지만, 굴다리는 어둡기 때문에 빙빙 돌아서 집으로 간다. 안타깝게 여긴 인식이는 굴다리 모든 길 0~N을 밝히게 가로등을 설치해 달라고 인천광역시에 민원을 넣었다. 인천광역시에서 가로등을 설치할 개수 M과 각 가로등의 위치 x들의 결정을 끝냈다. 그리고 각 가로등은 높이만큼 주위를 비출 수 있다. 하지만 갑자기 예산이 부족해진 인천광역시는 가로등의 높이가 높을수록 가격이 비싸지기 때문에 최소한의 높이로 굴다리 모든 길 0~N을 밝히고자 한다. 최소한의 예산이 들 높이를 구하자. 단 가로등은 모두 높이가 같아야 하고, 정수이다.

다음 그림을 보자.



가로등의 높이가 H라면 왼쪽으로 H, 오른쪽으로 H만큼 주위를 비춘다.

다음 그림은 예제1에 대한 설명이다.



가로등의 높이가 1일 경우 0~1사이의 길이 어둡기 때문에 상빈이는 지나가지 못한다.

아래 그림처럼 높이가 2일 경우 0~5의 모든 길이 밝기 때문에 상빈이는 지나갈 수 있다.



입력
첫 번째 줄에 굴다리의 길이 N 이 주어진다. (1 ≤ N ≤ 100,000)

두 번째 줄에 가로등의 개수 M 이 주어진다. (1 ≤ M ≤ N)

다음 줄에 M 개의 설치할 수 있는 가로등의 위치 x 가 주어진다. (0 ≤ x ≤ N)

가로등의 위치 x는 오름차순으로 입력받으며 가로등의 위치는 중복되지 않으며, 정수이다.

출력
굴다리의 길이 N을 모두 비추기 위한 가로등의 최소 높이를 출력한다.

예제 입력 1 
5
2
2 4
예제 출력 1 
2
예제 입력 2 
3
1
0
예제 출력 2 
3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int prev(0), max(0), temp(0);

    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (i == 0) {
            max = (max < temp - prev) ? temp - prev : max;
        } else {
            max = (max < ceil(double(temp - prev) / 2)) ? ceil(double(temp - prev) / 2) : max;
        }
        prev = temp;
    }
    max = (max < N - prev) ? N - prev : max;
    cout << max;
    
	return 0;
}