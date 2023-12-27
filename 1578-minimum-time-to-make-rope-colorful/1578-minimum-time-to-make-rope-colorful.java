/*
1578. 밧줄을 다채롭게 만드는 데 걸리는 최소 시간

앨리스는 밧줄에 n개의 풍선을 묶어 놓았습니다. 색[i]는 째 풍선의 색인 0 인덱스의 문자열 색이 주어집니다.

앨리스는 밧줄의 색이 화려하기를 원합니다. 앨리스는 두 개의 연속된 풍선이 같은 색이 되는 것을 원하지 않으므로 밥에게 도움을 요청합니다. 밥은 밧줄에서 풍선 몇 개를 떼어내어 알록달록한 색으로 만들 수 있습니다. 인덱스가 0인 정수 배열 neededTime이 주어지며, 여기서 neededTime[i]는 밥이 밧줄에서 째 풍선을 제거하는 데 필요한 시간(초)입니다.

밥이 밧줄을 색칠하는 데 필요한 최소 시간을 반환합니다.

 
예제 1:
입력: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
설명: 위 이미지에서 'a'는 파란색, 'b'는 빨간색, 'c'는 녹색입니다.
Bob은 인덱스 2에서 파란색 풍선을 제거할 수 있습니다. 이 작업은 3초가 걸립니다.
더 이상 같은 색의 풍선이 두 개 연속으로 존재하지 않습니다. 총 시간 = 3입니다.

예제 2:
입력: colors = "abc", neededTime = [1,2,3]
Output: 0
설명: 밧줄은 이미 알록달록합니다. 밥은 밧줄에서 풍선을 제거할 필요가 없습니다.

예제 3:
입력: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
설명: 밥이 풍선을 제거합니다: Bob은 인덱스 0과 4에 있는 풍선을 제거합니다. 각 풍선을 제거하는 데 1초가 걸립니다.
더 이상 같은 색의 풍선이 두 개 연속으로 존재하지 않습니다. 총 시간 = 1 + 1 = 2입니다.
 
제약 조건:
n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors에는 영문 소문자만 포함됩니다.
*/

class Solution {
    public int minCost(String s, int[] cost) {
        int n = s.length();
        int result = 0;
        for (int i=1; i<n; i++) {
            if (s.charAt(i) == s.charAt(i-1)) {
                result = result + Math.min(cost[i], cost[i-1]);
                cost[i] = Math.max(cost[i], cost[i-1]);
            }
        }
        return result;
    }
}